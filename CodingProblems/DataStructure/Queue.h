#pragma once

#include<queue>
#include<utility>

// PROBLEM 2075
int table_2075[1501][1501];
int currentIdxes[1501];

struct comp_2075
{
	bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
	{
		return lhs.first < rhs.first;
	}
};

void Problem_2075()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	for (int outerIdx = 0; outerIdx < N; outerIdx++)
	{
		currentIdxes[outerIdx] = N - 1;
		for (int innerIdx = 0; innerIdx < N; innerIdx++)
		{
			std::cin >> table_2075[outerIdx][innerIdx];
		}
	}

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp_2075> searchLine;
	for (int tableIdx = 0; tableIdx < N; tableIdx++)
	{
		searchLine.emplace(std::make_pair(table_2075[N - 1][tableIdx], tableIdx));
	}

	N--;
	while (N-- >0)
	{
		currentIdxes[searchLine.top().second]--;
		searchLine.emplace(std::make_pair(table_2075[currentIdxes[searchLine.top().second]][searchLine.top().second], searchLine.top().second));
		searchLine.pop();
	}

	std::cout << searchLine.top().first << '\n';
}

void ExecuteQueue()
{
	Problem_2075();
}