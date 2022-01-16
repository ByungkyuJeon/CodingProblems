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
	unsigned long long digits[30] = { 0 };
	unsigned long long sumDigits[65] = { 0 };
	std::bitset<32> bitsetBuffer;
	unsigned long long result = 0, inputBuffer;

	for (int count = 1; count <= N; count++)
	{
		inputBuffer = data[count];
		bitsetBuffer = std::bitset<32>(inputBuffer);

		for (int idx = 0; idx < 30; idx++)
		{
			if (bitsetBuffer[idx])
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
			result += static_cast<unsigned long long>(pow(2, idx));
		}
	}

	return result;
}

void Problem_13710_BF_TestStarter()
{
	bool test = true;
	std::srand(std::time(NULL));
	while (test)
	{
		unsigned long long testResult;
		int N;
		long long result = 0;
		N = 100000;
		//std::cin >> N;
		for (int idx = 1; idx <= N; idx++)
		{
			//data[idx] = std::rand() % 1000000001;
			//std::cin >> data[idx];
			data[idx] = 1000000000;
		}

		/*makeSegTree(1, N, 1);

		for (int size = 1; size <= N; size++)
		{
			for (int idx = 1; idx <= N - size + 1; idx++)
			{
				result += getSeg(1, N, 1, idx, idx + size - 1);
			}
		}*/

		test = ((testResult = Problem_13710_Test(N)) == result);
		std::cout << "Test : " << test << std::endl;
		if (!test)
		{
			std::cout << "BF result  : " << result << "  Bit result : " << testResult << std::endl;
			std::cout << "case : ";
			for (int idx = 1; idx <= N; idx++)
			{
				std::cout << data[idx] << " ";
			}
		}
		break;
	}
}

void Problem_13710()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	unsigned long long digits[32] = { 0 };
	unsigned long long sumDigits[65] = { 0 };
	std::bitset<32> bitsetBuffer;
	int N;
	unsigned long long result = 0, inputBuffer;
	std::cin >> N;

	for (int count = 1; count <= N; count++)
	{
		std::cin >> inputBuffer;
		bitsetBuffer = std::bitset<32>(inputBuffer);

		for (int idx = 0; idx < 32; idx++)
		{
			if (bitsetBuffer[idx])
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
			result += pow(2, idx);
		}
	}

	std::cout << result;
}


// PROBLEM 2830

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

void ExecuteBit()
{
	//Problem_13701();
	//Problem_13710_BF_TestStarter();
	//Problem_13710();
	Problem_2830();
}