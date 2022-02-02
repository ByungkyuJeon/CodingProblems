#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <unordered_map>
#include "TimeChecker.h"

// PROBLEM 8393
/*
void Problem_8393()
{
	int N, result = 0;
	std::cin >> N;

	for (int counter = N; counter > 0; counter--)
	{
		result += counter;
	}

	std::cout << result << std::endl;
}
*/

// PROBLEM 2753
/*
void Problem_2753()
{
	int N;
	bool result = false;
	std::cin >> N;

	if (N % 4 == 0 && (N % 400 == 0 || N % 100 != 0))
	{
		result = true;
	}

	std::cout << static_cast<int>(result) << std::endl;
}
*/

// PROBLEM 4344
/*
void Problem_4344()
{
	int C, N, inputBuffer;
	double result, average;
	std::vector<int> scores;
	std::cin >> C;

	for (int outerCounter = C; outerCounter > 0; outerCounter--)
	{
		scores.clear();
		average = 0;
		result = 0;
		std::cin >> N;
		for (int innerCounter = N; innerCounter > 0; innerCounter--)
		{
			std::cin >> inputBuffer;
			scores.emplace_back(inputBuffer);
		}

		average = static_cast<double>(std::accumulate(scores.begin(), scores.end(), 0)) / static_cast<double>(scores.size());

		for (const auto& elem : scores)
		{
			if (elem > average)
			{
				result++;
			}
		}

		std::cout << std::fixed;
		std::cout.precision(3);
		std::cout << static_cast<double>(result) / static_cast<double>(scores.size()) * 100.0 << "%" << std::endl;
	}
}
*/

// PROBLEM 2908
/*
void Problem_2908()
{
	int inputBuffer;
	std::string strBuffer;
	std::vector<int> nums;

	for (int counter = 0; counter < 2; counter++)
	{
		strBuffer.clear();
		std::cin >> inputBuffer;
		strBuffer.append(std::to_string(inputBuffer));
		std::swap(strBuffer[0], strBuffer[2]);
		nums.emplace_back(std::stoi(strBuffer));
	}

	std::cout << std::max(nums[0], nums[1]) << std::endl;
}
*/

// PROBLEM 1978
/*
void Problem_1978_Trial_1()
{
	int N, inputBuffer;
	int result = 0;
	std::vector<int> nums;

	std::cin >> N;
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		nums.emplace_back(inputBuffer);
	}

	for (const auto& elem : nums)
	{
		if (elem > 1) { result++; }
		for (int checker = 2; checker <= elem / 2; checker++)
		{
			if (elem % checker == 0)
			{
				result--;
				break;
			}
		}
	}

	std::cout << result << std::endl;
}

void Problem_1978_Trial_2()
{
	int N, inputBuffer;
	std::vector<int> nums;
	int result = 0;

	std::cin >> N;
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		nums.emplace_back(inputBuffer);
	}

	for (const auto& elem : nums)
	{
		if (elem > 1) { result++; }
		for (int checker = 2; checker <= static_cast<int>(sqrt(elem)); checker++)
		{
			if (elem % checker == 0)
			{
				result--;
				break;
			}
		}
	}

	std::cout << result << std::endl;
}
*/

// PROBLEM 2922
/*
int Calculate_Baekjoon_2922_MaxRange(int num)
{
	if (num < 2) { return 1; }

	return 6 * (num - 1);
}

int Calculate_Baekjoon_2922_MinRange(std::unordered_map<int, int>& cache, int num)
{
	if (num < 1) { return -1; }
	else if (cache.find(num) != cache.end())
	{
		return cache[num];
	}

	cache.emplace(num, ((num - 2) * 6) + Calculate_Baekjoon_2922_MinRange(cache, num - 1));

	return cache[num];
}

void Problem_2292()
{
	std::unordered_map<int, int> cacheTable
	{
		{1, 1},
		{2, 2}
	};

	int N, minBuffer;
	std::cin >> N;

	double consumedTime = TimeChecker::CheckTime([&] {

		for (int counter = 1; counter < 20; counter++)
		{
			minBuffer = Calculate_Baekjoon_2922_MinRange(cacheTable, counter);
			if (minBuffer <= N && N < minBuffer + Calculate_Baekjoon_2922_MaxRange(counter))
			{
				std::cout << counter << std::endl;
				break;
			}
		}
		});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

void Problem_2292_Tiral_2()
{
	int N;
	std::cin >> N;

	if (N == 1) { std::cout << 1 << std::endl; return; }

	int lowerNum = 2;
	int circleNum = 2;
	while (true)
	{
		if (lowerNum <= N && N < (lowerNum = lowerNum + (6 * (circleNum - 1))))
		{
			std::cout << circleNum << std::endl;
			break;
		}

		circleNum++;
	}
}
*/

// PROBLEM 2869
/*
void Problem_2869()
{
	int A, B, V;
	std::cin >> A >> B >> V;

	int consumedDays = ((V - A) / (A - B));
	V -= consumedDays * (A - B);

	std::cout << V << std::endl;

	while (true)
	{
		consumedDays++;
		if ((V -= A) <= 0)
		{
			break;
		}

		V += B;
	}

	std::cout << consumedDays << std::endl;
}
*/

// PROBLEM 3053
/*
void Problem_3053()
{
	int R;
	std::cin >> R;

	std::cout << std::fixed;
	std::cout.precision(6);
	std::cout << pow(R, 2) * M_PI << '\n' << 2 * pow(R, 2);
}
*/

// PROBLEM 4342
/*
bool process_4342(int bigger, int smaller,  bool turn)
{
	if (bigger % smaller == 0 || bigger - smaller > smaller) { return turn; }

	return process_4342(smaller, bigger - smaller, !turn);
}

void Problem_4342()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int gameNum[2];
	std::string outputStr;

	while (true)
	{
		std::cin >> gameNum[0] >> gameNum[1];
		if (!gameNum[0] && !gameNum[1]) { break; }

		if (gameNum[0] < gameNum[1]) { std::swap(gameNum[0], gameNum[1]); }
		
		if (process_4342(gameNum[0], gameNum[1], 1)) { outputStr += "A wins\n"; }
		else { outputStr += "B wins\n"; }
	}

	std::cout << outputStr;
}
*/

// PROBLEM 1546
/*
void Problem_1546()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, inputBuffer;
	double sum = 0, max = -1;
	std::cin >> N;
	for (int count = 0; count < N; count++)
	{
		std::cin >> inputBuffer;
		sum += inputBuffer;
		if (inputBuffer > max) { max = inputBuffer; }
	}

	std::cout << (sum / max * 100.0) / (double)N;

}
*/

// PROBLEM 4673

bool data[10001];

int getD(int num)
{
	int result = num;
	std::string numStr = std::to_string(num);
	for (int idx = 0; idx < numStr.size(); idx++)
	{
		result += numStr[idx] - '0';
	}
	return result;
}

void Problem_4673()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	int num = 0, D;
	while (num <= 10000) { if ((D = getD(num++)) <= 10000) { data[D] = true; } }
	for (int idx = 0; idx <= 10000; idx++){ if (!data[idx]) { std::cout << idx << '\n'; } }
}

void ExecuteBaekjoonMathProblems()
{
	//Problem_8393();
	//Problem_2753();
	//Problem_4344();
	//Problem_2908();
	//Problem_1978();
	//Problem_2922();
	//Problem_2869();
	//Problem_3053();
	//Problem_4342();
	//Problem_1546();
	Problem_4673();
}