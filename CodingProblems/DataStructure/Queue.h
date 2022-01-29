#pragma once

#include<queue>
#include<utility>

// PROBLEM 2075
/*
int table_2075[1501][1501];
int currentIdxes[1501];

struct comp_2075
{
	bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
	{
		return lhs.first < rhs.first;
	}
};

void Problem_2075()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	for (int outerIdx = 0; outerIdx < N; outerIdx++)
	{
		currentIdxes[outerIdx] = N - 1;
		for (int innerIdx = 0; innerIdx < N; innerIdx++)
		{
			std::cin >> table_2075[outerIdx][innerIdx];
		}
	}

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp_2075> searchLine;
	for (int tableIdx = 0; tableIdx < N; tableIdx++)
	{
		searchLine.emplace(std::make_pair(table_2075[N - 1][tableIdx], tableIdx));
	}

	N--;
	while (N-- >0)
	{
		currentIdxes[searchLine.top().second]--;
		searchLine.emplace(std::make_pair(table_2075[currentIdxes[searchLine.top().second]][searchLine.top().second], searchLine.top().second));
		searchLine.pop();
	}

	std::cout << searchLine.top().first << '\n';
}
*/

// PROBLEM 18258
/*
void Problem_18258()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::queue<int> dataQueue;
	std::string inputStr, outputStr;
	int N, inputNum;
	std::cin >> N;
	while (N-- > 0)
	{
		std::cin >> inputStr;
		if (inputStr == "push")
		{
			std::cin >> inputNum;
			dataQueue.push(inputNum);
		}
		else if (inputStr == "pop")
		{
			if (dataQueue.empty())
			{
				outputStr += std::to_string(-1) + '\n';
			}
			else
			{
				outputStr += std::to_string(dataQueue.front()) + '\n';
				dataQueue.pop();
			}
		}
		else if (inputStr == "size")
		{
			outputStr += std::to_string(dataQueue.size()) + '\n';
		}
		else if (inputStr == "empty")
		{
			if (dataQueue.empty())
			{
				outputStr += std::to_string(1) + '\n';
			}
			else
			{
				outputStr += std::to_string(0) + '\n';
			}
		}
		else if (inputStr == "front")
		{
			if (dataQueue.empty())
			{
				outputStr += std::to_string(-1) + '\n';
			}
			else
			{
				outputStr += std::to_string(dataQueue.front()) + '\n';
			}
		}
		else if (inputStr == "back")
		{
			if (dataQueue.empty())
			{
				outputStr += std::to_string(-1) + '\n';
			}
			else
			{
				outputStr += std::to_string(dataQueue.back()) + '\n';
			}
		}
	}

	std::cout << outputStr;
}
*/

// PROBLEM 1039
/*
void Problem_1039()
{
	int chCount[58] = { 0 };
	int N, K;
	std::cin >> N >> K;

	std::string numStr = std::to_string(N);

	bool check = false;
	for (const auto& elem : numStr)
	{
		if (++chCount[elem] > 1)
		{
			check = true;
			break;
		}
	}

	if (numStr.size() <= 1 || (numStr.size() == 2 && numStr.find('0', 0) != std::string::npos))
	{
		std::cout << -1;
	}
	else
	{
		int completed = -1, max;
		std::vector<int> maxIndices;
		std::set<int> swappedIndices;
		std::priority_queue<int> swappedvalues;
		while (K > 0)
		{
			if (completed + 1 < numStr.size() - 1)
			{
				max = completed + 1;
				maxIndices.clear();
				maxIndices.emplace_back(max);
				for (int idx = completed + 2; idx < numStr.size(); idx++)
				{
					if (numStr[idx] > numStr[max]) { max = idx; maxIndices.clear(); maxIndices.emplace_back(idx); }
					else if (numStr[idx] == numStr[max]) { maxIndices.emplace_back(idx); }
				}

				if (numStr[*(maxIndices.end() - 1)] != numStr[completed + 1])
				{
					std::swap(numStr[*(maxIndices.end() - 1)], numStr[completed + 1]);

					if (maxIndices.size() > 1 || (swappedIndices.find(completed + 1) != swappedIndices.end() || swappedIndices.find(*(maxIndices.end() - 1)) != swappedIndices.end()))
					{
						if (swappedIndices.find(completed + 1) != swappedIndices.end() && swappedIndices.find(*(maxIndices.end() - 1)) != swappedIndices.end())
						{
							K++;
						}
						for (const auto& elem : maxIndices)
						{
							swappedIndices.emplace(elem);
						}
					}

					if (--K == 0)
					{
						for (const auto& elem : swappedIndices)
						{
							swappedvalues.emplace(numStr[elem]);
						}

						for (const auto& elem : swappedIndices)
						{
							numStr[elem] = swappedvalues.top();
							swappedvalues.pop();
						}
						break;
					}
				}
				completed++;
			}
			else
			{
				for (const auto& elem : swappedIndices)
				{
					swappedvalues.emplace(numStr[elem]);
				}

				for (const auto& elem : swappedIndices)
				{
					numStr[elem] = swappedvalues.top();
					swappedvalues.pop();
				}

				if (check)
				{
					if (numStr[numStr.size() - 1] > numStr[numStr.size() - 2])
					{
						std::swap(numStr[numStr.size() - 1], numStr[numStr.size() - 2]);
					}
					break;
				}
				else
				{
					if (K % 2 == 1)
					{
						std::swap(numStr[numStr.size() - 1], numStr[numStr.size() - 2]);
					}
					break;
				}
			}
		}

		std::cout << numStr;
	}
}

int Problem_1039_Testee(int N, int K)
{
	int chCount[58] = { 0 };
	std::string numStr = std::to_string(N);
	bool check = false;

	for (const auto& elem : numStr)
	{
		if (++chCount[elem] > 1)
		{
			check = true;
			break;
		}
	}

	if (numStr.size() <= 1 || (numStr.size() == 2 && numStr.find('0', 0) != std::string::npos))
	{
		return -1;
	}
	else
	{
		int completed = -1, max;
		std::vector<int> maxIndices;
		std::set<int> swappedIndices;
		std::priority_queue<int> swappedvalues;
		while (K > 0)
		{
			if (completed + 1 < numStr.size() - 1)
			{
				max = completed + 1;
				maxIndices.clear();
				maxIndices.emplace_back(max);
				for (int idx = completed + 2; idx < numStr.size(); idx++)
				{
					if (numStr[idx] > numStr[max]) { max = idx; maxIndices.clear(); maxIndices.emplace_back(idx); }
					else if (numStr[idx] == numStr[max]) { maxIndices.emplace_back(idx); }
				}

				if (numStr[*(maxIndices.end() - 1)] != numStr[completed + 1])
				{
					std::swap(numStr[*(maxIndices.end() - 1)], numStr[completed + 1]);

					if (maxIndices.size() > 1 || (swappedIndices.find(completed + 1) != swappedIndices.end() || swappedIndices.find(*(maxIndices.end() - 1)) != swappedIndices.end()))
					{
						if (swappedIndices.find(completed + 1) != swappedIndices.end() && swappedIndices.find(*(maxIndices.end() - 1)) != swappedIndices.end())
						{
							K++;
						}
						for (const auto& elem : maxIndices)
						{
							swappedIndices.emplace(elem);
						}
					}

					if (--K == 0)
					{
						for (const auto& elem : swappedIndices)
						{
							swappedvalues.emplace(numStr[elem]);
						}

						for (const auto& elem : swappedIndices)
						{
							numStr[elem] = swappedvalues.top();
							swappedvalues.pop();
						}
						break;
					}
				}
				completed++;
			}
			else
			{
				for (const auto& elem : swappedIndices)
				{
					swappedvalues.emplace(numStr[elem]);
				}

				for (const auto& elem : swappedIndices)
				{
					numStr[elem] = swappedvalues.top();
					swappedvalues.pop();
				}

				if (check)
				{
					if (numStr[numStr.size() - 1] > numStr[numStr.size() - 2])
					{
						std::swap(numStr[numStr.size() - 1], numStr[numStr.size() - 2]);
					}
					break;
				}
				else
				{
					if (K % 2 == 1)
					{
						std::swap(numStr[numStr.size() - 1], numStr[numStr.size() - 2]);
					}
					break;
				}
			}
		}

		return std::stoi(numStr);
	}
}

void Problem_1039_Trial2()
{
	int N, K;
	std::cin >> N >> K;
	std::string numStr = std::to_string(N);

}

int nextMaximum[1000001][11];

int dfs(std::string num, int depth)
{ 
	if (0 == depth) return stoi(num);
	const int currNum = stoi(num);
	int& maximum = nextMaximum[currNum][depth];
	if (0 <= maximum) return maximum;
	for (int i = 0; i < num.length(); i++)
	{
		for (int j = i + 1; j < num.length(); j++) 
		{
			if (0 == i && '0' == num[j]) 
				continue; 
			std::swap(num[i], num[j]);
			maximum = std::max(maximum, dfs(num, depth - 1));
			std::swap(num[i], num[j]); 
		} 
	} 
	return maximum;
}

void Problem_1039_Tester()
{
	std::srand(std::time(NULL));
	int result, testResult;
	int n;
	int k;


	while (true)
	{
		n = (std::rand() % 1000000) + 1;
		//n = 30992;
		k = (std::rand() % 10) + 1;
		//k = 3;

		memset(nextMaximum, -1, sizeof(int) * 1000001 * 11);
		result = dfs(std::to_string(n), k);
		testResult = Problem_1039_Testee(n, k);
		if (result != testResult)
		{
			std::cout << "fail";
		}
		else
		{
			std::cout << "pass" << std::endl;
		}
	}
}
*/



void ExecuteQueue()
{
	//Problem_2075();
	//Problem_18258();
	//Problem_1039_Tester();
	//Problem_1039();
}