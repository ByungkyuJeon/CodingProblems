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

// PROBLEM 2239

char BoardData[9][9];

bool ProcessFunc(const std::vector<std::pair<char, char>>& emptySpotData, int index)
{
	if (emptySpotData.size() <= index)
		return true;

	const std::pair<char, char>& targetSpot = emptySpotData[index];

	int candidatesFlag = 0;
	for (int i = 1; i <= 9; ++i)
		candidatesFlag |= 1 << i;

	for (int i = 0; i < 9; ++i)
	{
		if (BoardData[targetSpot.first][i])
			candidatesFlag &= ~(1 << BoardData[targetSpot.first][i]);

		if (BoardData[i][targetSpot.second])
			candidatesFlag &= ~(1 << BoardData[i][targetSpot.second]);
	}

	int start = targetSpot.first - (targetSpot.first % 3);
	int end = targetSpot.second - (targetSpot.second % 3);

	for (int i = start; i < start + 3; ++i)
	{
		for (int j = end; j < end + 3; ++j)
		{
			if (BoardData[i][j])
				candidatesFlag &= ~(1 << BoardData[i][j]);
		}
	}

	for (int i = 1; i <= 9; ++i)
	{
		if (candidatesFlag & 1 << i)
		{
			BoardData[targetSpot.first][targetSpot.second] = i;
			bool result = ProcessFunc(emptySpotData, index + 1);
			if (result)
				return true;

			BoardData[targetSpot.first][targetSpot.second] = 0;
		}
	}

	return false;
}

void Problem_2239()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string inputStr;
	std::vector<std::pair<char, char>> emptySpots;

	for (int i = 0; i < 9; ++i)
	{
		std::getline(std::cin, inputStr);

		for (int j = 0; j < 9; ++j)
		{
			BoardData[i][j] = inputStr[j] - '0';
			if (!BoardData[i][j])
				emptySpots.emplace_back(std::pair<char, char>(i, j));
		}
	}

	bool result = ProcessFunc(emptySpots, 0);

	if (result == false)
		return;

	std::string outputStr;
	for (int i = 0; i < 9; ++i)
	{
		if(i != 0)
			outputStr += '\n';
		for (int j = 0; j < 9; ++j)
		{
			outputStr += std::to_string(BoardData[i][j]);
		}
	}

	std::cout << outputStr;
}

void Execute_DynamicProgramming()
{
	//Problem_1135();
	//Problem_1003();
	Problem_2239();
}