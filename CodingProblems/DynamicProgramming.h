#pragma once
#include <unordered_map>

// PROBLEM 1135
/*
int process(std::vector<int>* arr, int inIdx, int callCount)
{
	int result = 0;
	std::vector<int> sizes;
	std::priority_queue<int> calls;

	for(int idx = 0; idx < arr[inIdx].size(); idx++)
	{
		sizes.emplace_back(process(arr, arr[inIdx][idx], callCount));
	}
	std::sort(sizes.begin(), sizes.end(), std::greater<int>());
	for (int idx = 0; idx < sizes.size(); idx++)
	{
		calls.emplace(sizes[idx] + idx + 1);
	}
	
	if (calls.empty())
	{
		return callCount;
	}
	return calls.top() > arr[inIdx].size() ? calls.top() : arr[inIdx].size();
}

void Problem_1135()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::vector<int> data[50];
	std::vector<std::pair<int, int>> data_sizes[50];

	int N, inputBuffer;
	std::cin >> N;

	std::cin >> inputBuffer;
	for (int idx = 1; idx < N; idx++)
	{
		std::cin >> inputBuffer;
		data[inputBuffer].emplace_back(idx);
	}

	std::cout << process(data, 0, 0);
}
*/

// PROBLEM 1003
/*
std::unordered_map<int, std::pair<int, int>> lookupTable
{
	{0, {1, 0}},
	{1, {0, 1}},
	{2, {1, 1}},
	{3, {1, 2}},
};

std::pair<int, int> operator+(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
{
	return std::make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

std::pair<int, int> fibonacci(int num)
{
	if (lookupTable.find(num) != lookupTable.end())
	{
		return lookupTable[num];
	}


	lookupTable[num] = fibonacci(num - 1) + fibonacci(num - 2);
	return lookupTable[num];
}

void Problem_1003()
{
	std::pair<int, int > result;
	std::string resultStr;
	int T, N;
	std::cin >> T;
	while (T-- > 0)
	{
		std::cin >> N;
		result = fibonacci(N);
		resultStr += std::to_string(result.first) + " " + std::to_string(result.second) + '\n';
	}

	std::cout << resultStr;
}
*/

void Execute_DynamicProgramming()
{
	//Problem_1135();
	//Problem_1003();
}