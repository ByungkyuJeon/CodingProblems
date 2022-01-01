#pragma once

#include <unordered_map>
#include <iostream>

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

void ExecuteBinarySearch()
{
	//Problem_3020();
	//Problem_2352();
	//Problem_1208();
	//Problem_1114();
}