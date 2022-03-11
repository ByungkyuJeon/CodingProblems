#pragma once

// PROBLEM 3273

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

void executeTwoPointer()
{
	Problem_3273();
}