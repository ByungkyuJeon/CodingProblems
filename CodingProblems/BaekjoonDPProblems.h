#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

// PROBLEM 2839
/*
int DP_2839(std::unordered_map<int, int>& inLookupTable, int inNum)
{
	if (inNum == 0) { return 0; }
	else if (inNum < 0) { return INT_MAX; }

	auto itr = inLookupTable.find(inNum);
	if (itr != inLookupTable.end())
	{
		return itr->second;
	}

	if ((inLookupTable[inNum] = std::min(DP_2839(inLookupTable, inNum - 3), DP_2839(inLookupTable, inNum - 5))) != INT_MAX)
	{
		inLookupTable[inNum]++;
	}

	return inLookupTable[inNum];
}

void Problem_2839()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, result;
	std::cin >> N;
	std::unordered_map<int, int> lookupTable
	{
		{1, INT_MAX},
		{2, INT_MAX},
		{3, 1},
		{4, INT_MAX},
		{5, 1}
	};

	if ((result = DP_2839(lookupTable, N)) == INT_MAX)
	{
		std::cout << -1;
	}
	else { std::cout << result; }
}
*/

// PROBLEM 9184
/*
struct Data 
{ 
	Data() = default;
	Data(int a, int b, int c) : mA{ a }, mB{ b }, mC{ c }{}
	int mA, mB, mC;

	std::size_t operator()(const Data& data) const noexcept
	{
		return (data.mA + 100) * 1000000 + (data.mB + 100) * 10000 + (data.mC + 100);
	}

	bool operator==(const Data& other) const noexcept
	{
		return this->mA == other.mA && this->mB == other.mB && this->mC == other.mC;
	}
};

std::unordered_map <Data, long long, Data> lookupTable;

long long proc(int a, int b, int c)
{
	Data temp = Data(a, b, c);
	if (lookupTable.find(temp) != lookupTable.end()) { return lookupTable[temp]; }
	if (a <= 0 || b <= 0 || c <= 0) { return (lookupTable[temp] = 1); }
	if (a > 20 || b > 20 || c > 20) { return (lookupTable[temp] = proc(20, 20, 20)); }
	if (a < b && b < c) { return (lookupTable[temp] = proc(a, b, c - 1) + proc(a, b - 1, c - 1) - proc(a, b - 1, c)); }
	return (lookupTable[temp] = proc(a - 1, b, c) + proc(a - 1, b - 1, c) + proc(a - 1, b, c - 1) - proc(a - 1, b - 1, c - 1));
}

void Problem_9184()
{
	std::string outputStr;
	int inputs[3];
	while (true)
	{
		std::cin >> inputs[0] >> inputs[1] >> inputs[2];
		if (inputs[0] == -1 && inputs[1] == -1 && inputs[2] == -1)
		{
			break;
		}
		outputStr += "w(" + std::to_string(inputs[0]) + ", "
			+ std::to_string(inputs[1]) + ", "
			+ std::to_string(inputs[2]) + ")"
			+ " = "
			+ std::to_string(proc(inputs[0], inputs[1], inputs[2])) + '\n';
	}
	std::cout << outputStr;
}
*/

// PROBLEM 1904
/*
void Problem_1904()
{
	int N, buffer[3]{1, 1, 1}, currentIdx = 0;
	std::cin >> N;
	for (int num = 1; num < N; num++)
	{
		switch (currentIdx)
		{
		case 0:
			buffer[0] = (buffer[1] + buffer[2]) % 15746;
			break;
		case 1:
			buffer[1] = (buffer[0] + buffer[2]) % 15746;
			break;
		case 2:
			buffer[2] = (buffer[1] + buffer[0]) % 15746;
			break;
		default:
			break;
		}
		if (num == N - 1) { break; }
		if (++currentIdx > 2) { currentIdx = 0; }
	}

	std::cout << buffer[currentIdx];
}
*/

// PRBOELM 9461
/*
long long getNum(long long* arr, int idx)
{
	int prevIdx = idx - 1;
	if (prevIdx < 0) { prevIdx = 4; }
	return arr[idx] + arr[prevIdx];
}

void Problem_9461()
{
	std::string outputStr;
	long long data[5]{ 1, 1, 1, 2, 2 };
	int currIdx = 0;
	int T, N;
	std::cin >> T;
	while (T-- > 0)
	{
		std::cin >> N;
		data[0] = 1; data[1] = 1; data[2] = 1; data[3] = 2; data[4] = 2;
		currIdx = 0;
		if (N <= 5) { outputStr += std::to_string(data[N - 1]) + '\n'; }
		else
		{
			N -= 5;
			for (int count = 0; count < N; count++)
			{
				data[currIdx] = getNum(data, currIdx);
				if (count == N - 1) { break; }
				if (++currIdx > 4) { currIdx = 0; }
			}
			outputStr += std::to_string(data[currIdx]) + '\n';
		}
	}
	std::cout << outputStr;
}
*/

// PROBLEM 1149
/*
struct Data
{ 
	int mColor[3];

	size_t operator()(const std::pair<int, int>& obj) const noexcept
	{
		return (obj.first * 1000 << 2) + obj.second;
	}
};

std::unordered_map<std::pair<int, int>, long long, Data> lookTable;
Data data[1000];
int N;

long long process(int idx, int prevColor)
{
	if (idx == N){ return 0; }
	std::pair<int, int> pairTemp = std::make_pair(idx, prevColor);
	std::unordered_map<std::pair<int, int>, long long, Data>::iterator itr;
	if ((itr = lookTable.find(pairTemp)) != lookTable.end())
	{
		return itr->second;
	}

	long long min = 9999999999999, tempVal;
	for (int colorIdx = 0; colorIdx < 3; colorIdx++)
	{
		if (colorIdx != prevColor)
		{
			if (min > (tempVal = process(idx + 1, colorIdx) + data[idx].mColor[colorIdx]))
			{
				min = tempVal;
			}
		}
	}

	lookTable[pairTemp] = min;
	return min;
}

void Problem_1149()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N;
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> data[idx].mColor[0] >> data[idx].mColor[1] >> data[idx].mColor[2];
	}
	std::cout << process(0, -1);
}
*/

// PROBLEM 1932
/*
int N;
int data[125250];
std::unordered_map<int, int> dpTable;

int getBaseIdx(int height)
{
	return (height * (height + 1)) / 2;
}

long long process(int height, int baseIdx, int idx)
{
	if (height == N - 1) { return data[idx]; }
	if (dpTable.find(idx) != dpTable.end()){ return dpTable[idx]; }

	int nxtBase = getBaseIdx(height + 1);
	int lhsIdx = nxtBase + (idx - baseIdx);
	long long lhs = process(height + 1, nxtBase, lhsIdx), rhs = process(height + 1, nxtBase, lhsIdx + 1);
	dpTable[idx] = (lhs > rhs ? lhs : rhs) + data[idx];
	return dpTable[idx];
}

void Problem_1932()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int lastIdx;
	std::cin >> N;
	lastIdx = getBaseIdx(N) - 1;
	for (int idx = 0; idx <= lastIdx; idx++)
	{
		std::cin >> data[idx];
	}

	std:: cout << process(0, 0, 0);

}
*/

// PROBLEM 2579
/*
int N;
int data[301];
std::unordered_map<int, int> table[2];

long long process(int num, int isContinued)
{
	if (num == N) { return data[num]; }
	if (num > N) { return INT_MIN; }
	if (table[isContinued].find(num) != table[isContinued].end()) { return table[isContinued][num]; }

	int lhs = INT_MIN;
	if (isContinued == 0)
	{
		if(num != 0){ lhs = process(num + 1, 1); }
		else { lhs = process(num + 1, 0); }
	}
	int rhs = process(num + 2, 0);
	table[isContinued][num] = (lhs > rhs ? lhs : rhs) + data[num];
	return table[isContinued][num];
}

void Problem_2579()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N;
	for (int idx = 1; idx <= N; idx++)
	{
		std::cin >> data[idx];
	}
	std::cout << process(0, 0);
	std::cout << std::endl;
}
*/

// PROBLEM 10844
/*
struct Data
{
	Data() = default;
	Data(int digit, int num) : mDigit{ digit }, mNum{ num }{}

	int mDigit, mNum;

	bool operator==(const Data& other) const
	{
		return this->mDigit == other.mDigit && this->mNum == other.mNum;
	}

	size_t operator()(const Data& obj) const noexcept
	{
		return (obj.mDigit * 1000) + obj.mNum;
	}
};

int N;
std::unordered_map<Data, int, Data> dpTable;

int process(int digit, int prev)
{
	if (digit > N) { return 1; }
	Data temp{ digit, 0 };
	int sum = 0;
	if ((temp.mNum = prev - 1) >= 0)
	{
		if (dpTable.find(temp) != dpTable.end()) { sum = ((long long)sum + dpTable[temp]) % 1000000000; }
		else { sum = ((long long)sum + (dpTable[temp] = process(digit + 1, temp.mNum)) % 1000000000); }
	}
	if ((temp.mNum = prev + 1) <= 9)
	{
		if (dpTable.find(temp) != dpTable.end()) { sum = ((long long)sum + dpTable[temp]) % 1000000000; }
		else { sum = ((long long)sum + (dpTable[temp] = process(digit + 1, temp.mNum)) % 1000000000); }
	}
	
	return sum;
}

void Problem_10844()
{
	std::cin >> N;
	int sum = 0;
	for (int num = 1; num < 10; num++)
	{
		sum = ((long long)sum + process(2, num)) % 1000000000;
	}
	std::cout << sum;
}
*/

// PROBLEM 2156
/*
int N;
int data[10001];
std::unordered_map<int, int> table[2];

long long process(int num, int isContinued)
{
	if (num == N) { return data[num]; }
	if (num > N) { return 0; }
	if (table[isContinued].find(num) != table[isContinued].end()) { return table[isContinued][num]; }

	int nums[3]{ INT_MIN , INT_MIN , INT_MIN };
	if (isContinued == 0)
	{
		if (num != 0) { nums[0] = process(num + 1, 1); }
		else { nums[0] = process(num + 1, 0); }
	}
	nums[1] = process(num + 2, 0);
	nums[2] = process(num + 3, 0);
	table[isContinued][num] = (*std::max_element(nums, nums + 3)) + data[num];
	return table[isContinued][num];
}

void Problem_2156()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N;
	for (int idx = 1; idx <= N; idx++)
	{
		std::cin >> data[idx];
	}
	std::cout << process(0, 0);
}
*/

// PROBLEM 11054
/*
int N, L = 0;
int data[1000];
int subsequence[1000];
int lengths[1000];


int binarySearch(int start, int end, int val)
{
	if (start == end) { int ret = val <= subsequence[start] ? start : start + 1; if (ret > L) { return ret - 1; } return ret; }
	int mid = (start + end) / 2;
	if (val > subsequence[mid]) { return binarySearch(mid + 1, end, val); }
	else { return binarySearch(start, mid, val); }
}

void Problem_11054()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N;
	std::cin >> data[0];
	subsequence[0] = data[0];
	int max = 1; bool isDoubled = false;
	for (int idx = 1; idx < N; idx++)
	{
		std::cin >> data[idx];
		if (subsequence[L] < data[idx])
		{
			subsequence[++L] = data[idx];
			lengths[idx] = L + 1;
			if (lengths[idx] > max) { max = lengths[idx]; }
		}
		else if (subsequence[L] == data[idx]) { lengths[idx] = L + 1; }
		else
		{
			subsequence[binarySearch(0, L, data[idx])] = data[idx];
		}
	}

	for (int idx = 0; idx < N / 2; idx++)
	{
		std::swap(data[idx], data[N - idx - 1]);
	}

	L = 0;
	subsequence[0] = data[0];
	for (int idx = 1; idx < N; idx++)
	{
		if (subsequence[L] < data[idx])
		{
			subsequence[++L] = data[idx];
			if (max < lengths[N - idx - 1] + L + 1) { max = lengths[N - idx - 1] + L + 1;  if (lengths[N - idx - 1] != 0) { isDoubled = true; } }
		}
		else
		{
			subsequence[binarySearch(0, L, data[idx])] = data[idx];
		}
	}

	if (isDoubled) { max--; }
	std::cout << max;
}
*/

// PROBLEM 1912
/*
int N;
int data[100001];
std::unordered_map<int, long long> dpTable;

long long process(int idx)
{
	if (idx == N) { return data[idx]; }
	else if (idx > N) { return -1; }
	if (dpTable.find(idx) != dpTable.end()) { return dpTable[idx]; }

	long long calculated = process(idx + 1);
	long long current = data[idx];
	dpTable[idx] = current > calculated + current ? current : calculated + current;
	return dpTable[idx];
}

void Problem_1912()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N;
	for (int idx = 1; idx <= N; idx++){ std::cin >> data[idx]; }
	long long max = LONG_MIN, temp;
	for (int idx = 1; idx <= N; idx++)
	{
		if ((temp = process(idx + 1)) < 0) { temp = data[idx]; }
		else { temp += data[idx]; }
		if (max < temp) { max = temp; }
	}

	std::cout << max;
}
*/
//

// PROBLEM 12865 
/*
struct Data
{
public:
	void sort()
	{
		std::sort(mData.begin(), mData.end(), [](const int& lhs, const int& rhs) {return lhs > rhs; });
	}
	int get() const
	{
		return mData[currentIdx];
	}
	std::vector<int> mData;
	size_t currentIdx = 0;
};

std::unordered_map<int, Data> data;
std::unordered_map<int, long long> dpTable;
std::vector<int> weights;

long long process(int weight)
{
	if (weight <= 0) { return 0; }
	if (dpTable.find(weight) != dpTable.end()) { return dpTable[weight]; }

	std::vector<long long> calculated; 
	long long temp;
	for (int start = (std::upper_bound(weights.begin(), weights.end(), weight) - weights.begin()) - 1; start >= 0; start--)
	{
		if (data[weights[start]].currentIdx != data[weights[start]].mData.size())
		{
			data[weights[start]].currentIdx++;
			temp = process(weight - weights[start]);
			data[weights[start]].currentIdx--;
			calculated.emplace_back(temp + data[weights[start]].get());
		}
	}
	if (calculated.size() > 0)
	{
		dpTable[weight] = *std::max_element(calculated.begin(), calculated.end());
		return dpTable[weight];
	}

	return 0;
}

void Problem_12865_Trial()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, K, inputBuffer[2];
	std::cin >> N >> K;
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> inputBuffer[0] >> inputBuffer[1];
		data[inputBuffer[0]].mData.emplace_back(inputBuffer[1]);
		weights.emplace_back(inputBuffer[0]);
	}
	for (auto& elem : data)
	{
		elem.second.sort();
	}

	std::sort(weights.begin(), weights.end());

	std::cout << process(K);
}
*/

// PROBLEM 12865

int dp[101][100001];

void Problem_12865()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, K, input[2], lhs, rhs;
	std::cin >> N >> K;

	for (int inputCount = 1; inputCount <= N; inputCount++)
	{
		std::cin >> input[0] >> input[1];
		for (int weightCount = 1; weightCount <= K; weightCount++)
		{
			if (input[0] > weightCount) { dp[inputCount][weightCount] = dp[inputCount - 1][weightCount]; continue; }
			lhs = input[1] + dp[inputCount - 1][weightCount - input[0]];
			rhs = dp[inputCount - 1][weightCount];
			dp[inputCount][weightCount] = lhs > rhs ? lhs : rhs;
		}
	}
	
	std::cout << dp[N][K];
}


void ExecuteDpProblems()
{
	//Problem_2839();
	//Problem_9184();
	//Problem_1904();
	//Problem_9461();
	//Problem_1149();
	//Problem_1932();
	//Problem_2579();
	//Problem_10844();
	//Problem_2156();
	//Problem_11054();
	//Problem_1912();
	//Problem_12865_Trial();
	Problem_12865();
}