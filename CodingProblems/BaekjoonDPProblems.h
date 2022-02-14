#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

// PROBLEM 2839
/*
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
*/

// PROBLEM 9184
/*
struct Data 
{ 
	Data() = default;
	Data(int a, int b, int c) : mA{ a }, mB{ b }, mC{ c }{}
	int mA, mB, mC;

	std::size_t operator()(const Data& data) const noexcept
	{
		return (data.mA + 100) * 1000000 + (data.mB + 100) * 10000 + (data.mC + 100);
	}

	bool operator==(const Data& other) const noexcept
	{
		return this->mA == other.mA && this->mB == other.mB && this->mC == other.mC;
	}
};

std::unordered_map <Data, long long, Data> lookupTable;

long long proc(int a, int b, int c)
{
	Data temp = Data(a, b, c);
	if (lookupTable.find(temp) != lookupTable.end()) { return lookupTable[temp]; }
	if (a <= 0 || b <= 0 || c <= 0) { return (lookupTable[temp] = 1); }
	if (a > 20 || b > 20 || c > 20) { return (lookupTable[temp] = proc(20, 20, 20)); }
	if (a < b && b < c) { return (lookupTable[temp] = proc(a, b, c - 1) + proc(a, b - 1, c - 1) - proc(a, b - 1, c)); }
	return (lookupTable[temp] = proc(a - 1, b, c) + proc(a - 1, b - 1, c) + proc(a - 1, b, c - 1) - proc(a - 1, b - 1, c - 1));
}

void Problem_9184()
{
	std::string outputStr;
	int inputs[3];
	while (true)
	{
		std::cin >> inputs[0] >> inputs[1] >> inputs[2];
		if (inputs[0] == -1 && inputs[1] == -1 && inputs[2] == -1)
		{
			break;
		}
		outputStr += "w(" + std::to_string(inputs[0]) + ", "
			+ std::to_string(inputs[1]) + ", "
			+ std::to_string(inputs[2]) + ")"
			+ " = "
			+ std::to_string(proc(inputs[0], inputs[1], inputs[2])) + '\n';
	}
	std::cout << outputStr;
}
*/

// PROBLEM 1904
/*
void Problem_1904()
{
	int N, buffer[3]{1, 1, 1}, currentIdx = 0;
	std::cin >> N;
	for (int num = 1; num < N; num++)
	{
		switch (currentIdx)
		{
		case 0:
			buffer[0] = (buffer[1] + buffer[2]) % 15746;
			break;
		case 1:
			buffer[1] = (buffer[0] + buffer[2]) % 15746;
			break;
		case 2:
			buffer[2] = (buffer[1] + buffer[0]) % 15746;
			break;
		default:
			break;
		}
		if (num == N - 1) { break; }
		if (++currentIdx > 2) { currentIdx = 0; }
	}

	std::cout << buffer[currentIdx];
}
*/

// PRBOELM 9461

long long getNum(long long* arr, int idx)
{
	int prevIdx = idx - 1;
	if (prevIdx < 0) { prevIdx = 4; }
	return arr[idx] + arr[prevIdx];
}

void Problem_9461()
{
	std::string outputStr;
	long long data[5]{ 1, 1, 1, 2, 2 };
	int currIdx = 0;
	int T, N;
	std::cin >> T;
	while (T-- > 0)
	{
		std::cin >> N;
		data[0] = 1; data[1] = 1; data[2] = 1; data[3] = 2; data[4] = 2;
		currIdx = 0;
		if (N <= 5) { outputStr += std::to_string(data[N - 1]) + '\n'; }
		else
		{
			N -= 5;
			for (int count = 0; count < N; count++)
			{
				data[currIdx] = getNum(data, currIdx);
				if (count == N - 1) { break; }
				if (++currIdx > 4) { currIdx = 0; }
			}
			outputStr += std::to_string(data[currIdx]) + '\n';
		}
	}
	std::cout << outputStr;
	
}

void ExecuteDpProblems()
{
	//Problem_2839();
	//Problem_9184();
	//Problem_1904();
	Problem_9461();
}