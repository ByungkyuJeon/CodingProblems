#pragma once

// PROBLEM 13701

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

void ExecuteBit()
{
	Problem_13701();
}