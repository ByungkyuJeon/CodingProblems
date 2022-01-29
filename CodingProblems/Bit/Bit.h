#pragma once

// PROBLEM 13701
/*
std::bitset<33554432> bitSet;

void Problem_13701()
{
	int num;

	while (~scanf("%d", &num))
	{
		if (!bitSet[num])
		{
			bitSet[num] = 1;
			printf("%d ", num);
		}
	}
}
*/

// PROBLEM 13710
/*
int data[100002];
long long segTree[400000];

long long makeSegTree(int start, int end, int node)
{
	if (start == end) { segTree[node] = data[start]; return segTree[node]; }
	int mid = start + (end - start) / 2;
	long long lhs = makeSegTree(start, mid, 2 * node);
	long long rhs = makeSegTree(mid + 1, end, (2 * node) + 1);
	segTree[node] = lhs ^ rhs;
	return segTree[node];
}

long long getSeg(int start, int end, int node, int left, int right)
{
	if (left > end || right < start) { return -1; }
	if (start >= left && end <= right) { return segTree[node]; }
	int mid = start + (end - start) / 2;
	long long lhs = getSeg(start, mid, 2 * node, left, right);
	long long rhs = getSeg(mid + 1, end, (2 * node) + 1, left, right);
	if (lhs != -1 && rhs != -1) { return lhs ^ rhs; }
	else if (lhs == -1 && rhs == -1) { return -1; }
	else if (lhs == -1) { return rhs; }
	else { return lhs; }
}

unsigned long long Problem_13710_Test(int N)
{
	int digits[30] = { 0 };
	unsigned long long sumDigits[65] = { 0 };
	unsigned long long result = 0, inputBuffer;

	for (int count = 1; count <= N; count++)
	{
		inputBuffer = data[count];

		for (int idx = 0; idx < 30; idx++)
		{
			if ((inputBuffer >> idx) & 1 == 1)
			{
				digits[idx] = count - digits[idx];
			}
			sumDigits[idx] += digits[idx];
		}
	}

	for (int idx = 0; idx < 64; idx++)
	{
		sumDigits[idx + 1] += sumDigits[idx] / 2;
		if (sumDigits[idx] % 2 == 1)
		{
			result += ((unsigned long long)1 << idx);
		}
	}

	return result;
}

int count = 1;

void Problem_13710_BF_TestStarter()
{
	bool test = true;
	std::srand(std::time(NULL));
	while (test)
	{
		unsigned long long testResult;
		int N;
		long long result = 0;
		N = count++;
		//N = 100000;
		//std::cin >> N;
		for (int idx = 1; idx <= N; idx++)
		{
			data[idx] = idx;
			//std::cin >> data[idx];
			//data[idx] = 1000000000;
		}

		makeSegTree(1, N, 1);

		for (int size = 1; size <= N; size++)
		{
			for (int idx = 1; idx <= N - size + 1; idx++)
			{
				result += getSeg(1, N, 1, idx, idx + size - 1);
			}
		}

		test = ((testResult = Problem_13710_Test(N)) == result);
		test = true;
		std::cout << "Test : " << testResult << " N : " << N << std::endl;
		if (!test)
		{
			std::cout << "BF result  : " << result << "  Bit result : " << testResult << std::endl;
			std::cout << "case : ";
			for (int idx = 1; idx <= N; idx++)
			{
				std::cout << data[idx] << " ";
			}
		}
		//break;
	}
}

void Problem_13710()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int digits[30] = { 0 };
	unsigned long long sumDigits[65] = { 0 };
	int N;
	unsigned long long result = 0, inputBuffer;
	std::cin >> N;

	for (int count = 1; count <= N; count++)
	{
		std::cin >> inputBuffer;

		for (int idx = 0; idx < 30; idx++)
		{
			if ((inputBuffer >> idx) & 1 == 1)
			{
				digits[idx] = count - digits[idx];
			}
			sumDigits[idx] += digits[idx];
		}
	}

	for (int idx = 0; idx < 64; idx++)
	{
		sumDigits[idx + 1] += sumDigits[idx] / 2;
		if (sumDigits[idx] % 2 == 1)
		{
			result += ((unsigned long long)1 << idx);
		}
	}

	std::cout << result;
}
*/

// PROBLEM 2830
/*
void Problem_2830()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	long long resultNum = 0;
	int digits[20] = { 0 };

	int N, inputBuffer;
	std::cin >> N;

	for(int idx = 0; idx < N; idx++)
	{
		std::cin >> inputBuffer;

		for (int digit = 0; digit < 20; digit++)
		{
			digits[digit] += (inputBuffer >> digit) & 1;
		}
	}

	for (int digit = 0; digit < 20; digit++)
	{
		resultNum += (long long)(1 << digit) * digits[digit] * (N - digits[digit]);
	}

	std::cout << resultNum;
}
*/

// PROBLEM 13709

void Problem_13709()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::vector<unsigned long long> sums;
	int digits[60] = { 0 };
	unsigned long long sumDigits[60] = { 0 };
	int N;
	unsigned long long result = 0, inputBuffer;
	std::cin >> N >> inputBuffer;

	sums.emplace_back(inputBuffer);

	for (int count = 1; count < N; count++)
	{
		std::cin >> inputBuffer;

		for (int idx = sums.size() - 1; idx >= sums.size() - 1 - count; idx--)
		{
			sums.emplace_back((sums[idx]) ^ inputBuffer);
		}
	}

	result = *(std::max_element(sums.begin(), sums.end()));

	std::cout << result;
}

void ExecuteBit()
{
	//Problem_13701();
	//Problem_13710_BF_TestStarter();
	//Problem_13710();
	//Problem_2830();
	//Problem_13709();
}