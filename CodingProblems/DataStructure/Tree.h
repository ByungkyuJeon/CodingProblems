#pragma once


void Problem_11438()
{

}

// PROBLEM 1068
/*
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
*/

// PROBLEM 11505

long long data[1000002];
long long segTree[4000000];

long long makeSegTree(int start, int end, int node)
{
	if (start == end) { segTree[node] = data[start]; return segTree[node]; }
	int mid = start + ((end - start) / 2);

	segTree[node] = makeSegTree(start, mid, 2 * node) * makeSegTree(mid + 1, end, 2 * node + 1) % 1000000007;
	return segTree[node];
}

long long modifySegTree(int start, int end, int node, int idx, long long val)
{
	if (start > idx || end < idx) { return segTree[node]; }

	if (start == end && start == idx) { segTree[node] = val; return segTree[node]; }

	int mid = start + ((end - start) / 2);
	segTree[node] = modifySegTree(start, mid, 2 * node, idx, val) * modifySegTree(mid + 1, end, 2 * node + 1, idx, val) % 1000000007;
	return segTree[node];
}

long long getSegNode(int start, int end, int node, int left, int right)
{
	if (left > end || right < start) { return 1; }

	if (start >= left && end <= right) { return segTree[node]; }

	int mid = start + ((end - start) / 2);
	return getSegNode(start, mid, 2 * node, left, right) * getSegNode(mid + 1, end, 2 * node + 1, left, right) % 1000000007;
}

void Problem_11505()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, M, K, loopCount;
	long long inputBuffer[3];
	std::string outputStr;
	std::cin >> N >> M >> K;
	loopCount = M + K;
	for (int idx = 1; idx <= N; idx++)
	{
		std::cin >> data[idx];
	}
	makeSegTree(1, N, 1);

	while (loopCount-- > 0)
	{
		std::cin >> inputBuffer[0] >> inputBuffer[1] >> inputBuffer[2];
		if (inputBuffer[0] == 1)
		{
			modifySegTree(1, N, 1, inputBuffer[1], inputBuffer[2]);
		}
		else
		{
			outputStr += std::to_string(getSegNode(1, N, 1, inputBuffer[1], inputBuffer[2])) + '\n';
		}
	}

	std::cout << outputStr;
}

void ExecuteTree()
{
	//Problem_1068();
	Problem_11505();
}