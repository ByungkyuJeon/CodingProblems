#pragma once

#include<queue>
#include<utility>

// PROBLEM 2075
/*
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
*/

// PROBLEM 18258

void Problem_18258()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::queue<int> dataQueue;
	std::string inputStr, outputStr;
	int N, inputNum;
	std::cin >> N;
	while (N-- > 0)
	{
		std::cin >> inputStr;
		if (inputStr == "push")
		{
			std::cin >> inputNum;
			dataQueue.push(inputNum);
		}
		else if (inputStr == "pop")
		{
			if (dataQueue.empty())
			{
				outputStr += std::to_string(-1) + '\n';
			}
			else
			{
				outputStr += std::to_string(dataQueue.front()) + '\n';
				dataQueue.pop();
			}
		}
		else if (inputStr == "size")
		{
			outputStr += std::to_string(dataQueue.size()) + '\n';
		}
		else if (inputStr == "empty")
		{
			if (dataQueue.empty())
			{
				outputStr += std::to_string(1) + '\n';
			}
			else
			{
				outputStr += std::to_string(0) + '\n';
			}
		}
		else if (inputStr == "front")
		{
			if (dataQueue.empty())
			{
				outputStr += std::to_string(-1) + '\n';
			}
			else
			{
				outputStr += std::to_string(dataQueue.front()) + '\n';
			}
		}
		else if (inputStr == "back")
		{
			if (dataQueue.empty())
			{
				outputStr += std::to_string(-1) + '\n';
			}
			else
			{
				outputStr += std::to_string(dataQueue.back()) + '\n';
			}
		}
	}

	std::cout << outputStr;
}

void ExecuteQueue()
{
	//Problem_2075();
	Problem_18258();
}