#pragma once
#include <set>

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
/*
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
*/

// PROBLEM 10800
/*
struct ball
{
public:
	ball() : num{ 0 }, color{ 0 }, size{ 0 }, score{ 0 } {}
	ball(int inNum, int inColor, int inSize) : num{ inNum }, color{ inColor }, size{ inSize }, score{ 0 }{}
	int num, color, size;
	long long score;
};

struct Colors
{
	std::vector<int> sizes;
	std::vector<long long> colorFenwick;
	int processIdx = 0;
};

std::vector<ball> data_10800;
std::vector<long long> fenwickTree;
std::unordered_map<int, Colors> colorMap;

void update(std::vector<long long>& arr, int idx, int value, int size)
{
	while (idx < size)
	{
		arr[idx] += value;
		idx += idx & -idx;
	}
}

long long getSum(std::vector<long long>& arr, int idx)
{
	long long sum = 0;
	while (idx > 0)
	{
		sum += arr[idx];
		idx -= idx & -idx;
	}
	return sum;
}

long long getColorSubstraction(int color, int size)
{
	if (colorMap[color].sizes.size() <= 1) { return 0; }
	int realIdx = -1;
	for (int idx = colorMap[color].processIdx - 1; idx >= 0; idx--)
	{
		if (colorMap[color].sizes[idx] != size) { realIdx = idx; break; }
	}
	colorMap[color].processIdx++;
	if (realIdx != -1)
	{
		return getSum(colorMap[color].colorFenwick, realIdx + 1);
	}
	return 0;
}

int getSameSizeIndex(int inIdx, int size)
{
	for (int idx = inIdx - 1; idx >= 0; idx--)
	{
		if (data_10800[idx].size != size) { return idx; }
	}
	return -1;
}

void Problem_10800()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string outputStr;
	int N;
	std::cin >> N;

	data_10800.resize(N);
	fenwickTree.resize(N + 1);

	for (int idx = 0; idx < N; idx++)
	{
		std::cin >> data_10800[idx].color >> data_10800[idx].size;
		data_10800[idx].num = idx;
		colorMap[data_10800[idx].color].sizes.emplace_back(data_10800[idx].size);
	}

	for (auto& elem : colorMap)
	{
		std::sort(elem.second.sizes.begin(), elem.second.sizes.end());
		elem.second.colorFenwick.resize(elem.second.sizes.size() + 1);
		for (int idx = 0; idx < elem.second.sizes.size(); idx++)
		{
			update(elem.second.colorFenwick, idx + 1, elem.second.sizes[idx], elem.second.colorFenwick.size());
		}
	}

	std::sort(data_10800.begin(), data_10800.end(), [](const ball& lhs, const ball& rhs) {return lhs.size < rhs.size; });

	for (int idx = 0; idx < N; idx++)
	{
		update(fenwickTree, idx + 1, data_10800[idx].size, N + 1);
	}

	int realIdx;
	for (int idx = 0; idx < N; idx++)
	{
		if ((realIdx = getSameSizeIndex(idx, data_10800[idx].size)) != -1)
		{
			data_10800[idx].score = getSum(fenwickTree, realIdx + 1) - getColorSubstraction(data_10800[idx].color, data_10800[idx].size);
		}
		else
		{
			colorMap[data_10800[idx].color].processIdx++;
			data_10800[idx].score = 0;
		}
	}

	std::sort(data_10800.begin(), data_10800.end(), [](const ball& lhs, const ball& rhs) {return lhs.num < rhs.num; });
	
	for (int idx = 0; idx < N; idx++)
	{
		outputStr += std::to_string(data_10800[idx].score) + '\n';
	}

	std::cout << outputStr;
}
*/

void ExecuteTree()
{
	//Problem_1068();
	//Problem_11505();
	//Problem_10800();
}