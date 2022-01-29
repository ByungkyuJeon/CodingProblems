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
/*
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
*/

// PROBLEM 1467
/*
bool skipIndices[1001];
int countArr[10];
std::string origin, target, result;

void Problem_1467_trial_1()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::unordered_map<char, std::vector<int>> fastTable;
	std::cin >> origin >> target;

	for (int idx = 0; idx < target.size(); idx++)
	{
		countArr[target[idx] - '0']--;
	}

	for (int idx = 0; idx < origin.size(); idx++)
	{
		countArr[origin[idx] - '0']++;
		fastTable[origin[idx]].emplace_back(idx);
	}

	int indexBuffer = -1;
	bool checker = false;
	for (char charVal = '9'; charVal >= '0'; charVal--)
	{
		if (fastTable[charVal].size() > 0 && countArr[charVal - '0'] == fastTable[charVal].size())
		{
			checker = false;
			for (const auto& elem : fastTable[charVal])
			{
				//if (!checker && elem > indexBuffer) { indexBuffer = elem; checker = true; }
				skipIndices[elem] = true;
			}
		}
		else if (countArr[charVal - '0'] > 0)
		{
			checker = false;
			for (const auto& elem : fastTable[charVal])
			{
				if (elem > indexBuffer)
				{
					if (!checker) { indexBuffer = elem; checker = true; }
					countArr[charVal - '0']--;
					skipIndices[elem] = true;
				}

				if (countArr[charVal - '0'] == 0) { break; }
			}
			if ((countArr[charVal - '0'] > 0))
			{
				for (int idx = fastTable[charVal].size() - 1; idx >= 0; idx--)
				{
					if (!skipIndices[fastTable[charVal][idx]])
					{
						//indexBuffer = fastTable[charVal][idx];
						skipIndices[fastTable[charVal][idx]] = true;
						countArr[charVal - '0']--;
					}
					if (countArr[charVal - '0'] == 0) { break; }
				}
			}
		}
	}



	for (int idx = 0; idx < origin.size(); idx++)
	{
		if (skipIndices[idx]) { result += origin[idx]; }
	}

	std::cout << result;
}

int getIndex(int start, bool direc)
{
	if (direc)
	{
		for (int idx = start + 1; idx < origin.size(); idx++)
		{
			if (!skipIndices[idx])
			{
				return idx;
			}
		}
		for (int idx = start - 1; idx >= 0; idx--)
		{
			if (!skipIndices[idx])
			{
				return idx;
			}
		}
	}
	else
	{
		for (int idx = start - 1; idx >= 0; idx--)
		{
			if (!skipIndices[idx])
			{
				return idx;
			}
		}
		for (int idx = start + 1; idx < origin.size(); idx++)
		{
			if (!skipIndices[idx])
			{
				return idx;
			}
		}
	}

	return start;
}

struct comp_1467
{
	bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
	{	
		if (lhs.second == rhs.second) { return lhs.first > rhs.first; }

		if (lhs.first < rhs.first)
		{
			if (lhs.second <= 0) { return true; }
			else if (lhs.second == 0) { return rhs.second < 0; }
			return false;
		}
		else
		{
			if (rhs.second <= 0) { return false; }
			else if (rhs.second == 0) { return lhs.second > 0; }
			return true;
		}
	}
};

void Print()
{
	std::string str;
	for (int idx = 0; idx < origin.size(); idx++)
	{
		if (!skipIndices[idx]) { str += origin[idx]; }
	}
	std::cout << str << '\n';
}

void Problem_1467()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::unordered_map<char, std::vector<int>> fastTable;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp_1467> pickerQueue;
	std::cin >> origin >> target;

	for (int idx = 0; idx < origin.size(); idx++)
	{
		fastTable[origin[idx]].emplace_back(idx);
	}

	std::sort(target.begin(), target.end());

	int indexBuffer;
	for (int idx = 0; idx < target.size(); idx++)
	{
		for (int tableIdx = 0; tableIdx < fastTable[target[idx]].size(); tableIdx++)
		{
			indexBuffer = fastTable[target[idx]][tableIdx];
			if (skipIndices[indexBuffer]) { continue; }

			pickerQueue.emplace(std::make_pair(indexBuffer, origin[getIndex(indexBuffer, true)] - origin[indexBuffer]));
		}

		skipIndices[pickerQueue.top().first] = true;
		std::cout << target[idx] << " " << pickerQueue.top().first << " ";
		pickerQueue = std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp_1467>();
		Print();
	}

	for (int idx = 0; idx < origin.size(); idx++)
	{
		if (!skipIndices[idx]) { result += origin[idx]; }
	}

	std::cout << result;
}

std::string originStr, substractStr, resultStr;
int subCount[100], mainCount[100], mainIdxCount[1001];

std::pair<int, char> process(int idx) 
{
	int copiedSubStrCount[100];

	std::pair<int, int>result = std::make_pair(idx, originStr[idx]);

	for (int countIdx = 0; countIdx < 100; countIdx++)
	{
		copiedSubStrCount[countIdx] = subCount[countIdx];
	}

	while (copiedSubStrCount[originStr[idx]])
	{
		if (originStr[idx] > result.second && copiedSubStrCount[originStr[idx]] < mainIdxCount[idx])
		{
			result = { idx,originStr[idx] };
		}
		copiedSubStrCount[originStr[idx++]]--;
	}
	if (originStr[idx] > result.second && copiedSubStrCount[originStr[idx]] < mainIdxCount[idx])
	{
		result = { idx,originStr[idx] };
	}
	return result;
}

void Problem_1467_Study() 
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int processIdx = 0;
	std::cin >> originStr >> substractStr;

	for (int originIdx = originStr.size() - 1; originIdx >= 0; originIdx--)
	{
		mainIdxCount[originIdx] = ++mainCount[originStr[originIdx]];
	}

	for (const auto& elem : substractStr)
	{
		subCount[elem]++;
	}

	while (processIdx < originStr.size())
	{
		if (subCount[originStr[processIdx]] == 0)
		{
			resultStr.push_back(originStr[processIdx++]);
		}
		else if (subCount[originStr[processIdx]] == mainIdxCount[processIdx])
		{
			subCount[originStr[processIdx++]]--;
		}
		else 
		{
			auto dest = process(processIdx);
			for (int idx = processIdx; idx < dest.first; idx++)
			{
				subCount[originStr[idx]]--;
			}
			processIdx = dest.first + 1;
			resultStr.push_back(dest.second);
		}
	}
	std::cout << resultStr;
}
*/

// PROBLEM 1026
/*
int A[51], B[51];

void Problem_1026()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int N, result = 0;
	std::cin >> N;

	for (int count = 0; count < N; count++)
	{
		std::cin >> A[count];
	}

	for (int count = 0; count < N; count++)
	{
		std::cin >> B[count];
	}

	std::sort(A, A + N);
	std::sort(B, B + N, [](const int& lhs, const int& rhs) {return lhs > rhs; });

	for (int idx = 0; idx < N; idx++)
	{
		result += A[idx] * B[idx];
	}

	std::cout << result;
}
*/

// PROBLEM 1052
/*
void Problem_1052()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int preprocessed[26];

	preprocessed[0] = 1;
	for (int count = 1; count < 25; count++)
	{
		preprocessed[count] = preprocessed[count - 1] * 2;
	}

	int N, K, prevNum = 24, result;
	std::cin >> N >> K;

	if (N <= K) { std::cout << 0; }
	else
	{
		while (K-- > 0)
		{
			for (int count = prevNum - 1; count >= 0; count--)
			{
				if (N >= preprocessed[count])
				{
					prevNum = count;
					N -= preprocessed[count];
					break;
				}
			}
			if (N == 0) { break; }
		}
		if (K >= 0 || N == 0) { std::cout << 0; }
		else
		{
			result = preprocessed[prevNum] - N;

			std::cout << result;
		}
	}
}
*/

// PROBLEM 1041
/*
void Problem_1041()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int data[6];
	int mins[3]{ INT_MAX, INT_MAX, INT_MAX };

	int N;
	std::cin >> N;

	for (int idx = 0; idx < 6; idx++) { std::cin >> data[idx]; }

	if (N == 1)
	{
		std::sort(data, data + 6);
		int result = 0;
		for (int idx = 0; idx < 5; idx++) { result += data[idx]; }
		std::cout << result;
	}
	else
	{
		for (int outerIdx = 0; outerIdx < 6; outerIdx++)
		{
			if (mins[0] > data[outerIdx]) { mins[0] = data[outerIdx]; }
			for (int innerIdx = 0; innerIdx < 6; innerIdx++)
			{
				if (innerIdx != outerIdx && innerIdx != 5 - outerIdx && mins[1] > data[outerIdx] + data[innerIdx]) { mins[1] = data[outerIdx] + data[innerIdx]; }
				for (int deeperIdx = 0; deeperIdx < 6; deeperIdx++)
				{
					if (outerIdx != innerIdx && deeperIdx != outerIdx && deeperIdx != innerIdx && innerIdx != 5 - outerIdx && deeperIdx != 5 - outerIdx && deeperIdx != 5 - innerIdx && mins[2] > data[outerIdx] + data[innerIdx] + data[deeperIdx])
					{
						mins[2] = data[outerIdx] + data[innerIdx] + data[deeperIdx];
					}
				}
			}
		}

		std::cout << ((((long long)(N - 2) * (N - 2) * 5) + ((N - 2) * 4)) * mins[0]) + ((((long long)(N - 2) * 8) + 4) * mins[1]) + (4 * mins[2]);
	}

}
*/

// PROBLEM 1036
/*
struct dataComp
{
	dataComp() = default;
	dataComp(char inCharac, double inValue) : charac{ inCharac }, value{ inValue }{}

	char charac;
	double value;

	bool operator()(const dataComp& lhs, const dataComp& rhs)
	{
		return lhs.value < rhs.value;
	}
};

void Problem_1036_trial()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long long sum = 0;
	std::string result;
	int buffer;
	std::string data[50];
	std::vector<char> changeChars;
	std::unordered_set<int> summedIndices;
	double sums[37];
	memset(sums, 0, sizeof(double) * 36);
	std::priority_queue<dataComp, std::vector< dataComp>, dataComp> maxElemQueue;
	double nums[50];

	nums[0] = 1;
	for (int idx = 1; idx < 50; idx++)
	{
		nums[idx] = nums[idx - 1] * 36.0;
	}

	int N, K;
	std::cin >> N;
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> data[idx];
	}
	std::cin >> K;

	for (int idx = 0; idx < N; idx++)
	{
		buffer = data[idx].size();
		for (int charIdx = 0; charIdx < buffer; charIdx++)
		{
			if (data[idx][charIdx] >= 'A')
			{
				summedIndices.emplace(data[idx][charIdx] - 'A' + 10);
				sums[data[idx][charIdx] - 'A' + 10] += nums[buffer - charIdx - 1] * ('Z' - data[idx][charIdx]);
			}
			else
			{
				summedIndices.emplace(data[idx][charIdx] - '0');
				sums[data[idx][charIdx] - '0'] += nums[buffer - charIdx - 1] * (35 - (data[idx][charIdx] - '0'));
			}
		}
	}

	for (const auto& elem : summedIndices)
	{
		if (elem >= 10)
		{
			maxElemQueue.push(dataComp(elem + 55, sums[elem]));
		}
		else
		{
			maxElemQueue.push(dataComp(elem + '0', sums[elem]));
		}
	}

	for (int count = 0; count < K; count++)
	{
		if (maxElemQueue.empty()) { break; }
		if (std::find(changeChars.begin(), changeChars.end(), maxElemQueue.top().charac) == changeChars.end())
		{
			changeChars.emplace_back(maxElemQueue.top().charac);
		}
		maxElemQueue.pop();
	}

	for (int idx = 0; idx < N; idx++)
	{
		buffer = data[idx].size();
		for (int charIdx = 0; charIdx < buffer; charIdx++)
		{
			if (std::find(changeChars.begin(), changeChars.end(), data[idx][charIdx]) != changeChars.end())
			{
				data[idx][charIdx] = 'Z';
			}

			if (data[idx][charIdx] >= 'A')
			{
				sum += nums[buffer - charIdx - 1] * (data[idx][charIdx] - 'A' + 10);
			}
			else
			{
				sum += nums[buffer - charIdx - 1] * (data[idx][charIdx] - '0');
			}
		}
	}

	while (true)
	{
		buffer = sum % 36;
		if (buffer >= 10) 
		{
			result += buffer + 55;
		}
		else
		{
			result += std::to_string(buffer);
		}
		if (sum < 36) { break; }
		sum /= 36;
	}

	for (int idx = 0; idx < result.size() / 2; idx++)
	{
		std::swap(result[idx], result[result.size() - 1 - idx]);
	}

	std::cout << result;
}

void addAsString(std::string& outStr, std::string& operandStr)
{
	for (int idx = 0; idx < operandStr.size() / 2; idx++)
	{
		std::swap(operandStr[idx], operandStr[operandStr.size() - 1 - idx]);
	}

	int lhsVal, rhsVal, subBuffer;
	subBuffer = outStr.size() - operandStr.size();
	if (subBuffer < 0)
	{
		while (subBuffer++ < 0)
		{
			outStr += '0';
		}
	}
	else
	{
		while (subBuffer-- > 0)
		{
			operandStr += '0';
		}
	}
	int calLength = outStr.size();

	for (int idx = 0; idx < calLength; idx++)
	{
		if (outStr[idx] >= 'A') { lhsVal = outStr[idx] - 'A' + 10; }
		else { lhsVal = outStr[idx] - '0'; }

		if (operandStr[idx] >= 'A') { rhsVal = operandStr[idx] - 'A' + 10; }
		else { rhsVal = operandStr[idx] - '0'; }

		subBuffer = lhsVal + rhsVal;
		if (lhsVal + rhsVal > 35)
		{
			if ((subBuffer = idx + 1) == outStr.size()) { outStr += '0'; }
			while (true)
			{
				if (outStr[subBuffer] == 'Z')
				{
					outStr[subBuffer] = '0';
					if ((++subBuffer) == outStr.size()) { outStr += '0'; }
				}
				else if (outStr[subBuffer] == '9')
				{
					outStr[subBuffer] = 'A';
					break;
				}
				else
				{
					outStr[subBuffer]++;
					break;
				}
			}

			subBuffer = lhsVal + rhsVal - 36;
		}

		if (subBuffer >= 10)
		{
			outStr[idx] = subBuffer - 10 + 'A';
		}
		else
		{
			outStr[idx] = subBuffer + '0';
		}
	}
}

void Problem_1036()
{
	std::string result;
	int buffer;
	std::string data[50];
	std::vector<char> changeChars;
	std::unordered_set<int> summedIndices;
	double sums[37];
	memset(sums, 0, sizeof(double) * 36);
	std::priority_queue<dataComp, std::vector< dataComp>, dataComp> maxElemQueue;
	double nums[50];

	nums[0] = 1;
	for (int idx = 1; idx < 50; idx++)
	{
		nums[idx] = nums[idx - 1] * 36.0;
	}

	int N, K;
	std::cin >> N;
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> data[idx];
	}
	std::cin >> K;

	if (K != 0)
	{
		for (int idx = 0; idx < N; idx++)
		{
			buffer = data[idx].size();
			for (int charIdx = 0; charIdx < buffer; charIdx++)
			{
				if (data[idx][charIdx] >= 'A')
				{
					summedIndices.emplace(data[idx][charIdx] - 'A' + 10);
					sums[data[idx][charIdx] - 'A' + 10] += nums[buffer - charIdx - 1] * ('Z' - data[idx][charIdx]);
				}
				else
				{
					summedIndices.emplace(data[idx][charIdx] - '0');
					sums[data[idx][charIdx] - '0'] += nums[buffer - charIdx - 1] * (35 - (data[idx][charIdx] - '0'));
				}
			}
		}

		for (const auto& elem : summedIndices)
		{
			if (elem >= 10)
			{
				maxElemQueue.push(dataComp(elem + 55, sums[elem]));
			}
			else
			{
				maxElemQueue.push(dataComp(elem + '0', sums[elem]));
			}
		}

		for (int count = 0; count < K; count++)
		{
			if (maxElemQueue.empty()) { break; }
			if (std::find(changeChars.begin(), changeChars.end(), maxElemQueue.top().charac) == changeChars.end())
			{
				changeChars.emplace_back(maxElemQueue.top().charac);
			}
			maxElemQueue.pop();
		}

		for (int idx = 0; idx < N; idx++)
		{
			buffer = data[idx].size();
			for (int charIdx = 0; charIdx < buffer; charIdx++)
			{
				if (std::find(changeChars.begin(), changeChars.end(), data[idx][charIdx]) != changeChars.end())
				{
					data[idx][charIdx] = 'Z';
				}
			}
		}
	}

	for (int idx = 0; idx < N; idx++)
	{
		addAsString(result, data[idx]);
	}

	for (int idx = 0; idx < result.size() / 2; idx++)
	{
		std::swap(result[idx], result[result.size() - 1 - idx]);
	}

	if (result.size() == 0) { std::cout << '0'; }
	else { std::cout << result; }
}
*/

// PROBLEM 1161
/*
struct Data
{
	Data() = default;
	Data(int inStart, int inEnd, int inNum) : start{ inStart }, end{ inEnd }, num{ inNum }{}

	int start;
	int end;
	int num;
};

struct compEnd
{
	bool operator()(const Data& lhs, const Data& rhs)
	{
		return  lhs.end > rhs.end;
	}
};

struct compStart
{
	bool operator()(const Data& lhs, const Data& rhs)
	{
		return  lhs.start > rhs.start;
	}
};

void Problem_1161_Trial()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	// 아직 도착하지 않아, 시작 지점이 중요
	std::priority_queue<Data, std::vector<Data>, compStart> startQueue; // 최소 힙
	// 이미 시작점을 들렸기 때문에 끝나는 지점이 중요
	std::priority_queue<Data, std::vector<Data>, compEnd> endQueue; // 최소 힙

	int K, N, C, buffer[3];
	std::cin >> K >> N >> C;
	for(int idx = 0; idx < K; idx++)
	{
		std::cin >> buffer[0] >> buffer[1] >> buffer[2];
		// 아직 들르지 않은 모든 정류장 히피파이
		startQueue.emplace(std::move(Data(buffer[0], buffer[1], buffer[2])));
	}

	buffer[0] = 0; // 현재 태운 인원 수
	buffer[1] = 0; // 누적 인원 수

	// 들르지 않은 정류장이 없을 때까지 반복
	while (!startQueue.empty())
	{
		if (endQueue.empty()) // 아무도 타고 있지 않은 경우
		{
			buffer[0] += startQueue.top().num;
			buffer[1] += startQueue.top().num;
			endQueue.emplace(std::move(Data(startQueue.top())));
			startQueue.pop();
		}
		else // 누가 타고 있는 경우
		{
			if (endQueue.top().end > startQueue.top().start) // 다음 정류장과 겹치는 경우
			{
				if(buffer[0] == C){ startQueue.pop(); } // 최대 인원수 수용중이라 승차 거부
				else if (buffer[0] + startQueue.top().num > C) // 전부 태울 수 없어, 일부만 태움
				{
					endQueue.emplace(std::move(Data(startQueue.top().start, startQueue.top().end, C - buffer[0])));
					buffer[1] += (C - buffer[0]);
					buffer[0] = C;
					startQueue.pop();
				}
				else // 전부 태울 수 있음
				{
					endQueue.emplace(std::move(Data(startQueue.top())));
					buffer[0] += startQueue.top().num;
					buffer[1] += startQueue.top().num;
					startQueue.pop();
				}
			}
			else // 다음 정류장과 겹치지 않아, 사람들이 내림
			{
				buffer[0] -= endQueue.top().num;
				endQueue.pop();
			}
		}
		std::cout << " result : " << buffer[1] << " out : " << endQueue.top().end << '\n';
	}

	std::cout << buffer[1];
}

void Problem_1161_Final()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::priority_queue<Data, std::vector<Data>, compStart> startQueue;
	std::map<int, int> minmaxMap;

	int K, N, C, buffer[3];
	std::cin >> K >> N >> C;
	for (int idx = 0; idx < K; idx++)
	{
		std::cin >> buffer[0] >> buffer[1] >> buffer[2];
		startQueue.emplace(std::move(Data(buffer[0], buffer[1], buffer[2])));
	}

	buffer[0] = 0;
	buffer[1] = 0;
	std::map<int, int>::iterator Itr;

	while (!startQueue.empty())
	{
		if (minmaxMap.empty())
		{
			minmaxMap[startQueue.top().end] += startQueue.top().num;
			buffer[0] += startQueue.top().num;
			buffer[1] += startQueue.top().num;
			startQueue.pop();
		}
		else
		{
			if (minmaxMap.begin()->first > startQueue.top().start)
			{
				if (buffer[0] + startQueue.top().num > C)
				{
					if (buffer[0] != C)
					{
						buffer[1] += (C - buffer[0]);
					}

					buffer[0] += startQueue.top().num;
					minmaxMap[startQueue.top().end] += startQueue.top().num;
					Itr = --minmaxMap.end();
					while (true)
					{
						if (buffer[0] - Itr->second >= C)
						{
							buffer[0] -= Itr->second;
							minmaxMap.erase(Itr--);
						}
						else
						{
							Itr->second -= buffer[0] - C;
							break;
						}
					}

					buffer[0] = C;
					startQueue.pop();
				}
				else
				{
					minmaxMap[startQueue.top().end] += startQueue.top().num;
					buffer[0] += startQueue.top().num;
					buffer[1] += startQueue.top().num;
					startQueue.pop();
				}
			}
			else
			{
				buffer[0] -= minmaxMap.begin()->second;
				minmaxMap.erase(minmaxMap.begin());
			}
		}
	}

	std::cout << buffer[1];
}

struct group
{
	int M;
	int S;
	int E;

	bool operator<(const group& b) const
	{
		return S < b.S;
	}
};

// USACO 공식 해답
void Problem_1161_Official()
{
	int K, N, C;
	int ans = 0;

	std::cin >> K >> N >> C;
	std::vector<group> groups(K);
	for (int i = 0; i < K; i++)
		std::cin >> groups[i].S >> groups[i].E >> groups[i].M;

	std::sort(groups.begin(), groups.end());

	std::map<int, int> off;
	int total = 0;
	// 시작점이 가장 작은 그룹부터 iterate
	for (int i = 0; i < K; i++)
	{
		// 시작 지점 
		int pos = groups[i].S;
		std::map<int, int>::iterator offItr = off.begin();
		// 이전 끝점보다 다음 시작점이 클 때
		while (offItr != off.end() && offItr->first <= pos)
		{
			// 누적 인원 수
			ans += offItr->second;
			// 현재 인원 수
			total -= offItr->second;
			off.erase(offItr++);
		}


		// 끝점에 인원수 저장
		off[groups[i].E] += groups[i].M;
		// 현재 인원 수
		total += groups[i].M;
		// Itr 끝으로 이동
		offItr = off.end();
		// 유효 Itr 로 한칸 이동
		--offItr;
		// 현재 인원 수가 제한을 넘을 때
		while (total > C)
		{
			// 마지막 그룹의 인원수가 제한 인원 수를 넘기거나 걸칠 때
			if (total - offItr->second >= C)
			{
				// 그룹 인원 수 제거
				total -= offItr->second;
				// 그룹 제거
				off.erase(offItr--);
			}
			else
			{
				// 그룹 인원 수 부분 수용
				offItr->second -= total - C;
				total = C;
			}
		}
	}
	ans += total;
	std::cout << ans << "\n";
}
*/

void ExecuteGreedy()
{
	//Problem_1040();
	//Problem_23845();
	//Problem_1422();
	//Problem_1379();
	//Problem_1467();
	//Problem_1467_Study();
	//Problem_1026();
	//Problem_1052();
	//Problem_1041();
	//Problem_1036();
	//Problem_1161_Trial();
	//Problem_1161_Final();
	//Problem_1161_Official();
}