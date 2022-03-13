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
/*
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
*/

// PROBLEM 2667
/*
int xDirec[4]{ 0, 0, 1, -1 };
int yDirec[4]{ 1, -1, 0, 0 };
int N;
bool data[25][25];
bool visited[25][25];
std::vector<int> res;

int process(int x, int y, bool add)
{
	if (visited[x][y]) { return 0; }
	visited[x][y] = true;
	if (!data[x][y]) { return 0; }
	int sum = 1, nxtX, nxtY;
	for (int dIdx = 0; dIdx < 4; dIdx++)
	{
		if ((nxtX = x + xDirec[dIdx]) >= 0 && nxtX < N
			&& (nxtY = y + yDirec[dIdx]) >= 0 && nxtY < N)
		{
			sum += process(nxtX, nxtY, false);
		}
	}
	if (add) { res.emplace_back(sum); }
	return sum;
}

void Problem_2667()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string input;
	std::cin >> N;
	std::cin.ignore();
	for (int x = 0; x < N; x++)
	{
		std::cin >> input;
		for (int y = 0; y < N; y++)
		{
			data[x][y] = input[y] == '1';
		}
	}

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			process(x, y, true);
		}
	}

	std::sort(res.begin(), res.end());
	std::cout << res.size() << '\n';
	for (const auto& elem : res)
	{
		std::cout << elem << '\n';
	}
}
*/

// PROBLEM 1012
/*
int M, N;
bool base[50][50];
int count;

int xDirec[4]{ 0, 0, 1, -1 };
int yDirec[4]{ 1, -1, 0, 0 };

void process(int x, int y, bool started)
{
	if (!base[x][y]) { return; }
	if (!started) { count++; }
	
	base[x][y] = false;
	int newX, newY;

	for (int idx = 0; idx < 4; idx++)
	{
		newX = x + xDirec[idx];
		newY = y + yDirec[idx];
		if (newX < 0 || newX >= N || newY < 0 || newY >= M) { continue; }
		process(newX, newY, true);
	}
}

void Problem_1012()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string outputStr;

	int T, K, x, y;
	std::cin >> T;
	while (T-- > 0)
	{
		std::cin >> N >> M >> K;
		count = 0;
		while (K-- > 0)
		{
			std::cin >> x >> y;
			base[x][y] = true;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				process(i, j, false);
			}
		}

		outputStr += std::to_string(count) + '\n';
	}

	std::cout << outputStr;
}
*/

// PROBLEM 7576
/*
int M, N;
int data[1000][1000];
bool visited[1000][1000];
int xDirec[4]{ 0 , 0, 1, -1 };
int yDirec[4]{ 1, -1, 0, 0 };
std::queue<std::pair<int, int>> workQ;

long long process()
{
	long long res = -1;

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			if (data[x][y] == 1)
			{
				visited[x][y] = true;
				workQ.emplace(std::make_pair(x, y));
			}
		}
	}
	workQ.emplace(std::make_pair(-1, -1));

	int newX, newY;
	while (!workQ.empty())
	{
		if (workQ.front().first == -1) 
		{ 
			res++; workQ.pop(); 
			if (workQ.empty()) { break; }
			workQ.emplace(std::make_pair(-1, -1));
			continue; 
		}
		data[workQ.front().first][workQ.front().second] = 1;
		for (int idx = 0; idx < 4; idx++)
		{
			newX = workQ.front().first + xDirec[idx];
			newY = workQ.front().second + yDirec[idx];
			if (newX < 0 || newX >= N || newY < 0 || newY >= M || visited[newX][newY]) { continue; }
			visited[newX][newY] = true;
			if (data[newX][newY] == 0)
			{
				workQ.emplace(std::make_pair(newX, newY));
			}
		}
		workQ.pop();
	}

	return res;
}

void Problem_7576()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	bool check = true;

	std::cin >> M >> N;
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			std::cin >> data[x][y];
		}
	}
	long long res = process();
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			if (data[x][y] == 0) { check = false; break; }
		}
		if (!check) { break; }
	}

	if (check) { std::cout << res; }
	else { std::cout << -1; }
}
*/

// PROBLEM 7569
/*
int xDirec[6]{ 0,0,1,-1,0,0 };
int yDirec[6]{ 1,-1,0,0,0,0 };
int zDirec[6]{ 0,0,0,0,1,-1 };
int M, N, H;
int data[100][100][100];
int count;

struct Cordinate
{
	Cordinate(int x, int y, int z) : x{ x }, y{ y }, z{ z }{}
	int x, y, z;
};

void process()
{
	std::queue<Cordinate> searchQueue;
	for (int xCor = 0; xCor < N; xCor++)
	{
		for (int yCor = 0; yCor < M; yCor++)
		{
			for (int zCor = 0; zCor < H; zCor++)
			{
				if (data[xCor][yCor][zCor] == 1)
				{
					searchQueue.emplace(Cordinate(xCor, yCor, zCor));
				}
			}
		}
	}

	int newX, newY, newZ;
	searchQueue.emplace(Cordinate(-2, -2, -2));
	while (!searchQueue.empty())
	{
		if (searchQueue.front().x == -2)
		{
			count++;
			searchQueue.pop();
			if (searchQueue.empty())
			{
				break;
			}
			searchQueue.emplace(Cordinate(-2, -2, -2));
			continue;
		}
		for (int idx = 0; idx < 6; idx++)
		{
			newX = searchQueue.front().x + xDirec[idx];
			newY = searchQueue.front().y + yDirec[idx];
			newZ = searchQueue.front().z + zDirec[idx];
			if (newX < 0 || newX >= N
				|| newY < 0 || newY >= M
				|| newZ < 0 || newZ >= H )
			{
				continue;
			}
			if (data[newX][newY][newZ] == 0)
			{
				data[newX][newY][newZ] = 1;
				searchQueue.emplace(Cordinate(newX, newY, newZ));
			}
		}
		searchQueue.pop();
	}
}

void Problem_7569()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	bool check = false;
	std::cin >> M >> N >> H;
	for (int zCor = 0; zCor < H; zCor++)
	{
		for (int xCor = 0; xCor < N; xCor++)
		{
			for (int yCor = 0; yCor < M; yCor++)
			{
				std::cin >> data[xCor][yCor][zCor];
			}
		}
	}

	process();

	for (int xCor = 0; xCor < N; xCor++)
	{
		for (int yCor = 0; yCor < M; yCor++)
		{
			for (int zCor = 0; zCor < H; zCor++)
			{
				if (data[xCor][yCor][zCor] == 0)
				{
					check = true;
					break;
				}
			}
			if (check) { break; }
		}
		if (check) { break; }
	}

	if (check) { std::cout << -1; }
	else { std::cout << count - 1; }
}
*/

// PROBLEM 1753
//
/*
void dijkstra(std::vector<int>& res, std::vector<std::vector<std::pair<int, int>>> vertices, int start)
{
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
	minHeap.push(std::make_pair(0, start));
	res[start] = 0;

	while (minHeap.empty() == 0)
	{
		int Cost = minHeap.top().first;
		int Cur = minHeap.top().second;
		minHeap.pop();

		for (int i = 0; i < vertices[Cur].size(); i++)
		{
			int Next = vertices[Cur][i].first;
			int nCost = vertices[Cur][i].second;

			if (res[Next] > Cost + nCost)
			{
				res[Next] = Cost + nCost;
				minHeap.push(std::make_pair(res[Next], Next));
			}
		}
	}
}

void Problem_1753()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int V, E, start, u, v, w;
	std::cin >> V >> E >> start;
	std::vector<std::vector<std::pair<int, int>>> vertices(V + 1);
	std::vector<int> res(V + 1);
	for (int idx = 0; idx <= V; idx++) 
	{
		res[idx] = INT_MAX;
	}
	for (int idx = 1; idx <= E; idx++)
	{
		std::cin >> u >> v >> w;
		vertices[u].emplace_back(std::make_pair(v, w));
	}

	dijkstra(res, vertices, start);
	std::string outputStr;
	for (int idx = 1; idx <= V; idx++)
	{
		if (res[idx] == INT_MAX) { outputStr += "INF\n"; continue; }
		outputStr += std::to_string(res[idx]) + '\n';
	}
	std::cout << outputStr;
}
*/

// PROBLEM 1697

int process(int start, int end)
{
	std::queue<int> procQueue;
	procQueue.emplace(start);
	procQueue.emplace(INT_MAX);

	std::vector<bool> visited(100001, false);

	int count = 0;
	int pOne, mOne, mult;

	while (!procQueue.empty())
	{
		if (procQueue.front() == end) { break; }
		if (procQueue.front() == INT_MAX)
		{
			procQueue.pop();
			if (procQueue.empty()) { break; }
			procQueue.emplace(INT_MAX);
			count++;
			continue;
		}
		visited[procQueue.front()] = true;
		pOne = procQueue.front() + 1;
		mOne = procQueue.front() - 1;
		mult = procQueue.front() * 2;
		if(pOne <= 100000 && !visited[pOne]){ procQueue.emplace(pOne); }
		if (mOne >= 0 && !visited[mOne]) { procQueue.emplace(mOne); }
		if (mult <= 100000 && !visited[mult]) { procQueue.emplace(mult); }
		procQueue.pop();
	}

	return count;
}

void Problem_1697()
{
	int N, K;
	std::cin >> N >> K;
	std::cout << process(N, K);
}

void Problem_1697_Test()
{
	int N, K;
	std::srand(std::time(NULL));
	while (true)
	{
		N = std::rand() % 100000;
		K = std::rand() % 100000;
		std::cout << process(N, K) << std::endl;
	}
}

void ExecuteDFS_BFS()
{
	//Problem_1376();
	//Problem_1260();
	//Problem_2606();
	//Problem_2667();
	//Problem_1012();
	//Problem_7576();
	//Problem_7569();
	//Problem_1753();
	//Problem_1697();
	Problem_1697_Test();
}