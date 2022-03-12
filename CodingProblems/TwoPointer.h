#pragma once

#include <numeric>

// PROBLEM 3273
/*
void Problem_3273()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N;
	std::vector<int> data(N);
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> data[idx];
	}
	std::cin >> M;

	std::sort(data.begin(), data.end());
	int sIdx = 0, eIdx = N - 1, sum, count = 0;

	while (sIdx < eIdx)
	{
		sum = data[sIdx] + data[eIdx];
		if (sum > M)
		{
			eIdx--;
		}
		else if (sum < M)
		{
			sIdx++;
		}
		else
		{
			count++;
			sIdx++;
		}
	}
	std::cout << count;
}
*/

// PROBLEM 2470
/*
void Problem_2470()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;
	std::vector<int> data(N);
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> data[idx];
	}

	std::sort(data.begin(), data.end());

	long long sum, nxtSum = 0, min = 9999999999999;
	int sIdx = 0; int eIdx = N - 1;
	int res[2];

	nxtSum = std::abs((long long)data[sIdx] + data[eIdx]);

	while (sIdx < eIdx)
	{
		sum = nxtSum;
		if (sum < min)
		{
			min = sum;
			res[0] = data[sIdx];
			res[1] = data[eIdx];
		}

		if (sIdx < eIdx - 1 && sum > (nxtSum = std::abs((long long)data[sIdx] + data[eIdx - 1])))
		{
			eIdx--;
		}
		else
		{
			nxtSum = std::abs((long long)data[++sIdx] + data[eIdx]);
		}
	}

	std::cout << res[0] << " " << res[1];
}
*/

// PROBLEM 1806
/*
void Problem_1806()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, S;
	std::cin >> N >> S;
	std::vector<int> data(N);
	long long sum = 0;
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> data[idx];
		sum += data[idx];
	}

	if (sum >= S)
	{
		int sIdx = 0, eIdx = 0;
		int min = N;
		sum = data[sIdx];
		while (true)
		{
			if (sum >= S && min > eIdx - sIdx + 1) { min = eIdx - sIdx + 1; }
			if (sIdx != eIdx && sum >= S)
			{
				sum -= data[sIdx++];
			}
			else
			{
				if (eIdx == N - 1) { break; }
				sum += data[++eIdx];
			}
		}

		std::cout << min;
	}
	else
	{
		std::cout << 0;
	}
}
*/

// PROBLEM 1644

std::vector<int> primeRange(int start, int end)
{
	int m = start, n = end, squrtNum, temp = 2, nxtNum, firstErased = 0;
	bool checker;

	if (m == 1) { m = 2; }
	std::vector<int> result(n - m + 1);
	for (int idx = 0; idx < result.size(); idx++) { result[idx] = m + idx; }
	squrtNum = sqrt(n);
	while (temp <= squrtNum)
	{
		nxtNum = -1;
		checker = false;
		result.erase(std::remove_if(result.begin() + firstErased, result.end(), [&](int n)
			{
				bool res = n != temp && n % temp == 0;
				if (!checker && !res && temp < n) 
				{
					firstErased++;
					nxtNum = n;
					checker = true;
				} 
				return res;
			}), result.end());
		temp = nxtNum;
	}
	return result;
}

void Problem_1644()
{
	int N;
	std::cin >> N;
	if (N == 1) { std::cout << 0; }
	else
	{
		std::vector<int> primes = primeRange(2, N);

		int sIdx = 0, eIdx = 0, resCnt = N == 2, sum = primes[0];
		while (true)
		{
			if (sum <= N || sIdx == eIdx)
			{
				if (eIdx + 1 == primes.size()) { break; }
				sum += primes[++eIdx];
			}
			else
			{
				sum -= primes[sIdx++];
			}
			if (sum == N)
			{
				resCnt++;
			}
		}
		std::cout << resCnt;
	}
}

void executeTwoPointer()
{
	//Problem_3273();
	//Problem_2470();
	//Problem_1806();
	Problem_1644();
}