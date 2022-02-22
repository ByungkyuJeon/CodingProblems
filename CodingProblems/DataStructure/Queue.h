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

// PROBLEM 2164
/*
void Problem_2164()
{
	int N;
	std::cin >> N;
	std::queue<int> data;
	for (int num = 1; num <= N; num++)
	{
		data.emplace(num);
	}
	while (data.size() != 1)
	{
		data.pop();
		data.emplace(data.front());
		data.pop();
	}

	std::cout << data.front();
}
*/

// PROBLEM 11866
/*
void Problem_11866()
{
	int N, K;
	std::cin >> N >> K;
	std::string outputStr = "<";
	std::queue<int> data;
	for (int num = 1; num <= N; num++) { data.emplace(num); }
	int itrCount;
	while (data.size() != 1)
	{
		if(K <= data.size()) { itrCount = K; }
		else{ itrCount = (K % data.size()) + data.size(); }

		for (int cnt = 1; cnt < itrCount; cnt++)
		{
			data.emplace(data.front());
			data.pop();
		}
		outputStr += std::to_string(data.front()) + ", ";
		data.pop();
	}
	outputStr += std::to_string(data.front()) += ">";

	std::cout << outputStr;
}
*/

// PROBLEM 1966
/*
void Problem_1966()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string outputStr;
	int N, T, M, input, count;
	std::cin >> T;
	while (T-- > 0)
	{
		std::cin >> N >> M;
		std::queue<std::pair<int, int>> ret;
		std::priority_queue<int> data;
		for (int idx = 0; idx < N; idx++)
		{
			std::cin >> input;
			data.emplace(input);
			ret.emplace(std::make_pair(input, idx));
		}
		count = 0;
		while (true)
		{
			if (data.top() != ret.front().first)
			{
				ret.emplace(ret.front());
				ret.pop();
			}
			else
			{
				count++;
				data.pop();
				if (ret.front().second == M)
				{
					outputStr += std::to_string(count) + '\n';
					break;
				}
				ret.pop();
			}
		}
	}

	std::cout << outputStr;
}
*/

// PROBLEM 10866
/*
void Problem_10866()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, inputBuffer;
	std::cin >> N;
	std::string inputStr, outputStr;
	std::deque<int> data;
	while (N-- > 0)
	{
		std::cin >> inputStr;
		if (inputStr == "push_front")
		{
			std::cin >> inputBuffer;
			data.emplace_front(inputBuffer);
		}
		else if (inputStr == "push_back")
		{
			std::cin >> inputBuffer;
			data.emplace_back(inputBuffer);
		}
		else if (inputStr == "pop_front")
		{
			if (data.empty()){ outputStr += std::to_string(-1) + '\n'; }
			else { outputStr += std::to_string(data.front()) + '\n'; data.pop_front(); }
		}
		else if (inputStr == "pop_back")
		{
			if (data.empty()) { outputStr += std::to_string(-1) + '\n'; }
			else { outputStr += std::to_string(data.back()) + '\n'; data.pop_back();}
		}
		else if (inputStr == "size")
		{
			outputStr += std::to_string(data.size()) + '\n';
		}
		else if (inputStr == "empty")
		{
			if (data.empty()) { outputStr += std::to_string(1) + '\n'; }
			else { outputStr += std::to_string(0) + '\n'; }
		}
		else if (inputStr == "front")
		{
			if (data.empty()) { outputStr += std::to_string(-1) + '\n'; }
			else { outputStr += std::to_string(data.front()) + '\n'; }
		}
		else if (inputStr == "back")
		{
			if (data.empty()) { outputStr += std::to_string(-1) + '\n'; }
			else { outputStr += std::to_string(data.back()) + '\n'; }
		}
	}

	std::cout << outputStr;
}
*/

// PROBLEM 1021
/*
bool outs[51];

int getDistance(int start, int dest, int max)
{
	int ldist = 0, rdist = 0;
	for (int num = start;; num++)
	{
		if (num > max) { num = 1; }
		if (num == dest) { break; }
		if (outs[num]) { continue; }
		ldist++;
	}

	for (int num = start;; num--)
	{
		if (num < 1) { num = max; }
		if (num == dest) { break; }
		if (outs[num]) { continue; }
		rdist++;
	}

	return ldist < rdist ? ldist : -rdist;
}

void Problem_1021()
{
	int N, M;
	std::cin >> N >> M;
	std::vector<int> data(M);
	for (int idx = 0; idx < M; idx++)
	{
		std::cin >> data[idx];
	}
	std::deque<int> dataQueue;
	for (int num = 1; num <= N; num++)
	{
		dataQueue.emplace_back(num);
	}
	int currentPos = 1, dist, currIdx = 0, result = 0;

	while (M-- > 0)
	{
		dist = getDistance(currentPos, data[currIdx++], N);
		while (dist != 0)
		{
			result++;
			if (dist > 0)
			{
				dataQueue.emplace_back(dataQueue.front());
				dataQueue.pop_front(); dist--;
			}
			else
			{
				dataQueue.emplace_front(dataQueue.back());
				dataQueue.pop_back(); dist++;
			}
		}
		outs[dataQueue.front()] = true;
		dataQueue.pop_front();
		if (dataQueue.empty()) { break; }
		currentPos = dataQueue.front();
	}

	std::cout << result;
}
*/

// PROBLEM 5430

void Problem_5430()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	
	int T;
	std::cin >> T;

	std::string funcStr, numStr, temp, outputStr;
	std::deque<int> data; bool isError = false, direction = false;
	int numCount;
	while (T-- > 0)
	{
		std::cin >> funcStr >> numCount >> numStr;
		data.clear(); direction = false; isError = false;
		for (int idx = 0; idx < numStr.size(); idx++)
		{
			if ((numStr[idx] == ',' || numStr[idx] == ']') && !temp.empty())
			{
				data.emplace_back(std::stoi(temp));
				temp.clear();
			}
			else if (numStr[idx] >= '0' && numStr[idx] <= '9')
			{
				temp += numStr[idx];
			}
		}

		for (const auto& func : funcStr)
		{
			if (func == 'R'){ direction = !direction; }
			else
			{
				if (data.empty()) { isError = true; break; }
				if (direction){ data.pop_back(); }
				else{ data.pop_front(); }
			}
		}

		if (isError) { outputStr += "error\n"; continue; }
		outputStr += '[';
		while (data.size() > 1)
		{
			if (direction)
			{
				outputStr += std::to_string(data.back()) + ',';
				data.pop_back();
			}
			else
			{
				outputStr += std::to_string(data.front()) + ',';
				data.pop_front();
			}
		}
		if (!data.empty()) { outputStr += std::to_string(data.front()); }
		outputStr += "]\n";
	}

	std::cout << outputStr;
}

void ExecuteQueue()
{
	//Problem_2075();
	//Problem_18258();
	//Problem_1039_Tester();
	//Problem_1039();
	//Problem_2164();
	//Problem_11866();
	//Problem_1966();
	//Problem_10866();
	//Problem_1021();
	Problem_5430();
}