#pragma once

// PROBLEM 1376
/*
std::set<int> nodes_1376[100002];
std::string result_1376;
bool visited_1376[100002];

void mFS_1376(int nodeIdx)
{
	visited_1376[nodeIdx] = true;
	result_1376 += std::to_string(nodeIdx) + ' ';

	std::vector<int> unVisited;
	std::vector<int> temp;
	for (const auto& node : nodes_1376[nodeIdx])
	{
		if (!visited_1376[node])
		{
			unVisited.emplace_back(node);
		}
	}
	if (unVisited.size() == 0) { return; }

	while (true)
	{
		if (unVisited.size() % 2 == 0)
		{
			mFS_1376(unVisited[0]);
		}
		else
		{
			mFS_1376(unVisited[unVisited.size() / 2]);
		}

		temp.clear();
		for (const auto& node : unVisited)
		{
			if (!visited_1376[node])
			{
				temp.emplace_back(node);
			}
		}
		if (temp.size() == 0) { break; }

		unVisited.clear();
		for (const auto& node : temp)
		{
			unVisited.emplace_back(node);
		}
	}
}

void Problem_1376()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, M, inputBuffer[2];
	std::cin >> N >> M;
	while (M-- > 0)
	{
		std::cin >> inputBuffer[0] >> inputBuffer[1];
		nodes_1376[inputBuffer[0]].emplace(inputBuffer[1]);
		nodes_1376[inputBuffer[1]].emplace(inputBuffer[0]);
	}

	mFS_1376(1);

	std::cout << result_1376 << '\n';
}
*/

// PROBLEM 1260
/*
std::vector<int> data[1001];
bool visited[1001];
std::vector<int> dfsRes, bfsRes;


void resetVisited(int num)
{
	for (int idx = 1; idx <= num; idx++) { visited[idx] = false; }
}

void dfs(int node)
{
	if (visited[node]) { return; }
	visited[node] = true;
	dfsRes.emplace_back(node);
	for (const auto& elem : data[node])
	{
		dfs(elem);
	}
}

void bfs(int node)
{
	std::queue<int> bfsQueue;
	bfsQueue.emplace(node);
	while (!bfsQueue.empty())
	{
		if (visited[bfsQueue.front()]) { bfsQueue.pop(); continue; }
		visited[bfsQueue.front()] = true;
		bfsRes.emplace_back(bfsQueue.front());
		for (const auto& elem : data[bfsQueue.front()])
		{
			bfsQueue.emplace(elem);
		}
		bfsQueue.pop();
	}
	
}

void Problem_1260()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, M, start, input[2];
	std::cin >> N >> M >> start;
	while (M-- > 0)
	{
		std::cin >> input[0] >> input[1];
		data[input[0]].emplace_back(input[1]);
		data[input[1]].emplace_back(input[0]);
	}

	for (int idx = 1; idx <= N; idx++)
	{
		std::sort(data[idx].begin(), data[idx].end());
	}

	dfs(start);
	resetVisited(N);
	bfs(start);
	std::string outputStr;
	for (const auto& elem : dfsRes)
	{
		outputStr += std::to_string(elem) += " ";
	}
	outputStr += '\n';
	for (const auto& elem : bfsRes)
	{
		outputStr += std::to_string(elem) + " ";
	}

	std::cout << outputStr;
}
*/

// PROBLEM 2606

int N, count;

std::vector<int> data[101];
bool visited[101];

void process(int node)
{
	if (visited[node]) { return; }
	visited[node] = true;
	count++;
	for (const auto& elem : data[node])
	{
		process(elem);
	}
}

void Problem_2606()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int M, input[2];
	std::cin >> N >> M;
	while (M-- > 0)
	{
		std::cin >> input[0] >> input[1];
		data[input[0]].emplace_back(input[1]);
		data[input[1]].emplace_back(input[0]);
	}
	process(1);
	std::cout << count - 1;
}

void ExecuteDFS_BFS()
{
	//Problem_1376();
	//Problem_1260();
	Problem_2606();
}