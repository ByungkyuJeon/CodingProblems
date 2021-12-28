#pragma once

// PROBLEM 1040
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

void ExecuteGreedy()
{
	Problem_1040();
}