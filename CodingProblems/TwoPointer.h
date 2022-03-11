#pragma once

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

void executeTwoPointer()
{
	//Problem_3273();
	Problem_2470();
}