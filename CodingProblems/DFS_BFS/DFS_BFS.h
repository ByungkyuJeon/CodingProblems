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

void ExecuteDFS_BFS()
{
	//Problem_1376();
}