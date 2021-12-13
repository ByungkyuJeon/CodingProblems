#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>

int rowMovement_Graph[4] = { 0, 0, 1, -1 };
int columnMovement_Graph[4] = { 1, -1, 0, 0 };
std::string puzzle[101];
int distance[101][101];

int DFS_2178(int inX, int inY, int N, int M)
{
	if (inX == N - 1 && inY == M - 1)
	{
		return 1;
	}

	puzzle[inX][inY] = '0';
	int nextX, nextY, result, counter = 0;
	int results[4] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX };

	for (int moveIdx = 0; moveIdx < 4; moveIdx++)
	{
		nextX = inX + rowMovement_Graph[moveIdx];
		nextY = inY + columnMovement_Graph[moveIdx];
		if (nextX >= 0 && nextX < N
			&& nextY >= 0 && nextY < M
			&& puzzle[nextX][nextY] == '1')
		{
			if ((result = DFS_2178(nextX, nextY, N, M)) != -1)
			{
				counter++;
				results[moveIdx] = result + 1;
			}
		}
	}

	puzzle[inX][inY] = '1';

	if(counter == 0)
	{ 
		return -1;
	}
	return *std::min_element(results, results + 4);
}

int BFS_2178(int inX, int inY, int N, int M)
{
	std::queue<std::pair<int, int>> bfsQueue;
	bfsQueue.push(std::make_pair(inX, inY));
	distance[inX][inY] = 1;
	int nextX, nextY;

	while (!bfsQueue.empty())
	{
		if (bfsQueue.front().first == N - 1 && bfsQueue.front().second == M - 1)
		{
			return distance[bfsQueue.front().first][bfsQueue.front().second];
		}

		for (int moveIdx = 0; moveIdx < 4; moveIdx++)
		{
			nextX = bfsQueue.front().first + rowMovement_Graph[moveIdx];
			nextY = bfsQueue.front().second + columnMovement_Graph[moveIdx];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M
				&& puzzle[nextX][nextY] == '1' && distance[nextX][nextY] == 0)
			{
				bfsQueue.push(std::make_pair(nextX, nextY));
				distance[nextX][nextY] = distance[bfsQueue.front().first][bfsQueue.front().second] + 1;
			}
		}

		bfsQueue.pop();
	}
}

void Problem_2178()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;
	std::cin.ignore();

	for (int rowReadCounter = 0; rowReadCounter < N; rowReadCounter++)
	{
		std::getline(std::cin, puzzle[rowReadCounter]);
	}

	double consumedTime = TimeChecker::CheckTime([&] {
		std::cout << BFS_2178(0, 0, N, M) << '\n';
		});

	std::cout << "consumed time : " << consumedTime << " ms" << '\n';
}

void ExecuteGraph()
{
	Problem_2178();
}