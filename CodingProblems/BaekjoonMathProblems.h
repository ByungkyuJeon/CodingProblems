#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <unordered_map>
#include <queue>
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
/*
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
*/

// PROBLEM 2581
/*
void Problem_2581()
{
	int m, n, squrtNum, min = 10001; 
	long long sum = 0;
	std::cin >> m >> n;
	bool checker;
	if (m == 1) { m = 2; }
	for (int num = m; num <= n; num++)
	{
		squrtNum = sqrt(num);
		checker = true;
		for (int check = 2; check <= squrtNum; check++)
		{
			if (num % check == 0) { checker = false; break; }
		}
		if (checker) { if (num < min) { min = num; } sum += num; }
	}

	if (sum == 0) { std::cout << -1; }
	else { std::cout << sum << '\n' << min; }
}
*/

// PROBLEM 11653
/*
void Problem_11653()
{
	int N;
	std::cin >> N;
	if (N == 1) { return; }
	else
	{
		int sqrtNum = sqrt(N);
		std::string outputStr;
		for (int num = 2; num <= sqrtNum; num++)
		{
			if (N % num == 0)
			{
				N /= num;
				sqrtNum = sqrt(N);
				outputStr += std::to_string(num) + '\n';
				num--;
			}
		}

		std::cout << outputStr << N;
	}
}
*/

// PROBLEM 1929
/*
void Problem_1929_Simple()
{
	int m, n, squrtNum;
	std::cin >> m >> n;
	bool checker;
	std::string outputStr;
	if (m == 1) { m = 2; }
	for (int num = m; num <= n; num++)
	{
		squrtNum = sqrt(num);
		checker = true;
		for (int check = 2; check <= squrtNum; check++)
		{
			if (num % check == 0) { checker = false; break; }
		}
		if (checker) { outputStr += std::to_string(num) + '\n'; }
	}

	std::cout << outputStr;
}

int primesUnder1000[168] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997 };

void Problem_1929()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int m, n, squrtNum, temp;
	std::cin >> m >> n;
	bool checker;
	int count = 0;
	std::string outputStr;
	if (m == 1) { m = 2; }
	if (m == n) { std::cout << n; return; }
	std::vector<int> result(n - m + 1);
	for (int idx = 0; idx < result.size(); idx++) { result[idx] = m + idx; }
	squrtNum = sqrt(n);
	for (int pIdx = 0; pIdx < 168; pIdx++)
	{
		temp = primesUnder1000[pIdx];
		if (temp > squrtNum) { break; }
		result.erase(std::remove_if(result.begin(), result.end(), [=](int n) {return n != temp && n % temp == 0; }), result.end());
	}
	for (int idx = 0; idx < result.size(); idx++) { outputStr += std::to_string(result[idx]) + '\n'; }

	std::cout << outputStr;
}
*/

// PROBLEM 4948
/*
int primesUnder496[94] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491 };

void Problem_4948()
{
	int n, squrtNum;
	bool checker;
	int count = 0;
	std::string outputStr;

	while (true)
	{
		std::cin >> n;
		if (n == 0) { break; }
		count = 0;
		for (int num = n + 1; num <= 2 * n; num++)
		{
			squrtNum = sqrt(num);
			checker = true;
			for (int pIdx = 0; pIdx < 94; pIdx++)
			{
				if (primesUnder496[pIdx] > squrtNum) { break; }
				if (num % primesUnder496[pIdx] == 0) { checker = false; break; }
			}
			if (checker) { count++; }
		}

		outputStr += std::to_string(count) + '\n';
	}

	std::cout << outputStr;
}
*/

// PROBLEM 9020
/*
int primesUnder97[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

void Problem_9020()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string outputStr;
	int T, N, end, count, squrtNum;
	bool checker;
	std::cin >> T;
	while (T-- > 0)
	{
		std::cin >> N;
		end = N / 2;
		for (int num = end; num >= 2; num--)
		{
			squrtNum = sqrt(num);
			checker = true;
			for (int pIdx = 0; pIdx < 25; pIdx++)
			{
				if (primesUnder97[pIdx] > squrtNum) { break; }
				if (num % primesUnder97[pIdx] == 0) { checker = false; break; }
			}
			if (checker) 
			{ 
				squrtNum = sqrt(N - num);
				checker = true;
				for (int pIdx = 0; pIdx < 25; pIdx++)
				{
					if (primesUnder97[pIdx] > squrtNum) { break; }
					if ((N - num) % primesUnder97[pIdx] == 0) { checker = false; break; }
				}
				if (checker)
				{
					outputStr += std::to_string(num) + " " + std::to_string(N - num) + '\n';
					break;
				}
			}
		}
	}

	std::cout << outputStr;
}
*/

// PROBLEM 1085
/*
void Problem_1085()
{
	int x, y, w, h;
	std::cin >> x >> y >> w >> h;
	std::vector<int> val {x, y, w - x, h - y};
	std::cout << *std::min_element(val.begin(), val.end());
}
*/

// PROBLEM 3009
/*
void Problem_3009()
{
	int input, x, y;
	std::unordered_map<int, int> X, Y;
	for (int count = 0; count < 3; count++)
	{
		std::cin >> input; X[input]++;
		std::cin >> input; Y[input]++;
	}
	for (const auto& elem : X) { if (elem.second % 2 == 1) { x = elem.first; break; } }
	for (const auto& elem : Y) { if (elem.second % 2 == 1) { y = elem.first; break; } }
	std::cout << x << " " << y;
}
*/

// PROBLEM 4153
/*
void Problem_4153()
{
	std::string outputStr;
	std::vector<int> nums(3);
	int max, sum;
	while (true)
	{
		std::cin >> nums[0] >> nums[1] >> nums[2];
		if (nums[0] == 0) { break; }
		sum = 0;
		max = *std::max_element(nums.begin(), nums.end());
		for (const auto elem : nums){ if (elem != max) { sum += pow(elem, 2); } }
		if (pow(max, 2) == sum) { outputStr += "right\n"; }
		else { outputStr += "wrong\n"; }
	}

	std::cout << outputStr;
}
*/

// PROBLEM 1002
/*
void Problem_1022()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string outputStr;
	int T, inputs[6], maxR, minR;
	double distance;
	std::cin >> T;
	while (T-- > 0)
	{
		std::cin >> inputs[0] >> inputs[1] >> inputs[2] >> inputs[3] >> inputs[4] >> inputs[5];
		maxR = inputs[2] > inputs[5] ? inputs[2] : inputs[5];
		minR = inputs[2] < inputs[5] ? inputs[2] : inputs[5];
		distance = sqrt(pow(inputs[0] - inputs[3], 2) + pow(inputs[1] - inputs[4], 2));
		if (distance == 0 && inputs[2] == inputs[5]) { outputStr += "-1\n"; continue; }
		if (distance >= maxR)
		{
			if (distance > inputs[2] + inputs[5]){ outputStr += "0\n"; }
			else if (distance == inputs[2] + inputs[5]){ outputStr += "1\n"; }
			else{ outputStr += "2\n"; }
		}
		else
		{
			if (maxR == distance + minR) { outputStr += "1\n"; }
			else if (maxR < distance + minR) { outputStr += "2\n"; }
			else { outputStr += "0\n"; }
		}
	}

	std::cout << outputStr;
}
*/

// PROBLEM 10872
/*
long long factorial(int num)
{
	if (num == 1 || num == 0) { return 1; }
	return num * factorial(num - 1);
}

void Problem_10872()
{
	int N;
	std::cin >> N;
	std::cout << factorial(N);
}
*/

// PROBLEM 10870, 2747

std::unordered_map<int, long long> map
{
	{0, 0},
	{1, 1}
};

long long fibonacci(int num)
{
	if (map.find(num) != map.end()) { return map[num]; }
	return (map[num] = fibonacci(num - 1) + fibonacci(num - 2));
}

void Problem_10870()
{
	int num;
	std::cin >> num;
	std::cout << fibonacci(num);
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
	//Problem_1011();
	//Problem_2581();
	//Problem_11653();
	//Problem_1929();
	//Problem_4948();
	//Problem_9020();
	//Problem_1085();
	//Problem_3009();
	//Problem_4153();
	//Problem_1022();
	//Problem_10872();
	Problem_10870();
}