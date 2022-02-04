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
/*
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
*/

// PROBLEM 1065
/*
bool checkNum(int num)
{
	std::string numStr = std::to_string(num);
	if (numStr.size() == 1){ return true; }
	else
	{
		int distance = numStr[0] - numStr[1];
		for (int idx = 1; idx < numStr.size() - 1; idx++){ if (numStr[idx] - numStr[idx + 1] != distance) { return false; } }
	}
	return true;
}

void Problem_1065()
{
	int N, result = 0;
	std::cin >> N;
	for (int num = 1; num <= N; num++){ if (checkNum(num)) { result++; } }
	std::cout << result;
}
*/

// PROBLEM 1712
/*
void Problem_1712()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	if (b >= c){ std::cout << -1; }
	else{ std::cout << (a / (c - b)) + 1; }
}
*/

// PROBLEM 1193
/*
void Problem_1193()
{
	int x;
	std::cin >> x;
	int arrCount = 0, arrNum, distance;
	for (int count = 1; count < 100000; count++)
	{
		if ((arrCount += count) >= x)
		{
			distance = x - (arrCount - count);
			arrNum = count;
			break;
		}
	}
	int numerator;
	int denominator;
	if (arrNum % 2)
	{
		numerator = arrNum;
		denominator = 1;
		while (--distance > 0)
		{
			numerator--;
			denominator++;
		}
	}
	else
	{
		numerator = 1;
		denominator = arrNum;
		while (--distance > 0)
		{
			numerator++;
			denominator--;
		}
	}

	std::cout << numerator << "/" << denominator;
}
*/

// PROBLEM 10250
/*
void Problem_10250()
{
	int T, inputBuffer[3];
	std::cin >> T;
	std::string outputStr;
	while (T-- > 0)
	{
		std::cin >> inputBuffer[0] >> inputBuffer[1] >> inputBuffer[2];
		int div = inputBuffer[2] / inputBuffer[0];
		int mod = inputBuffer[2] % inputBuffer[0];
		if(mod == 0) { outputStr += std::to_string((inputBuffer[0] * 100) + div) + '\n'; }
		else { outputStr += std::to_string((mod * 100) + div + 1) + '\n'; }
	}

	std::cout << outputStr;
}
*/

// PROBLEM 2775
/*
struct HashFunc
{
	size_t operator()(const std::pair<int, int>& obj) const
	{
		return obj.first * 100 + obj.second;
	}
};

std::unordered_map<std::pair<int, int>, int, HashFunc> map
{
	{{0, 1}, 1}, {{0, 2}, 2}, {{0, 3}, 3}, {{0, 4}, 4}, {{0, 5}, 5}, {{0, 6}, 6}, {{0, 7}, 7}, {{0, 8}, 8}, {{0, 9}, 9}, {{0, 10}, 10},
	{{0, 11}, 11}, {{0, 12}, 12}, {{0, 13}, 13}, {{0, 14}, 14}
};

int getNum(std::pair<int, int> data)
{
	std::unordered_map<std::pair<int, int>, int, HashFunc>::iterator itr;
	if ((itr = map.find(data)) != map.end()){ return (*itr).second; }
	
	int sum = 0;
	for (int num = data.second; num > 0; num--)
	{
		sum += getNum(std::make_pair(data.first - 1, num));
	}

	map[data] = sum;
	return sum;
}

void Problem_2775()
{
	int T, inputs[2];
	std::cin >> T;
	std::string outputStr;
	while (T-- > 0)
	{
		std::cin >> inputs[0] >> inputs[1];
		outputStr+= std::to_string(getNum(std::make_pair(inputs[0], inputs[1]))) + '\n';
	}

	std::cout << outputStr;
}
*/

// PRBOLEM 10757
/*
void Problem_10757()
{
	std::string a, b, result;
	std::cin >> a >> b;
	for (int idx = 0; idx < a.size() / 2; idx++) { std::swap(a[idx], a[a.size() - idx - 1]); }
	for (int idx = 0; idx < b.size() / 2; idx++) { std::swap(b[idx], b[b.size() - idx - 1]); }
	int max = a.size() > b.size() ? a.size() : b.size();
	bool over = false; int temp;
	for (int idx = 0; idx < max; idx++)
	{
		if (a.size() < max) { a += '0'; }
		if (b.size() < max) { b += '0'; }
		if (result.size() < idx + 1) { result += '0'; }
		over = false;
		temp = a[idx] + b[idx] + result[idx] - (3 * '0');
		if (temp >= 10) { result += '1'; }
		result[idx] = (temp % 10) + '0';
	}
	for (int idx = 0; idx < result.size() / 2; idx++) { std::swap(result[idx], result[result.size() - idx - 1]); }
	std::cout << result;
}
*/

// PROBLEM 1011

void Problem_1011()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string outputStr;
	int T, inputs[2], distance, currentMov, result;
	long long calcMov;
	std::cin >> T;
	while (T-- > 0)
	{
		std::cin >> inputs[0] >> inputs[1];
		distance = inputs[1] - inputs[0];
		currentMov = result = 0;
		
		while (distance > 0)
		{
			if ((calcMov = ((long long)(currentMov + 1 + 1) * (currentMov + 1)) / 2) <= distance)
			{
				distance -= ++currentMov;
			}
			else if ((calcMov = ((long long)(currentMov + 1) * (currentMov)) / 2) <= distance)
			{
				distance -= currentMov;
			}
			else
			{
				distance -= --currentMov;
			}
			result++;
		}
		
		outputStr += std::to_string(result) + '\n';
	}
	std::cout << outputStr;
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
	//Problem_4673();
	//Problem_1065();
	//Problem_1712();
	//Problem_1193();
	//Problem_10250();
	//Problem_2775();
	//Problem_10757();
	Problem_1011();
}