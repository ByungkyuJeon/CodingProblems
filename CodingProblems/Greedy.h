#pragma once

// PROBLEM 1040
/*
std::string numStr_1040;
int digitCounter_1040[10];
long long N_1040, K_1040;

int getCount_1040()
{
	int result = 0;
	for (int idx = 0; idx < 10; idx++)
	{
		if (digitCounter_1040[idx])
		{
			result++;
		}
	}
	return result;
}

int getSameNum_1040(int origin)
{
	int result = -1;
	for (int idx = origin + 1; idx < 10; idx++)
	{
		if (digitCounter_1040[idx])
		{
			result = idx;
			break;
		}
	}
	return result;
}

int getDiffNum_1040(int origin)
{
	int result = -1;
	for (int idx = origin + 1; idx < 10; idx++)
	{
		if (digitCounter_1040[idx] == 0)
		{
			result = idx;
			break;
		}
	}
	return result;
}

void setAllToZero(int offset)
{
	for (int idx = offset; idx < numStr_1040.size(); idx++)
	{
		numStr_1040[idx] = '/';
	}
}

bool process_1040(int idx, int count)
{
	if (idx == numStr_1040.size())
	{
		return K_1040 == count;
	}
	if (numStr_1040.size() - idx < K_1040 - count || K_1040 < count) { return false; }

	bool result = false;
	if (numStr_1040[idx] != '/')
	{ 
		digitCounter_1040[numStr_1040[idx] - '0']++;
		result = process_1040(idx + 1, getCount_1040());
	}
	int nextNum;

	while (!result)
	{
		if (numStr_1040[idx] != '/') { digitCounter_1040[numStr_1040[idx] - '0']--; }

		if (K_1040 == count)
		{
			nextNum = getSameNum_1040(numStr_1040[idx] - '0');
		}
		else
		{
			if (numStr_1040[idx] == '9') { nextNum = -1; }
			else { nextNum = numStr_1040[idx] + 1 - '0'; }
		}

		if (nextNum == -1)
		{
			numStr_1040[idx] = '/';
			return false;
		}
		numStr_1040[idx] = nextNum + '0';
		setAllToZero(idx + 1);
		digitCounter_1040[numStr_1040[idx] - '0']++;
		result = process_1040(idx + 1, getCount_1040());
	}

	return true;
}

void Problem_1040()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N_1040 >> K_1040;
	numStr_1040 = std::to_string(N_1040);

	while (!process_1040(0, 0))
	{
		numStr_1040 = '1' + numStr_1040;
		setAllToZero(1);
	}

	std::cout << numStr_1040;
}
*/

// PROBLEM 23845
int data_23845[200001];
int counts_23845[100001];
long long result;

inline void segProcess_23845(int start, long long end)
{
	if(start == end)
	{
		result += end * counts_23845[start];
		return;
	}
	auto minmax = std::minmax_element(&counts_23845[start], (&counts_23845[end] + 1));
	int minNum = minmax.first - counts_23845;
	int maxCount = *minmax.second;
	int minCount = *minmax.first;
	if (minCount != 0)
	{
		for (int num = start; num <= end; num++)
		{
			counts_23845[num] -= minCount;
		}

		result += end * (end - start + 1) * minCount;
	}

	if (maxCount == minCount) { return; }
	if(minNum - 1 >= start){ segProcess_23845(start, minNum - 1); }
	if(minNum + 1 <= end){ segProcess_23845(minNum + 1, end); }
}

void Problem_23845()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::srand(std::time(nullptr));

	int N, idxCounter = 0;
	std::cin >> N;

	double consumedTime = TimeChecker::CheckTime([&] {

	while(N-- > 0)
	{
		//std::cin >> data_23845[idxCounter];
		data_23845[idxCounter] = std::rand() % 100000;
		counts_23845[data_23845[idxCounter]]++;
		if (counts_23845[data_23845[idxCounter]] == 1) { idxCounter++; }
	}
	std::sort(data_23845, data_23845 + idxCounter, [](const int& lhs, const int& rhs) {return lhs > rhs; });

	int startIdx = 0, endIdx = 0;
	int prev = data_23845[0];
	for (int idx = 1; idx < idxCounter; idx++)
	{
		if (prev - data_23845[idx] == 1)
		{
			endIdx++;
		}
		else
		{
			segProcess_23845(data_23845[endIdx], data_23845[startIdx]);
			startIdx = endIdx = idx;
		}

		prev = data_23845[idx];
	}
	segProcess_23845(data_23845[endIdx], data_23845[startIdx]);

	std::cout << result;

		});

	std::cout << " time : " << consumedTime << " ms";
}

void ExecuteGreedy()
{
	//Problem_1040();
	Problem_23845();
}