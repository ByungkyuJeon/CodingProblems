#pragma once
#include <vector>
#include <utility>
#include <limits>

// PROBLEM 1007 FAILED (TIMEOUT)
/*
typedef std::numeric_limits< double > dbl;

std::pair<int, int> vecMatch[381];
int vecAsoc[381][11];
std::priority_queue<double, std::vector<double>, std::greater<double>> sums;

bool checkMultipled(int lhsIdx, int rhsIdx, int count)
{
	for (int idx = 0; idx < count; idx++)
	{
		if (std::find(vecAsoc[rhsIdx], vecAsoc[rhsIdx] + 2, vecAsoc[lhsIdx][idx]) != vecAsoc[rhsIdx] + 2)
		{
			return true;
		}
	}

	return false;
}

void getSums(const std::pair<int, int>* arr, int size, int maxDepth, int start, int depth, int x, int y, int base)
{
	if (start >= size) { return; }

	for (int depthIdx = start; depthIdx < size; depthIdx++)
	{
		if (maxDepth == 1){ sums.emplace(sqrt(pow(arr[depthIdx].first, 2) + pow(arr[depthIdx].second, 2))); continue; }
		if (depth == 1)
		{
			getSums(arr, size, maxDepth, depthIdx + 1, depth + 1, arr[depthIdx].first, arr[depthIdx].second, depthIdx);
		}
		else
		{
			if (checkMultipled(base, depthIdx, (depth - 1) * 2)) { continue; }
			if (depth == maxDepth) { sums.emplace(sqrt(pow(x + arr[depthIdx].first, 2) + pow(y + arr[depthIdx].second, 2))); continue; }
			vecAsoc[base][(depth * 2) - 2] = vecAsoc[depthIdx][0];
			vecAsoc[base][(depth * 2) - 1] = vecAsoc[depthIdx][1];
			getSums(arr, size, maxDepth, depthIdx + 1, depth + 1, x + arr[depthIdx].first, y + arr[depthIdx].second, base);
		}
	}
}

void Problem_1007()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(dbl::max_digits10);

	std::pair<int, int> points[20];
	int T, N;
	std::cin >> T;

	while (T-- > 0)
	{
		std::cin >> N;
		for(int idx = 0; idx < N; idx++)
		{
			std::cin >> points[idx].first >> points[idx].second;
		}

		int count = 0;

		for (int outerIdx = 0; outerIdx < N; outerIdx++)
		{
			for (int innerIdx = outerIdx + 1; innerIdx < N; innerIdx++)
			{
				vecMatch[count].first = points[outerIdx].first - points[innerIdx].first;
				vecMatch[count].second = points[outerIdx].second - points[innerIdx].second;
				vecAsoc[count][0] = outerIdx; vecAsoc[count][1] = innerIdx;
				vecMatch[count + 1].first = -vecMatch[count].first;
				vecMatch[count + 1].second = -vecMatch[count].second;
				vecAsoc[count + 1][0] = innerIdx; vecAsoc[count + 1][1] = outerIdx;
				count += 2;
			}
		}

		getSums(vecMatch, count, N / 2, 0, 1, 0, 0, 0);

		std::cout << sums.top() << '\n';
		sums = std::priority_queue<double, std::vector<double>, std::greater<double>>();
	}
}
*/

// PROBLEM 1007 RETRY (SUCCESS)
/*
typedef std::numeric_limits< double > dbl;

std::pair<long long, long long> points[20];
std::priority_queue<double, std::vector<double>, std::greater<double>> sums;

void getSums(const std::pair<long long, long long> sum, int size, int maxDepth, int start, int depth)
{
	if (start >= size) { return; }

	for (int depthIdx = start; depthIdx < size; depthIdx++)
	{
		if (depth == maxDepth) 
		{ 
			sums.emplace(sqrt(pow(sum.first - 2 * points[depthIdx].first, 2) + pow(sum.second - 2 * points[depthIdx].second, 2)));
			continue;
		}
		getSums(std::make_pair(sum.first - 2 * points[depthIdx].first, sum.second - 2 * points[depthIdx].second), size, maxDepth, depthIdx + 1, depth + 1);
	}
}

void Problem_1007()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(dbl::max_digits10);

	std::pair<long long, long long> sum = { 0, 0 };
	int T, N;
	std::cin >> T;

	while (T-- > 0)
	{
		std::cin >> N;
		for (int idx = 0; idx < N; idx++)
		{
			std::cin >> points[idx].first >> points[idx].second;
			sum.first += points[idx].first;
			sum.second += points[idx].second;
		}

		getSums(sum, N, N / 2, 0, 1);

		std::cout << sums.top() << '\n';
		sums = std::priority_queue<double, std::vector<double>, std::greater<double>>();
		sum = { 0, 0 };
	}
}
*/

// PROBLEM 1053

void Problem_1053()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string inputStr;
	
}

// PROBLEM 1019
/*
long long result[10];
int expNum = 0;

void process(std::string num)
{
	for (const auto& elem : num)
	{
		result[elem - '0'] += pow(10, expNum);
	}
}

void pushCounts(int lhs, int rhs)
{
	for (int idx = 0; idx < 10; idx++)
	{
		result[idx] += (rhs - lhs + 1) * pow(10, expNum);
	}

	expNum++;
}

void Problem_1019()
{
	int end, start = 1;
	std::cin >> end;

	while (end != 0)
	{
		while (start % 10 != 0)
		{
			process(std::to_string(start));
			if (start == end) { break; }
			start++;
		}

		if (start == end)
		{
			if (start % 10 == 0)
			{
				process(std::to_string(start));
			}
			break;
		}

		while (end % 10 != 9)
		{
			process(std::to_string(end));
			if (start == end) { break; }
			end--;
		}

		if (start == end)
		{
			if (end % 10 == 9)
			{
				process(std::to_string(end));
			}
			break;
		}

		pushCounts((start /= 10), (end /= 10));
	}

	for (int idx = 0; idx < 10; idx++)
	{
		std::cout << result[idx] << " ";
	}
}
*/

// PROBLEM 1027
/*
int data[51];

void Problem_1027()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::priority_queue<int> result;
	double maxTan, distance, height;
	int N, count;
	std::cin >> N;

	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> data[idx];
	}

	for (int idx = 0; idx < N; idx++)
	{
		count = 0;
		if (idx > 0)
		{
			maxTan = (data[idx] - data[idx - 1]);
			count = 1;
			for (int left = idx - 2; left >= 0; left--)
			{
				distance = idx - left;
				height = data[idx] - data[left];
				if (height / distance < maxTan)
				{
					maxTan = height / distance;
					count++;
				}
			}
		}

		if (idx < N - 1)
		{
			maxTan = (data[idx] - data[idx + 1]);
			count++;
			for (int right = idx + 2; right < N; right++)
			{
				distance = right - idx;
				height = data[idx] - data[right];
				if (height / distance < maxTan)
				{
					maxTan = height / distance;
					count++;
				}
			}
		}

		result.emplace(count);
	}

	std::cout << result.top();
}
*/

// PROBLEM 1038
/*
void Problem_1038()
{
	int nums[10] = { 0 };
	long long result = 0;
	int maxDigit = 0;
	int N;
	std::cin >> N;
	if (N > 1022)
	{
		std::cout << std::to_string(-1);
	}
	else
	{
		while (N-- > 0)
		{
			for (int digit = 0; digit <= maxDigit; digit++)
			{
				if (digit != maxDigit)
				{
					if (nums[digit] + 1 < nums[digit + 1])
					{
						nums[digit]++;
						break;
					}
					else
					{
						if (digit == 0) { nums[digit] = 0; }
						else { nums[digit] = nums[digit - 1] + 1; }
					}
				}
				else
				{
					if (nums[digit] == 9)
					{
						maxDigit++;
						if (digit == 0) { nums[digit] = 0; }
						else { nums[digit] = nums[digit - 1] + 1; }
						nums[maxDigit] = nums[digit] + 1;
						break;
					}
					else
					{
						nums[digit]++;
						break;
					}
				}
			}
		}

		for (int idx = 0; idx < 10; idx++)
		{
			if (nums[idx] > 0)
			{
				result += pow(10, idx) * nums[idx];
			}
		}

		std::cout << result << std::endl;
	}
}

void Problem_1038_Test()
{
	int N = 0;
	while (N < 50000)
	{
		//Problem_1038(N++);
	}
}
*/

void Execute_Math()
{
	//Problem_1007();
	//Problem_1019();
	//Problem_1027();
	//Problem_1038_Test();
	//Problem_1038();
}