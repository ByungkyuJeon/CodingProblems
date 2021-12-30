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
/*
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
*/

// PROBLEM 1422
/*
std::vector<std::string> result_1422;
std::string maxStr_1422 = "";

void Problem_1422()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int K, N;
	std::string tempStr;
	std::cin >> K >> N;

	for (int idx = 0; idx < K; idx++)
	{
		std::cin >> tempStr;
		result_1422.emplace_back(tempStr);

		if (maxStr_1422.size() == tempStr.size())
		{
			if (maxStr_1422 < tempStr)
			{
				maxStr_1422 = tempStr;
			}
		}
		else if (maxStr_1422.size() < tempStr.size())
		{
			maxStr_1422 = tempStr;
		}
	}

	N -= K;

	while (N-- > 0)
	{
		result_1422.emplace_back(maxStr_1422);
	}

	std::sort(result_1422.begin(), result_1422.end(), [](const std::string& lhs, const std::string& rhs)
		{
			return lhs + rhs > rhs + lhs;
		});

	for (const auto& elem : result_1422)
	{
		std::cout << elem;
	}
}
*/

// PROBLEM 1374
/*
int data_1374[100001];

struct comp_1374
{
	bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
	{
		return lhs.second > rhs.second;
	}
};

void Problem_1374()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp_1374> startQueue;
	std::priority_queue<int, std::vector<int>, std::greater<int>> endQueue;


	int N, inputBuffer[3], result = 0;
	std::cin >> N;

	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> inputBuffer[0] >> inputBuffer[1] >> inputBuffer[2];
		startQueue.emplace(std::make_pair(inputBuffer[0], inputBuffer[1]));
		data_1374[inputBuffer[0]] = inputBuffer[2];
	}

	while (!startQueue.empty())
	{
		if (endQueue.empty() || endQueue.top() > startQueue.top().second)
		{
			endQueue.emplace(data_1374[startQueue.top().first]);
			startQueue.pop();
		}
		else
		{
			endQueue.pop();
		}

		if (result < endQueue.size()) { result = endQueue.size(); }
	}

	std::cout << result;
}
*/

// PROBLEM 1379
int data_1379[100001];
int nums_1379[100001];

struct comp_1379
{
	bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const
	{
		return lhs.second > rhs.second;
	}
};

void Problem_1379()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp_1379> startQueue;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp_1379> endQueue;
	std::priority_queue<int, std::vector<int>, std::greater<int>> numsQueue;
	std::string outputStr;

	int N, buffer, inputBuffer[2];
	std::cin >> N;

	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> buffer >> inputBuffer[0] >> inputBuffer[1];
		startQueue.emplace(std::make_pair(buffer, inputBuffer[0]));
		data_1379[buffer] = inputBuffer[1];
		numsQueue.emplace(idx + 1);
	}

	buffer = 0;
	while (!startQueue.empty())
	{
		if (endQueue.empty() || endQueue.top().second > startQueue.top().second)
		{
			endQueue.emplace(std::make_pair(numsQueue.top(),data_1379[startQueue.top().first]));
			nums_1379[startQueue.top().first] = numsQueue.top();
			numsQueue.pop();
			startQueue.pop();
		}
		else
		{
			numsQueue.emplace(endQueue.top().first);
			endQueue.pop();
		}

		if (buffer < endQueue.size()) { buffer = endQueue.size(); }
	}

	std::cout << buffer << '\n';
	for(buffer = 1; buffer <= N; buffer++)
	{
		outputStr += std::to_string(nums_1379[buffer]) + '\n';
	}
	std::cout << outputStr;
}

void ExecuteGreedy()
{
	//Problem_1040();
	//Problem_23845();
	//Problem_1422();

	Problem_1379();
}