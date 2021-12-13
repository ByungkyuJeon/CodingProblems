#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>


int DP_2839(std::unordered_map<int, int>& inLookupTable, int inNum)
{
	if (inNum == 0) { return 0; }
	else if (inNum < 0) { return INT_MAX; }

	auto itr = inLookupTable.find(inNum);
	if (itr != inLookupTable.end())
	{
		return itr->second;
	}

	if ((inLookupTable[inNum] = std::min(DP_2839(inLookupTable, inNum - 3), DP_2839(inLookupTable, inNum - 5))) != INT_MAX)
	{
		inLookupTable[inNum]++;
	}

	return inLookupTable[inNum];
}

void Problem_2839()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, result;
	std::cin >> N;
	std::unordered_map<int, int> lookupTable
	{
		{1, INT_MAX},
		{2, INT_MAX},
		{3, 1},
		{4, INT_MAX},
		{5, 1}
	};

	if ((result = DP_2839(lookupTable, N)) == INT_MAX)
	{
		std::cout << -1;
	}
	else { std::cout << result; }
}

void ExecuteDpProblems()
{
	Problem_2839();
}