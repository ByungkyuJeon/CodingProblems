#pragma once


void Problem_11438()
{

}

// PROBLEM 1068

std::vector<int> data[50];
int inputs[50];

int getLeaves(int nodeIdx)
{
	if (data[nodeIdx].size() == 0) { return 1; }

	int count = 0;

	for (const auto elem : data[nodeIdx])
	{
		count += getLeaves(elem);
	}

	return count;
}

void Problem_1068()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, removeIdx, inputBuffer, root = 0;
	std::cin >> N;
	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> inputs[idx];
		if (inputs[idx] == -1)
		{
			root = idx;
		}
	}

	std::cin >> removeIdx;
	if (removeIdx == root)
	{
		std::cout << std::to_string(0);
	}
	else
	{
		for (int idx = 0; idx < N; idx++)
		{
			if (idx == removeIdx) { continue; }
			if (inputs[idx] != -1 && inputs[idx] != idx)
			{
				data[inputs[idx]].emplace_back(idx);
			}
		}
		std::cout << getLeaves(root);
	}
}

void ExecuteTree()
{
	Problem_1068();
}