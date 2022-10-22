#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include <map>
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

void Problem_1929_ver1()
{
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

// PROBLEM 1929 ver.2

std::vector<int> primeRange(int start, int end)
{
	std::vector<bool> isPrime(end + 1, true);
	int sqrtNum = std::sqrt(end);
	isPrime[1] = false;
	int s = 4;
	int f = 3;
	while (f <= sqrtNum || s <= end)
	{
		if(s <= end && isPrime[s]){ isPrime[s] = false; }
		if (f <= sqrtNum && isPrime[f])
		{
			for (int j = f * f; j <= end; j += f * 2) { isPrime[j] = false; }
		}
		s += 2;
		f += 2;
	}
	std::vector<int> res;
	for (int num = start; num <= end; num++)
	{
		if (isPrime[num]) { res.emplace_back(num); }
	}

	return res;
}

void Problem_1929()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int m, n;
	std::cin >> m >> n;
	std::vector<int> result = primeRange(m, n);

	std::string outputStr;
	for (int idx = 0; idx < result.size(); idx++) { outputStr += std::to_string(result[idx]) + '\n'; }

	std::cout << outputStr;
}



std::vector<int> Problem_1929_test(int m, int n)
{
	int squrtNum, temp;
	bool checker;
	int count = 0;
	std::string outputStr;
	if (m == 1) { m = 2; }
	std::vector<int> result(n - m + 1);
	for (int idx = 0; idx < result.size(); idx++) { result[idx] = m + idx; }
	squrtNum = sqrt(n);
	for (int pIdx = 0; pIdx < 168; pIdx++)
	{
		temp = primesUnder1000[pIdx];
		if (temp > squrtNum) { break; }
		result.erase(std::remove_if(result.begin(), result.end(), [=](int n) {return n != temp && n % temp == 0; }), result.end());
	}

	return result;
}

void Problem_1929_TEST()
{
	int m, n;
	
	std::srand(std::time(NULL));
	while (true)
	{
		m = 1 + (std::rand() % 100);
		n = m + (std::rand() % 1000);
		std::vector<int> temp = Problem_1929_test(m, n);
		std::vector<int> result = primeRange(m, n);
		if (temp.size() != result.size())
		{
			std::cout << "fail";
			for (int idx = 0; idx < result.size(); idx++)
			{
				if (std::find(temp.begin(), temp.end(), result[idx]) == temp.end())
				{
					std::cout << "fail";
				}
			}
		}
		else
		{
			std::cout << "Pass" << std::endl;
		}
	}
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

// PROBLEM 10870, 2747, 2748
/*
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
*/

// PROBLEM 10826
/*
std::string addStr(std::string& lhs, std::string& rhs)
{
	int digit;
	if (lhs.size() > rhs.size()) { rhs = "0" + rhs; }
	else if (lhs.size() < rhs.size()) { lhs = "0" + lhs; }
	std::string result; result.resize(lhs.size(), '0');
	for (int idx = lhs.size() - 1; idx >= 0; idx--)
	{
		digit = lhs[idx] + rhs[idx] + result[idx] - (3 * '0');
		result[idx] = (digit % 10) + '0';
		if (digit >= 10)
		{
			if (idx != 0) { result[idx - 1]++; }
			else{ result = "1" + result; }
		}
	}
	return result;
}

void Problem_10826()
{
	int num;
	std::cin >> num;
	if (num == 0) { std::cout << 0; }
	else if (num == 1) { std::cout << 1; }
	else
	{
		std::string fibonacci[3]{ "0", "1", "1" };
		int checkIdx = 1;
		for (int idx = 2; idx <= num; idx++)
		{
			if (++checkIdx > 2) { checkIdx = 0; }
			if (checkIdx == 2){ fibonacci[2] = addStr(fibonacci[0], fibonacci[1]); }
			else if (checkIdx == 1){ fibonacci[1] = addStr(fibonacci[0], fibonacci[2]); }
			else{ fibonacci[0] = addStr(fibonacci[1], fibonacci[2]); }
		}
		std::cout << fibonacci[checkIdx];
	}
}
*/

// PROBLEM 9471 : 파사노 주기
/*
void Problem_9471()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string outputStr;
	int T, inputs[2];
	long long temp[2];
	std::cin >> T;
	while (T-- > 0)
	{
		std::cin >> inputs[0] >> inputs[1];
		
		long long fibonacci[3]{ 0, 1, 1 };
		int checkIdx = 1;
		temp[0] = -1;
		for (int num = 2;; num++)
		{
			if (++checkIdx > 2) { checkIdx = 0; }
			if (checkIdx == 2) { fibonacci[2] = (fibonacci[0] + fibonacci[1]) % inputs[1]; }
			else if (checkIdx == 1) { fibonacci[1] = (fibonacci[0] + fibonacci[2]) % inputs[1]; }
			else { fibonacci[0] = (fibonacci[1] + fibonacci[2]) % inputs[1]; }
			temp[1] = fibonacci[checkIdx];
			if (temp[0] == 1 && temp[1] == 1)
			{
				outputStr += std::to_string(inputs[0]) + " " + std::to_string(num - 2) + '\n';
				break;
			}
			temp[0] = temp[1];
		}
	}

	std::cout << outputStr;
}
*/

// PRBOELM 2749 : 피보나치 수 3
/*
void Problem_2749()
{
	long long N;
	std::cin >> N;
	N %= 1500000;

	long long fibonacci[3]{ 0, 1, 1 };
	int checkIdx = 1;
	for (int num = 2; num <= N; num++)
	{
		if (++checkIdx > 2) { checkIdx = 0; }
		if (checkIdx == 2) { fibonacci[2] = (fibonacci[0] + fibonacci[1]) % 1000000; }
		else if (checkIdx == 1) { fibonacci[1] = (fibonacci[0] + fibonacci[2]) % 1000000; }
		else { fibonacci[0] = (fibonacci[1] + fibonacci[2]) % 1000000; }
	}

	std::cout << fibonacci[checkIdx];
}
*/

// PROBLEM 1463 : 1로 만들기
/*
int maxDepth = 1000000;

void operation(int num, int depth)
{
	if (maxDepth < depth) { return; }
	if (num == 1) { if (maxDepth > depth) { maxDepth = depth; } return; }
	if (num % 3 == 0) { operation(num / 3, depth + 1); }
	if (num % 2 == 0) { operation(num >> 1, depth + 1); }
	operation(num - 1, depth + 1);
}

void Problem_1463()
{
	int num;
	std::cin >> num;
	operation(num, 0);
	std::cout << maxDepth;
}
*/

// PRBOELM 2447
//
/*
bool calc(int x, int y)
{
	while (x != 0 && y != 0) { if (x % 3 == 1 && y % 3 == 1) { return true; } x /= 3; y /= 3; }
	return false;
}

void Problem_2447()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string outputStr;
	int N;
	std::cin >> N;
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			if (calc(x, y)) { outputStr += " "; continue; }
			outputStr += "*";
		}
		outputStr += "\n";
	}

	std::cout << outputStr;
}
*/

// PROBLEM 11729 : 하노이 탑 이동 순서
/*
std::stack<int> table[3];
std::vector<std::pair<int, int>> trace;
std::string result;
int N;
int maxDepth = 100000;
bool found = false;

void saveResult()
{
	result.clear();
	result += std::to_string(maxDepth) + "\n";
	for (const auto& elem : trace)
	{
		result += std::to_string(elem.first) + " " + std::to_string(elem.second) + "\n";
	}
}

void oper(int depth)
{
	if (table[0].empty() && table[1].empty()) { if (maxDepth == depth) { saveResult(); found = true; } return; }
	if (found || maxDepth < depth) { return; }
	std::pair<int, int> step;

	for (int lhs = 0; lhs < 2; lhs++)
	{
		for (int rhs = lhs + 1; rhs < 3; rhs++)
		{
			if (trace.size() > 0 && trace[trace.size() - 1].first == rhs + 1 && trace[trace.size() - 1].second == lhs + 1) { continue; }
			if (!table[lhs].empty() && (table[rhs].empty() || table[lhs].top() < table[rhs].top()))
			{
				step.first = lhs + 1; step.second = rhs + 1;
				trace.emplace_back(step);
				table[rhs].emplace(table[lhs].top()); table[lhs].pop();
				oper(depth + 1);
				trace.erase(trace.end() - 1);
				table[lhs].emplace(table[rhs].top()); table[rhs].pop();
			}
			if (found) { return; }
		}
	}

	for (int lhs = 2; lhs > 0; lhs--)
	{
		for (int rhs = lhs - 1; rhs >= 0; rhs--)
		{
			if (trace.size() > 0 && trace[trace.size() - 1].first == rhs + 1 && trace[trace.size() - 1].second == lhs + 1) { continue; }
			if (!table[lhs].empty() && (table[rhs].empty() || table[lhs].top() < table[rhs].top()))
			{
				step.first = lhs + 1; step.second = rhs + 1;
				trace.emplace_back(step);
				table[rhs].emplace(table[lhs].top()); table[lhs].pop();
				oper(depth + 1);
				trace.erase(trace.end() - 1);
				table[lhs].emplace(table[rhs].top()); table[rhs].pop();
			}
			if (found) { return; }
		}
	}
}

void Problem_11729_bruteForce()
{
	std::cin >> N;
	maxDepth = pow(2, N) - 1;
	for (int num = N; num > 0; num--) { table[0].emplace(num); }
	oper(0);
	std::cout << result;
}

int getStart(int num)
{
	int ret = 1;
	while ((num & 1) != 1){ num = num >> 1; ret++; }
	return ret;
}

void Problem_11729()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::unordered_map<int, int> map{ {1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{14,1},{15,1},{16,1},{17,1},{18,1},{19,1},{20,1} };
	int num, temp, start, cirNum, order;
	std::cin >> num;
	order = num % 2;
	int min = pow(2, num) - 1;
	std::string outputStr; outputStr += std::to_string(min) + "\n";
	for (int step = 1; step <= min; step++)
	{
		start = map[(cirNum = getStart(step))];
		outputStr += std::to_string(start) + " ";
		if (cirNum % 2 == order) { if (start == 1) { temp = 3; } else { temp = start - 1; } map[cirNum] = temp; outputStr += std::to_string(temp) + "\n"; }
		else { if (start == 3) { temp = 1; } else { temp = start + 1; } map[cirNum] = temp; outputStr += std::to_string(temp) + "\n"; }
	}
	std::cout << outputStr;
}
*/

// PROBLEM 2798 : 블랙잭
/*
void Problem_2798()
{
	int N, M, inputs[100] = { 0 };
	std::cin >> N >> M;
	int sum = 0, max = 0;

	for(int idx = 0; idx < N; idx++)
	{
		std::cin >> inputs[idx];
	}
	for (int front = 0; front < N - 2; front++)
	{
		for (int middle = front + 1; middle < N - 1; middle++)
		{
			for (int back = middle + 1; back < N; back++)
			{
				sum = inputs[front] + inputs[middle] + inputs[back];
				if (sum <= M && max < sum) { max = sum; }
				if (max == M) { break; }
			}
			if (max == M) { break; }
		}
		if (max == M) { break; }
	}

	std::cout << max;
}
*/

// PROBLEM 2231 : 분해합
/*
void Problem_2231()
{
	int N;
	std::cin >> N;
	std::string numStr = std::to_string(N);
	int start = N - (numStr.size() * 9), sum;
	bool check = false;
	if (start < 0) { start = 0; }
	for (int num = start; num < N; num++)
	{
		sum = num;
		numStr = std::to_string(num);
		for (int idx = numStr.size() - 1; idx >= 0; idx--) { sum += (numStr[idx] - '0'); }
		if (sum == N) { check = true;  break; }
	}
	if(check){ std::cout << numStr; }
	else { std::cout << 0; }
}
*/

// PROBLEM 7568 : 덩치
/*
void Problem_7568()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	struct Human { int weight, height; };
	Human humans[51];

	int N;
	std::cin >> N;
	for (int idx = 0; idx < N; idx++) { std::cin >> humans[idx].weight >> humans[idx].height; }
	std::string outputStr;
	int count;
	for (int outer = 0; outer < N; outer++)
	{
		count = 1;
		for (int inner = 0; inner < N; inner++)
		{
			if (outer == inner) { continue; }
			if (humans[inner].weight > humans[outer].weight && humans[inner].height > humans[outer].height) { count++; }
		}
		outputStr += std::to_string(count) + " ";
	}

	std::cout << outputStr;
}
*/

// PROBLEM 1436
/*
void Problem_1436()
{
	int N;
	std::cin >> N;

	int count = 0;
	int result;
	for (int num = 666; count != N; num++){ if (std::to_string(num).find("666") != std::string::npos) { count++; result = num; } }
	std::cout << result;
}
*/

// PROBLEM 11444 Trial : 피보나치 수 6

/// <summary>
/// 파사노 주기 법칙을 활용해 최적화하는 알고리즘으로 해결해야 한다.
/// 입력값의 크기가 크기 때문에 일반적인 3항 바텀업 알고리즘 또는 탑다운 DP 알고리즘으로는 시간 초과이다.
/// 모듈러 연산자가 1,000,000,007로 고정되어 있기 때문에 파사노 주기는 2,000,000,016이다.
/// 
/// 결과 : 시간초과. 모듈러 연산자가 큰 수의 파사노 주기를 가지고 있어, 파사노 주기로 해결할 수 없는 문제이다.
/// </summary>
/*
void Problem_11444_Trial()
{
	long long input;
	std::cin >> input;
	input %= 2000000016;
	long long nums[3]{0, 1, 1};
	int current = 0;
	if (input < 3) { std::cout << nums[input]; }
	else
	{
		for (int num = 3; num <= input; num++)
		{
			switch (current)
			{
			case 0:
				nums[0] = (nums[1] + nums[2]) % 1000000007;
				break;
			case 1:
				nums[1] = (nums[0] + nums[2]) % 1000000007;
				break;
			case 2:
				nums[2] = (nums[0] + nums[1]) % 1000000007;
				break;
			default:
				break;
			}
			if (num != input && ++current > 2) { current = 0; }
		}

		std::cout << nums[current];
	}
}
*/

// PROBLEM 11444 Final : 피보나치 수 6

/// <summary>
/// 피보나치의 점화식을 행렬의 곱셈을 통해 분할 정복으로 풀이해야 한다.
/// 행렬의 제곱 연산을 이용하면 n 번째 피보나치 행렬을 통해 2n 번째 피보나치 행렬을 빠르게 구할 수 있기 때문이다.
/// </summary>
/*
void mult(long long (*lhs)[2], long long (*rhs)[2])
{
	long long ret[2][2];
	ret[0][0] = (lhs[0][0] * rhs[0][0]) + (lhs[0][1] * rhs[1][0]);
	ret[0][1] = (lhs[0][0] * rhs[0][1]) + (lhs[0][1] * rhs[1][1]);
	ret[1][0] = (lhs[1][0] * rhs[0][0]) + (lhs[1][1] * rhs[1][0]);
	ret[1][1] = (lhs[1][0] * rhs[0][1]) + (lhs[1][1] * rhs[1][1]);
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			lhs[row][col] = ret[row][col] % 1000000007;
		}
	}
}

std::map<int, long long[2][2]> map;
int count, dataSize;
void Problem_11444(long long i)
{
	map[1][0][0] = 1; map[1][0][1] = 1; map[1][1][0] = 1; map[1][1][1] = 0;
	long long input, current = 1, size = sizeof(long long) * 4;
	std::map<int, long long[2][2]>::iterator itr;
	//std::cin >> input;
	input = i;
	input %= 2000000016;
	if (input == 0) { std::cout << 0; }
	else 
	{
		long long result[2][2]{ {1, 1}, {1, 0} };
		while (input > current)
		{
			count++;
			itr = map.begin();
			while (itr != map.end() && (*(itr)).first < input - current) { std::advance(itr, 1); }
			if (itr != map.begin()) { std::advance(itr, -1); }
			mult(result, (*(itr)).second);
			current += (*(itr)).first;
			memcpy(map[current], result, size);
		}

		dataSize = map.size();
		//std::cout << result[0][1];
	}
}
*/

/// <summary>
/// Test code for 11444
/// </summary>
/*
void Problem_11444_Test()
{
	long long num = 0;
	long long max = 0;
	while (num < 2000000016)
	{
		count = 0;
		dataSize = 0;
		map = std::map<int, long long[2][2]>();
		num++;

		Problem_11444(num);
		if (max < count) 
		{ 
			max = count; 
			std::cout << max << "   " << dataSize << std::endl;
		}
	}
}
*/

// PROBLEM 7677

/// <summary>
/// 문제 11444와 마찬가지로 피보나치의 점화식을 행렬 곱셈으로 풀이하면 된다.
/// </summary>
/*
void mult(long long(*lhs)[2], long long(*rhs)[2])
{
	long long ret[2][2];
	ret[0][0] = (lhs[0][0] * rhs[0][0]) + (lhs[0][1] * rhs[1][0]);
	ret[0][1] = (lhs[0][0] * rhs[0][1]) + (lhs[0][1] * rhs[1][1]);
	ret[1][0] = (lhs[1][0] * rhs[0][0]) + (lhs[1][1] * rhs[1][0]);
	ret[1][1] = (lhs[1][0] * rhs[0][1]) + (lhs[1][1] * rhs[1][1]);
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			lhs[row][col] = ret[row][col] % 10000;
		}
	}
}

std::map<int, long long[2][2]> map;

void Problem_7677()
{
	map[1][0][0] = 1; map[1][0][1] = 1; map[1][1][0] = 1; map[1][1][1] = 0;
	long long input, current = 1, size = sizeof(long long) * 4;
	std::map<int, long long[2][2]>::iterator itr;
	std::string outputStr;
	while (true)
	{
		std::cin >> input;
		if (input == -1) { break; }
		input %= 15000;
		if (input == 0) { outputStr += "0\n"; continue; }

		long long result[2][2]{ {1, 1}, {1, 0} };
		current = 1;
		while (input > current)
		{
			itr = map.begin();
			while (itr != map.end() && (*(itr)).first < input - current) { std::advance(itr, 1); }
			if (itr != map.begin()) { std::advance(itr, -1); }
			mult(result, (*(itr)).second);
			current += (*(itr)).first;
			memcpy(map[current], result, size);
		}

		outputStr += std::to_string(result[0][1]) + '\n';
	}

	std::cout << outputStr;
}
*/

// PROBLEM 2086
/*
void mult(long long(*lhs)[2], long long(*rhs)[2])
{
	long long ret[2][2];
	ret[0][0] = (lhs[0][0] * rhs[0][0]) + (lhs[0][1] * rhs[1][0]);
	ret[0][1] = (lhs[0][0] * rhs[0][1]) + (lhs[0][1] * rhs[1][1]);
	ret[1][0] = ret[0][1];
	ret[1][1] = (lhs[1][0] * rhs[0][1]) + (lhs[1][1] * rhs[1][1]);
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			lhs[row][col] = ret[row][col] % 1000000007;
		}
	}
}

std::map<int, long long[2][2]> map;

void Problem_2086()
{
	long long nums[2] = { 0 };
	long long num;

	map[1][0][0] = 1; map[1][0][1] = 1; map[1][1][0] = 1; map[1][1][1] = 0;
	long long current = 1, size = sizeof(long long) * 4;
	std::map<int, long long[2][2]>::iterator itr;
	std::cin >> nums[0] >> nums[1];

	long long temp;
	if (nums[0] < nums[1])
	{
		temp = nums[0];
		nums[0] = nums[1];
		nums[0] = temp;
	}

	if (nums[1] == 0) { num = 0; }
	else
	{
		while ((temp = nums[0] % nums[1]) != 0)
		{
			nums[0] = nums[1];
			nums[1] = temp;
		}

		num = nums[1];
	}


	num %= 2000000016;
	if (num == 0) { std::cout << 0; }
	else
	{
		long long result[2][2]{ {1, 1}, {1, 0} };
		while (num > current)
		{
			itr = map.begin();
			while (itr != map.end() && (*(itr)).first < num - current) { std::advance(itr, 1); }
			if (itr != map.begin()) { std::advance(itr, -1); }
			mult(result, (*(itr)).second);
			current += (*(itr)).first;
			memcpy(map[current], result, size);
		}

		std::cout << result[0][1];
	}
}
*/

// PROBLEM 2525
/*
void Problem_2525()
{
	int H, M, S;
	std::cin >> H >> M >> S;

	std::cout << (H + ((M + S) / 60)) % 24 << " " << (M + S) % 60;
}
*/

// PROBLEM 2480
/*
void Problem_2480()
{
	int n[3];
	std::cin >> n[0] >> n[1] >> n[2];

	if (n[0] == n[1] && n[1] == n[2]) { std::cout << n[0] * 1000 + 10000; }
	else if(n[0] != n[1] && n[0] != n[2] && n[1] != n[2]) { std::cout << *(std::max_element(n, n + 3)) * 100; }
	else if(n[0] == n[1]) { std::cout << n[0] * 100 + 1000; }
	else if (n[0] == n[2]) { std::cout << n[0] * 100 + 1000; }
	else{ std::cout << n[1] * 100 + 1000; }

}
*/

// PROBLEM 1931
/*
struct Comp_EndTime
{
	bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const noexcept
	{
		if (lhs.second == rhs.second)
		{
			return lhs.first > rhs.first;	
		}
		return lhs.second > rhs.second;
	}
};

void Problem_1931()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comp_EndTime> standby;
	int N, num[2];
	std::cin >> N;
	while (N-- > 0)
	{
		std::cin >> num[0] >> num[1];
		standby.emplace(std::make_pair(num[0], num[1]));
	}

	int currentEndTime = 0, count = 0;
	while (!standby.empty())
	{
		if (currentEndTime <= standby.top().first)
		{
			count++;
			currentEndTime = standby.top().second;
		}
		standby.pop();
	}

	std::cout << count;
}
*/

// PROBLEM 1780
/*
int N, result[3];
int data[2187][2187];

void process(int sX, int sY, int length)
{
	int lhs = data[sX][sY], check = true;
	for (int row = sX; row < sX + length; row++)
	{
		for (int col = sY; col < sY + length; col++)
		{
			if (data[row][col] != lhs)
			{
				check = false;
				break;
			}
		}
		if (!check) { break; }
	}
	if (!check)
	{
		int oneThirdLength = length / 3;
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				process(sX + x * oneThirdLength, sY + y * oneThirdLength, oneThirdLength);
			}
		}
		return;
	}
	
	result[lhs + 1]++;
}

void Problem_1780()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			std::cin >> data[row][col];
		}
	}

	process(0, 0, N);

	for (int idx = 0; idx < 3; idx++)
	{
		std::cout << result[idx] << '\n';
	}
}
*/

// PROBLEM 1629
/*
int num, mod;

int process(int exp)
{
	if (exp == 1) { return num % mod; }
	long long ret = process(exp / 2);
	if (exp % 2 == 0){ return (ret * ret) % mod; }
	else{ return (((ret * ret) % mod) * num) % mod; }
}

void Problem_1629()
{
	int b;
	std::cin >> num >> b >> mod;

	std::cout << process(b);
}
*/

// PROBLEM 10830
/*
int N;
int data[5][5];
int calc[5][5];

void process(long long exp)
{
	if (exp == 1)
	{ 
		for (int r = 0; r < N; r++){ for (int c = 0; c < N; c++) { calc[r][c] = data[r][c] % 1000; } }
		return; 
	}

	process(exp / 2);
	int sum = 0; int temp[5][5];
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			sum = 0;
			for (int mult = 0; mult < N; mult++)
			{
				sum += (calc[row][mult] * calc[mult][col]) % 1000;
			}
			temp[row][col] = sum % 1000;
		}
	}

	if (exp % 2 == 0)
	{
		for (int r = 0; r < N; r++) { for (int c = 0; c < N; c++) { calc[r][c] = temp[r][c]; } }
	}
	else
	{
		for (int row = 0; row < N; row++)
		{
			for (int col = 0; col < N; col++)
			{
				sum = 0;
				for (int mult = 0; mult < N; mult++)
				{
					sum += (temp[row][mult] * data[mult][col]) % 1000;
				}
				calc[row][col] = sum % 1000;
			}
		}
	}
}


void Problem_10830()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	long long B;
	std::cin >> N >> B;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			std::cin >> data[row][col];
		}
	}

	process(B);

	std::string outputStr;

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			outputStr += std::to_string(calc[row][col]) + " ";
		}
		outputStr += '\n';
	}

	std::cout << outputStr;
}
*/

// PROBLEM 2740
/*
int a[100][100];
int b[100][100];
int res[100][100];
int aRow, aCol;
int bRow, bCol;

void Problem_2740()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> aRow >> aCol;
	for (int row = 0; row < aRow; row++)
	{
		for (int col = 0; col < aCol; col++)
		{
			std::cin >> a[row][col];
		}
	}
	std::cin >> bRow >> bCol;
	for (int row = 0; row < bRow; row++)
	{
		for (int col = 0; col < bCol; col++)
		{
			std::cin >> b[row][col];
		}
	}

	int sum;
	for (int row = 0; row < aRow; row++)
	{
		for (int col = 0; col < bCol; col++)
		{
			sum = 0;
			for (int rCol = 0; rCol < aCol; rCol++)
			{
				sum += a[row][rCol] * b[rCol][col];
			}
			res[row][col] = sum;
		}
	}

	std::string outputStr;

	for (int row = 0; row < aRow; row++)
	{
		for (int col = 0; col < bCol; col++)
		{
			outputStr += std::to_string(res[row][col]) + " ";
		}
		outputStr += '\n';
	}

	std::cout << outputStr;
}
*/

// PROBLELM 11401
/*
long long d = 1, n = 1;

long long process(int exp)
{
	if (exp == 1) { return d; }
	int half = exp / 2;
	long long temp = process(half);
	long long ret = (temp * temp) % 1000000007;
	if (exp % 2 == 0) { return ret; }
	return (ret * d) % 1000000007;
}

void Problem_11401()
{
	int N, K;
	std::cin >> N >> K;

	for (int num = K; num > 0; num--){ d = (d * num) % 1000000007; }
	for (int num = N - K; num > 0; num--) { d = (d * num) % 1000000007; }

	for(int num = N; num > 0; num--){ n = (n * num) % 1000000007; }

	std::cout << (n * process(1000000005)) % 1000000007;
}
*/

// PROBLEM 1654
/*
int K, N;
int data[10001];
int res;

long long getCount(int val)
{
	long long count = 0, temp;
	for (int idx = 0; idx < K; idx++)
	{
		if ((temp = data[idx] / val) == 0) { break; }
		count += temp;
	}
	return count;
}

void binarySearch(int start, int end)
{
	if (start == end) 
	{ 
		res = getCount(start) == N ? start : start - 1;
		return;
	}
	int mid = ((long long)start + end) / 2;
	long long count = getCount(mid);
	if (count < N){ binarySearch(start, mid); }
	else{ binarySearch(mid + 1, end); }
}

void Problem_1654()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::cin >> K >> N;

	for (int idx = 0; idx < K; idx++){ std::cin >> data[idx]; }

	std::sort(data, data + K, [&](const int& lhs, const int& rhs) {return lhs > rhs; });

	binarySearch(1, data[0]);

	std::cout << res;

}
*/

// PROBLEM 2805
/*
int N, M, res;
int data[1000001];

long long getLength(int height)
{
	long long sum = 0, temp;
	for (int idx = 0; idx < N; idx++)
	{
		if ((temp = data[idx] - height) <= 0) { break; }
		sum += temp;
	}
	return sum;
}

void binarySearch(int start, int end)
{
	if (start == end)
	{
		res = getLength(start) == M ? start : start - 1;
		return;
	}

	int mid = ((long long)start + end) / 2;
	long long temp = getLength(mid);
	if (temp >= M)
	{
		binarySearch(mid + 1, end);
	}
	else
	{
		binarySearch(start, mid);
	}
}

void Problem_2805()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N >> M;
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> data[idx];
	}
	std::sort(data, data + N, [&](const int& lhs, const int& rhs) {return lhs > rhs; });

	binarySearch(1, data[0]);

	std::cout << res;
}
*/

// PROBLEM 2110
/*
int N, C, res;
int data[200000];
int lengths[200000] = {1000000001};

int tryPlace(int length)
{
	int count = 0;
	long long sum = 0;
	for (int idx = 0; idx < N; idx++)
	{
		if ((sum += lengths[idx]) >= length)
		{
			sum = 0;
			count++;
		}
	}
	return count;
}

void binarySearch(int start, int end)
{
	if (start == end)
	{
		res = tryPlace(start) == C ? start : start - 1;
		return;
	}

	int mid = (start + end) / 2;
	int temp = tryPlace(mid);
	if (temp >= C)
	{
		binarySearch(mid + 1, end);
	}
	else
	{
		binarySearch(start, mid);
	}
}

void Problem_2110()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N >> C;
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> data[idx];
	}
	std::sort(data, data + N);
	for (int idx = 1; idx < N; idx++)
	{
		lengths[idx] = data[idx] - data[idx - 1];
	}


	binarySearch(1, data[N - 1] - data[0]);

	std::cout << res;
}
*/

// PROBLEM 1300
/*
long long N, K, res = 1;

int bsSub(int start, int end, int col, long long val)
{
	int mid = (start + end) / 2;
	long long temp = (long long)col * mid;
	if (start == end) 
	{ 
		if (temp <= val) 
		{ 
			if (res < temp) { res = temp; }
			return start;
		}
		if (start - 1 - (col - 1) > 0) { temp = (long long)col * (start - 1); if (res < temp) { res = temp; } }
		return start - 1; 
	}
	if (temp == val)
	{
		if (res < temp) { res = temp; }
		return mid;
	}
	else if(temp > val)
	{
		return bsSub(start, mid, col, val);
	}
	else
	{
		return bsSub(mid + 1, end, col, val);
	}
}

long long calc(long long num)
{
	long long ret = 0, temp; res = 1;
	for (int nTemp = 1; nTemp <= N; nTemp++)
	{
		if ((temp = bsSub(nTemp, N, nTemp, num) - (nTemp - 1)) <= 0) { break; }
		ret += (temp * 2) - 1;
	}
	return ret;
}	

void bsMain(long long start, long long end)
{
	if (start == end) { calc(start); return; }
	long long mid = (start + end) / 2;
	long long temp = calc(mid);
	if (temp == K) { return; }
	if (temp > K){ bsMain(start, mid); }
	else{ bsMain(mid + 1, end); }
}

void Problem_1300()
{
	std::cin >> N >> K;

	bsMain(1, N * N);

	std::cout << res;
}

void Problem_1300_Testee(long long n, long long k)
{
	N = n; K = k;
	bsMain(1, N * N);
}

long long TEST_N, TEST_K, TEST_Res;

long long lessNum_inMatrix(long long mid) {
	long long cnt = 0;
	for (int i = 1; i <= TEST_N; i++) {
		// i행은 i의 배수의 집합이므로 
		// mid를 i로 나눠주면 mid가 i행에서 몇 번째에 위치하는지 알 수 있다
		// i행의 최댓값보다 mid/i가 더 크다면 N(행의 크기)을 cnt에 더해준다
		cnt += std::min(TEST_N, (long long)mid / i);
		if (i > mid) break;
	}
	return cnt;
}

void Problem_1300_Test()
{
	while (true)
	{
		TEST_N++;
		for (; TEST_K < (TEST_N * TEST_N);)
		{
			TEST_K++;

			long long lo = 1;
			long long hi = TEST_N * TEST_N;

			TEST_Res = 0;


			while (lo <= hi) {
				long long mid = (lo + hi) / 2;
				// mid와 같거나 작은 값의 개수가 K보다 작으면
				if (lessNum_inMatrix(mid) < TEST_K) lo = mid + 1;
				else {
					TEST_Res = mid;
					hi = mid - 1;
				}
			}

			Problem_1300_Testee(TEST_N, TEST_K);
			if (TEST_Res != res)
			{
				std::cout << "FAIL";
				Problem_1300_Testee(TEST_N, TEST_K);
			}
			else
			{
				std::cout << TEST_N << " " << TEST_K << std::endl;
			}
		}
		TEST_K = 0;
	}

	
}
*/

// PROBLEM 1081
/*
int expNum = 0;
void countNums_proc(std::vector<long long>& arr, std::string num)
{
	for (const auto& elem : num)
	{
		arr[elem - '0'] += pow(10, expNum);
	}
}

void countNums_pushCounts(std::vector<long long>& arr, int lhs, int rhs)
{
	for (int idx = 0; idx < 10; idx++)
	{
		arr[idx] += (rhs - lhs + 1) * pow(10, expNum);
	}

	expNum++;
}

void countNums(std::vector<long long>& res, int s, int e)
{
	// 0 부터 9까지의 등장 횟수
	int end = e, start = s;

	while (end != 0)
	{
		// 시작 번호 끝자리를 0으로 맞추기
		while (start % 10 != 0)
		{
			countNums_proc(res, std::to_string(start));
			if (start == end) { break; }
			start++;
		}

		if (start == end)
		{
			if (start % 10 == 0)
			{
				countNums_proc(res, std::to_string(start));
			}
			break;
		}

		while (end % 10 != 9)
		{
			countNums_proc(res, std::to_string(end));
			if (start == end) { break; }
			end--;
		}

		if (start == end)
		{
			if (end % 10 == 9)
			{
				countNums_proc(res, std::to_string(end));
			}
			break;
		}

		countNums_pushCounts(res, (start /= 10), (end /= 10));
	}
}

void Problem_1081()
{
	int N, M;
	std::cin >> N >> M;
	std::vector<long long> res(10);
	countNums(res, N, M);
	long long sum = 0;
	for (int idx = 1; idx < 10; idx++)
	{
		sum += res[idx] * idx;
	}
	std::cout << sum;
}
*/

// PROBLEM 1225
/*
void Problem_1225()
{
	std::string a, b;
	std::cin >> a >> b;

	long long sum = 0;

	for (const auto& aElem : a)
	{
		for (const auto& bElem : b)
		{
			sum += (aElem - '0') * (bElem - '0');
		}
	}

	std::cout << sum;
}
*/

// PROBLEM 2166
/*
void Problem_2166()
{
	int N;
	std::cin >> N;

	std::vector<double> xAxis(N + 1);
	std::vector<double> yAxis(N + 1);

	double fX, fY, input[2], prev[2];
	std::cin >> fX >> fY;
	prev[0] = fX; prev[1] = fY;

	double res = 0;
	for (int idx = 1; idx < N; idx++)
	{
		std::cin >> input[0] >> input[1];
		res += prev[0] * input[1] - input[0] * prev[1];
		prev[0] = input[0]; prev[1] = input[1];
	}
	res += prev[0] * fY - fX * prev[1];
	res /= 2.0;

	std::cout.precision(1);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	if (res < 0) { res = -res; }
	std::cout << res;
}
*/

// PROBLEM 1010
/*
struct Comp
{
	size_t operator()(const std::pair<int, int>& obj) const noexcept
	{
		return obj.first * 100 + obj.second;
	}
};

std::unordered_map<std::pair<int, int>, long long, Comp> map;

long long calc(int node, int count, int size)
{
	if (count == 0)
	{
		return 1;
	}

	if (node == size) { return 0; }

	std::pair<int, int> key{ node, count };
	std::unordered_map<std::pair<int, int>, long long, Comp>::iterator itr;

	if ((itr = map.find(key)) != map.end())
	{
		return itr->second;
	}

	map[key] = calc(node + 1, count, size) + calc(node + 1, count - 1, size);
	return map[key];
}

void Problem_1010()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T, a, b, count;
	std::cin >> T;
	std::string outputStr;
	while (T-- > 0)
	{
		std::cin >> a >> b;

		map = std::unordered_map<std::pair<int, int>, long long, Comp>();
		outputStr += std::to_string(calc(0, a, b)) + '\n';
	}

	std::cout << outputStr;
}
*/

// PROBLEM 1158
/*
void Problem_1158()
{
	int N, K;
	std::cin >> N >> K;


	std::queue<int> data;
	for (int num = 1; num <= N; num++)
	{
		data.emplace(num);
	}

	std::string outputStr{ "<" };

	while (data.size() > 1)
	{
		for (int count = 1; count < K; count++)
		{
			data.emplace(data.front());
			data.pop();
		}
		outputStr += std::to_string(data.front()) + ", ";
		data.pop();
	}
	outputStr += std::to_string(data.front()) + ">";

	std::cout << outputStr;
}
*/

// PROBLEM 1100
/*
void Problem_1100()
{
	std::string data[8];
	
	for (int row = 0; row < 8; row++)
	{
		std::cin >> data[row];
	}

	int count = 0;
	for (int row = 0; row < 8; row++)
	{
		for (int col = row % 2; col < 8; col += 2)
		{
			if (data[row][col] == 'F') { count++; }
		}
	}

	std::cout << count;
}
*/

// PROBLEM 3046
/*
void Problem_3046()
{
	int R1, S;
	std::cin >> R1 >> S;

	std::cout << (S * 2) - R1;
}
*/

// PROBLEM 1934
/*
int gcd(int lhs, int rhs)
{
	if (rhs == 0) { return lhs; }
	return gcd(rhs, lhs % rhs);
}

void Problem_1934()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;
	std::string outputStr;
	while (T-- > 0)
	{
		int a, b;
		std::cin >> a >> b;

		outputStr += std::to_string(a * b / gcd(a, b)) + '\n';
	}

	std::cout << outputStr;
}
*/

// PROBLEM 2609
/*
int gcd(int lhs, int rhs)
{
	if (rhs == 0) { return lhs; }
	return gcd(rhs, lhs % rhs);
}

void Problem_2609()
{
	int a, b;
	std::cin >> a >> b;

	std::cout << gcd(std::max(a, b), std::min(a, b)) << '\n';
	std::cout << a * b / gcd(std::max(a, b), std::min(a, b));
}
*/

// PROBLEM 5086
/*
void Problem_5086()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int nums[2];

	std::string outputStr;
	while (true)
	{
		std::cin >> nums[0] >> nums[1];
		if (nums[0] == 0 && nums[1] == 0) { break; }

		if (nums[1] % nums[0] == 0){ outputStr += "factor\n"; }
		else if (nums[0] % nums[1] == 0){ outputStr += "multiple\n"; }
		else{ outputStr += "neither\n"; }
	}

	std::cout << outputStr;
}
*/

// PROBLEM 1271
/*
void Problem_1271()
{
	double n, m;
	std::cin >> n >> m;

	std::cout << std::fixed;
	std::cout.precision(0);
	std::cout << (n / m) << '\n' << n - m * std::floor(n / m);
}
*/

// PREOBLEM 10950
/*
void Problem_10950()
{
	int T, n = 0;
	std::cin >> T;
	std::string outputStr, numStr, temp;
	while (T-- > 0)
	{
		std::cin >> numStr;
		n = 0;
		temp.clear();
		for (const auto& elem : numStr)
		{
			if (elem == ',')
			{
				n = std::stoi(temp);
				temp.clear();
				continue;
			}
			temp += elem;
		}
		n += std::stoi(temp);
		outputStr += std::to_string(n) + '\n';
	}

	std::cout << outputStr;
}
*/

// PROBLEM 1037
/*
void Problem_1037()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	int N;
	std::cin >> N;

	int num;
	int max = 0, min = 1000000;
	while (N-- > 0)
	{
		std::cin >> num;

		if (num > max) { max = num; }
		if (num < min) { min = num; }

	}

	std::cout << (long long)max * min;
}
*/

// PROBLEM 10039
/*
void Problem_10039()
{
	int num, sum = 0;

	for (int count = 0; count < 5; count++)
	{
		std::cin >> num;
		if (num < 40) { sum += 40; continue; }
		sum += num;
	}

	std::cout << (float)sum / 5.0f;
}
*/

// PROBLEM 2475
/*
void Problem_2475()
{
	int num, sum = 0;

	for (int count = 0; count < 5; count++)
	{
		std::cin >> num;
		sum += num * num;
	}

	std::cout << sum % 10;
}

void Problem_1051()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	int input[50][50] = { 0 };
	int count = N;
	while (count > 0)
	{
		std::string inputStr;
		std::cin >> inputStr;
		int currCol = N - count--;
		for (int idx = 0; idx < M; idx++)
		{
			input[currCol][idx] = inputStr[idx] - '0';
		}
	}

	int max = 0;
	for (int colIdx = 0; colIdx < N - 1; colIdx++)
	{
		for (int rowIdx = 0; rowIdx < M - 1; rowIdx++)
		{
			int colMaxLength = N - colIdx - 1;
			int rowMaxLength = M - rowIdx - 1;
			bool rectResult = false;
			for (int length = colMaxLength <= rowMaxLength ? colMaxLength : rowMaxLength; length > max; length--)
			{
				bool rectResult = false;

				if ((rectResult = input[colIdx][rowIdx] ^ input[colIdx + length][rowIdx + length]))
					continue;

				if ((rectResult = input[colIdx][rowIdx] ^ input[colIdx + length][rowIdx]))
					continue;

				if ((rectResult = input[colIdx][rowIdx] ^ input[colIdx][rowIdx + length]))
					continue;

				if (length > max)
					max = length;
			}
		}
	}

	max += 1;
	std::cout << max * max;
}
*/

#include <unordered_set>
// PROBLEM 1269
/*void Problem_1269()
{
	int c = 10;
	while (c-- > 0)
	{
		double timeChecker = TimeChecker::CheckTime([]() {

			std::ios_base::sync_with_stdio(false);
			std::cin.tie(nullptr);

			int m, n;

			std::cin >> m >> n;
			std::unordered_set<int> aSet(200000);

			int count = m, input;
			while (count-- > 0)
			{
				std::cin >> input;
				aSet.emplace(input);
			}

			int duplicatedElemCount = 0;
			count = n;
			while (count-- > 0)
			{
				std::cin >> input;
				if (aSet.find(input) != aSet.end())
					duplicatedElemCount++;
			}

			std::cout << m + n - duplicatedElemCount - duplicatedElemCount;
		});

		std::cout << std::endl << timeChecker << std::endl;
	}
}

void Problem_1269_vector()
{
	int c = 10;
	while (c-- > 0)
	{
		double timeChecker = TimeChecker::CheckTime([]() {

			std::ios_base::sync_with_stdio(false);
			std::cin.tie(nullptr);

			int result = 0;
			std::string input;
			std::getline(std::cin, input);
			std::vector<bool> aSet(100000000);

			std::getline(std::cin, input);


			std::string::iterator last = input.begin();
			auto itr = input.begin();
			while (++itr != input.end())
			{
				if (*itr == ' ')
				{
					aSet[std::stoi(input.substr(last - input.begin(), itr - last))] = true;
					last = itr + 1;
					result++;
				}
			}
			aSet[std::stoi(input.substr(last - input.begin(), input.end() - last))] = true;


			std::getline(std::cin, input);

			last = input.begin();
			itr = input.begin();
			while (++itr != input.end())
			{
				if (*itr == ' ')
				{
					if (aSet[std::stoi(input.substr(last - input.begin(), itr - last))])
						result -= 2;
					last = itr + 1;
					result++;
				}
			}
			if (aSet[std::stoi(input.substr(last - input.begin(), input.end() - last))])
				result -= 2;

			std::cout << result + 2;
		});

		std::cout << std::endl << timeChecker << std::endl;
	}
}
*/

void ExecuteBaekjoonMathProblems()
{
	//Problem_1269_vector();
	//Problem_1051();
	//Problem_2475();
	//Problem_10039();
	//Problem_1037();
	//Problem_10950();
	//Problem_1271();
	//Problem_5086();
	//Problem_2609();
	//Problem_1934();
	//Problem_3046();
	//Problem_1100();
	//Problem_1158();
	//Problem_1010();
	//Problem_2166();
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
	//Problem_10870();
	//Problem_10826();
	//Problem_9471();
	//Problem_2749();
	//Problem_1463();
	//Problem_2447();
	//Problem_11729();
	//Problem_2798();
	//Problem_2231();
	//Problem_7568();
	//Problem_1436();
	//Problem_11444();
	//Problem_11444_Test();
	//Problem_7677();
	//Problem_2086();
	//Problem_2525();
	//Problem_2480();
	//Problem_1931();
	//Problem_1780();
	//Problem_1629();
	//Problem_10830();
	//Problem_2740();
	//Problem_11401();
	//Problem_1654();
	//Problem_2805();
	//Problem_2110();
	//Problem_1300();
	//Problem_1300_Test();
	//Problem_1300();
	//Problem_1081();
	//Problem_1929_TEST();
	//Problem_1225();
}