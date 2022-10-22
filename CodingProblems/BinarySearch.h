#pragma once

#include <unordered_map>
#include <iostream>
#include <algorithm>

// PROBLEM 3020
/*
int lower_3020[500001];
int upper_3020[500001];
int total_3020[500001];

void Problem_3020()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, H, inputBuffer[2];
	std::cin >> N >> H;

	for (int i = 0; i < N; i += 2)
	{
		std::cin >> inputBuffer[0] >> inputBuffer[1];
		lower_3020[inputBuffer[0]]++;
		upper_3020[inputBuffer[1]]++;
	}

	for (int i = H - 2; i > 0; i--)
	{
		lower_3020[i] += lower_3020[i + 1];
	}

	total_3020[1] = lower_3020[1];
	total_3020[2] = upper_3020[H - 1] + lower_3020[2];
	for (int i = H - 2; i > 0; i--)
	{
		upper_3020[i] += upper_3020[i + 1];
		total_3020[H - i + 1] = upper_3020[i] + lower_3020[H - i + 1];
	}

	std::make_heap(&total_3020[1], &total_3020[H + 1], [](const int& lhs, const int& rhs) {return lhs > rhs; });
	inputBuffer[0] = total_3020[1];
	inputBuffer[1] = 0;
	int counter = 0;
	while (inputBuffer[0] == total_3020[1] && counter <= H)
	{
		inputBuffer[1]++;
		std::pop_heap(&total_3020[1], &total_3020[H + 1 - counter], [](const int& lhs, const int& rhs) {return lhs > rhs; });
		counter++;
	}

	std::cout << inputBuffer[0] << " " << inputBuffer[1] << '\n';
}
*/

// PROBLEM 2352
/*
int subsequence_2352[40001];

int binarySearch_2352(int start, int end, int val)
{
	if (start == end) { return subsequence_2352[start] >= val ? start : start + 1; }
	//if (start >= end) { return start; }
	int mid = start + (end - start) / 2;
	if (subsequence_2352[mid] == val) { return mid; }
	else if (val < subsequence_2352[mid]) { return binarySearch_2352(start, mid, val); }
	//else if (subsequence_2352[mid] > val) { return binarySearch_2352(start, mid - 1, val); }
	else { return binarySearch_2352(mid + 1, end, val); }
}

void Problem_2352()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, result = 1, inputBuffer;
	std::cin >> N;
	
	std::cin >> subsequence_2352[0];

	while (--N > 0)
	{
		std::cin >> inputBuffer;
		if (subsequence_2352[result - 1] < inputBuffer)
		{
			subsequence_2352[result++] = inputBuffer;
		}
		else
		{
			subsequence_2352[binarySearch_2352(0, result - 1, inputBuffer)] = inputBuffer;
		}
	}
	
	std::cout << result;
}
*/

// PROBLEM 1208
/*
int data_1208[41];
std::unordered_map<int, int> subsequencesCount;
long long result_1208;

void processSubsequences_1208(int idx, int end, int val)
{
	if (idx == end)
	{
		subsequencesCount[val]++;
		return;
	}

	processSubsequences_1208(idx + 1, end, val + data_1208[idx]);
	processSubsequences_1208(idx + 1, end, val);
}

void processSubsequences_1208(int idx, int end, int val, int S)
{
	if (idx == end)
	{
		if (subsequencesCount.find(S - val) == subsequencesCount.end()) { return; }
		result_1208 += subsequencesCount[S - val];
		return;
	}

	processSubsequences_1208(idx + 1, end, val + data_1208[idx], S);
	processSubsequences_1208(idx + 1, end, val, S);
}

void Problem_1208()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, S;

	std::cin >> N >> S;

	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> data_1208[idx];
	}

	processSubsequences_1208(0, N / 2, 0);
	processSubsequences_1208(N / 2, N, 0, S);

	if (S == 0) { result_1208--; }
	std::cout << result_1208 << '\n';
}
*/

// PROBLEM 1114
/*
int L_1114, K_1114, C_1114, cut_1114;
std::vector<int> points_1114;

bool process_1114(int mid)
{
	int sum = 0, subSum, cutCount = 0, cut;

	for (int idx = points_1114.size(); idx >= 0; idx--)
	{
		if (idx == points_1114.size())
		{
			subSum = L_1114 - points_1114[idx - 1];
		}
		else if (idx == 0) { subSum = points_1114[idx]; }
		else{ subSum = points_1114[idx] - points_1114[idx - 1]; }
		if (subSum > mid)
		{
			return false;
		}

		sum += subSum;
		if (sum > mid)
		{
			if (cutCount >= C_1114) { return false; }
			cut = idx;
			cutCount++;
			sum = subSum;
		}
	}

	if (C_1114 - cutCount > 0) { cut_1114 = 0; }
	else { cut_1114 = cut; }
	return true;
}

void Problem_1114()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> L_1114 >> K_1114 >> C_1114;
	int buffer;
	int start, end;

	for (int i = 0; i < K_1114; i++) {
		std::cin >> buffer;
		points_1114.emplace_back(buffer);
	}
	std::sort(points_1114.begin(), points_1114.end());
	points_1114.erase(std::unique(points_1114.begin(), points_1114.end()), points_1114.end());
	if (points_1114.size() <= C_1114)
	{
		start = points_1114[0];
		for (int idx = 1; idx < points_1114.size(); idx++)
		{
			buffer = points_1114[idx] - points_1114[idx - 1];
			if (buffer > start)
			{
				start = buffer;
			}
		}
		if (L_1114 - points_1114[points_1114.size() - 1] > start)
		{
			start = L_1114 - points_1114[points_1114.size() - 1];
		}
		std::cout << start << " " << points_1114[0];
	}
	else
	{
		start = 0, end = L_1114;
		bool midResult = process_1114(start + (end - start) / 2);
		while (true)
		{
			if (midResult){ end = start + (end - start) / 2; }
			else{ start = start + (end - start) / 2; }
			midResult = process_1114(start + (end - start) / 2);
			if (end - start <= 1)
			{
				break;
			}
		}

		if(midResult){ std::cout << start << ' ' << points_1114[cut_1114]; }
		else{ std::cout << end << ' ' << points_1114[cut_1114]; }
	}
}
*/

// PROBLEM 2568
/*
struct data
{
	data() = default;
	data(data* inParent, int inNum) : parent{ inParent }, num{ inNum } {}

	data* parent;
	int num;
};

data* subsequence[1000001];
data list[1000001];
int counts[1000001];
std::pair<int, int> wires[100001];

int binarySearch(int start, int end, int val)
{
	if (start == end) { return subsequence[start]->num >= val ? start : start + 1; }
	int mid = start + (end - start) / 2;
	if (val == subsequence[mid]->num) { return mid; }
	else if (val < subsequence[mid]->num) { return binarySearch(start, mid, val); }
	else { return binarySearch(mid + 1, end, val); }
}

void Problem_2568()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::vector<int> resultList;
	std::vector<int> removalList;
	data* lastDataBuffer = nullptr;
	int N, inputBuffer[2], result = 1;
	std::cin >> N;
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> inputBuffer[0] >> inputBuffer[1];
		wires[idx].first = inputBuffer[1];
		wires[idx].second = inputBuffer[0];
	}

	std::sort(wires, wires + N, [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {return lhs.second < rhs.second; });

	list[0] = data(nullptr, wires[0].first);
	subsequence[0] = &list[0];
	counts[0] = 1;
	for (int idx = 1; idx < N; idx++)
	{
		if (subsequence[result - 1]->num < wires[idx].first)
		{
			list[idx] = data(subsequence[result - 1], wires[idx].first);
			subsequence[result] = &list[idx];
			result++;
			counts[idx] = binarySearch(0, result - 1, wires[idx].first) + 1;
		}
		else
		{
			counts[idx] = binarySearch(0, result - 1, wires[idx].first) + 1;
			if (counts[idx] - 1 == 0)
			{
				list[idx] = data(nullptr, wires[idx].first);
				subsequence[counts[idx] - 1] = &list[idx];
			}
			else
			{
				list[idx] = data(subsequence[counts[idx] - 2], wires[idx].first);
				subsequence[counts[idx] - 1] = &list[idx];
			}
		}
	}

	lastDataBuffer = subsequence[result - 1];
	while (lastDataBuffer != nullptr)
	{
		resultList.emplace_back(lastDataBuffer->num);
		lastDataBuffer = lastDataBuffer->parent;
	}

	for (int idx = 0; idx < N; idx++)
	{
		if (std::find(resultList.begin(), resultList.end(), wires[idx].first) == resultList.end())
		{
			removalList.emplace_back(wires[idx].second);
		}
	}

	std::cout << removalList.size() << '\n';

	for (const auto& elem : removalList)
	{
		std::cout << elem << '\n';
	}
}
*/

// PROBLEM 17441
/*
int subsequence[1000001];
int counts[1000001];
std::vector<std::pair<int, long long>> list[1000001];

int binarySearch_17441(int start, int end, int val)
{
	if (start == end) { return subsequence[start] >= val ? start : start + 1; }
	int mid = start + (end - start) / 2;
	if (val == subsequence[mid]) { return mid; }
	else if (val < subsequence[mid]) { return binarySearch_17441(start, mid, val); }
	else { return binarySearch_17441(mid + 1, end, val); }
}

long long getSum(int length, int val)
{
	long long result = 0;
	for (const auto& elem : list[length])
	{
		if (elem.first < val)
		{
			result += elem.second % 1000000007;
		}
	}
	return result;
}

void Problem_17441()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, inputBuffer, result = 1;
	std::cin >> N >> subsequence[0];

	list[1].emplace_back(std::make_pair(subsequence[0], 1));
	counts[0] = 1;

	for (int idx = 1; idx < N; idx++)
	{
		std::cin >> inputBuffer;
		if (subsequence[result - 1] < inputBuffer)
		{
			subsequence[result] = inputBuffer;
			result++;
			counts[idx] = binarySearch_17441(0, result - 1, inputBuffer) + 1;
			list[counts[idx]].emplace_back(std::make_pair(inputBuffer, getSum(counts[idx] - 1, inputBuffer)));
		}
		else
		{
			counts[idx] = binarySearch_17441(0, result - 1, inputBuffer) + 1;
			subsequence[counts[idx] - 1] = inputBuffer;

			if (counts[idx] != 1)
			{
				list[counts[idx]].emplace_back(std::make_pair(inputBuffer, getSum(counts[idx] - 1, inputBuffer)));
			}
			else
			{
				list[counts[idx]].emplace_back(std::make_pair(inputBuffer, 1));
			}
		}
	}

	std::cout << result << " " << getSum(result, 1000000000) % 1000000007;
}
*/

// PROBLEM 1365
/*
struct data
{
	data() = default;
	data(data* inParent, int inNum) : parent{ inParent }, num{ inNum } {}

	data* parent;
	int num;
};

data* subsequence[100001];
data list[100001];
int counts[100001];
std::pair<int, int> wires[100001];

int binarySearch(int start, int end, int val)
{
	if (start == end) { return subsequence[start]->num >= val ? start : start + 1; }
	int mid = start + (end - start) / 2;
	if (val == subsequence[mid]->num) { return mid; }
	else if (val < subsequence[mid]->num) { return binarySearch(start, mid, val); }
	else { return binarySearch(mid + 1, end, val); }
}

void Problem_1365()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::vector<int> resultList;
	data* lastDataBuffer = nullptr;
	int N, inputBuffer[2], result = 1;
	std::cin >> N;
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> inputBuffer[1];
		wires[idx].first = inputBuffer[1];
		wires[idx].second = idx + 1;
	}

	list[0] = data(nullptr, wires[0].first);
	subsequence[0] = &list[0];
	counts[0] = 1;
	for (int idx = 1; idx < N; idx++)
	{
		if (subsequence[result - 1]->num < wires[idx].first)
		{
			list[idx] = data(subsequence[result - 1], wires[idx].first);
			subsequence[result] = &list[idx];
			result++;
			counts[idx] = binarySearch(0, result - 1, wires[idx].first) + 1;
		}
		else
		{
			counts[idx] = binarySearch(0, result - 1, wires[idx].first) + 1;
			if (counts[idx] - 1 == 0)
			{
				list[idx] = data(nullptr, wires[idx].first);
				subsequence[counts[idx] - 1] = &list[idx];
			}
			else
			{
				list[idx] = data(subsequence[counts[idx] - 2], wires[idx].first);
				subsequence[counts[idx] - 1] = &list[idx];
			}
		}
	}

	inputBuffer[0] = 0;
	lastDataBuffer = subsequence[result - 1];
	while (lastDataBuffer != nullptr)
	{
		resultList.emplace_back(lastDataBuffer->num);
		lastDataBuffer = lastDataBuffer->parent;
		inputBuffer[0]++;
	}

	std::cout << N - inputBuffer[0] << '\n';
}
*/

// PROBLEM 1920
/*
int data[100001];

void Problem_1920()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, M, inputNum;
	std::cin >> N;
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> data[idx];
	}

	std::sort(data, data + N);

	std::string outputStr;
	std::cin >> M;
	while (M-- > 0)
	{
		std::cin >> inputNum;
		if ((*std::lower_bound(data, data + N - 1, inputNum)) == inputNum) { outputStr += "1\n"; }
		else { outputStr += "0\n"; }
	}
	
	std::cout << outputStr;
}
*/


// PROBLEM 10816
/*
std::unordered_map<int, int> data;

void Problem_10816()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, M, inputNum;
	std::cin >> N;
	for (int idx = 0; idx < N; idx++) { std::cin >> inputNum; data[inputNum]++; }
	std::cin >> M;
	std::string outputStr;
	while (M-- > 0)
	{
		std::cin >> inputNum;
		if (data.find(inputNum) != data.end())
		{
			outputStr += std::to_string(data[inputNum]) + '\n';
		}
		else { outputStr += "0\n"; }
	}

	std::cout << outputStr;

}
*/

// PROBLEM 1024
/*
long long calc(int start, int end)
{
	return (long long)(start + end) * (end - start + 1) / 2;
}

int binarySearch_Num(int sNum, int eNum, int length, int val)
{
	if (sNum == eNum)
	{
		return calc(sNum, sNum + length - 1) == val ? sNum : -1;
	}

	int mid = (sNum + eNum) / 2;
	long long temp = calc(mid, mid + length - 1);
	if (temp == val) { return mid; }
	if (temp > val) { return binarySearch_Num(sNum, mid, length, val); }
	else { return binarySearch_Num(mid + 1, eNum, length, val); }
}

void Problem_1024()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, L, temp, resLength = -1, resNum = 0;
	std::cin >> N >> L;

	for (int len = L; len <= 100; len++)
	{
		temp = binarySearch_Num(0, N / L, len, N);
		if (temp != -1)
		{
			resNum = temp;
			resLength = len;
			break;
		}
	}

	if (resLength == -1)
	{
		std::cout << -1;
	}
	else
	{
		std::string outputStr;		
		for (int num = resNum; num <= resNum + resLength - 1; num++)
		{
			outputStr += std::to_string(num) + " ";
		}
		std::cout << outputStr;
	}
}
*/

void ExecuteBinarySearch()
{
	//Problem_1024();
	//Problem_3020();
	//Problem_2352();
	//Problem_1208();
	//Problem_1114();
	//Problem_2568();
	//Problem_17441();
	//Problem_1365();
	//Problem_1920();
	//Problem_10816();
	//Problem_1300();
}