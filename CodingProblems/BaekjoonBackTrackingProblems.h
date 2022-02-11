#pragma once

// PROBLEM 15649
/*
bool visited[9];
std::vector<int> proc;
int N, M, depth;
std::string outputStr;

void process()
{
	if (depth == M)
	{
		for (const auto& elem : proc)
		{
			outputStr += std::to_string(elem) + " ";
		}
		outputStr += '\n';
		return;
	}

	for (int idx = 1; idx <= N; idx++)
	{
		if (!visited[idx])
		{
			proc.emplace_back(idx);
			visited[idx] = true;
			depth++;
			process();
			proc.erase(proc.end() - 1);
			visited[idx] = false;
			depth--;
		}
	}
}

void Problem_15649()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N >> M;

	process();

	std::cout << outputStr;
}
*/

// PROBLEM 15650
/*
bool visited[9];
std::vector<int> proc;
int N, M, depth;
std::string outputStr;

void process(int prev)
{
	if (depth == M)
	{
		for (const auto& elem : proc)
		{
			outputStr += std::to_string(elem) + " ";
		}
		outputStr += '\n';
		return;
	}

	for (int idx = 1; idx <= N; idx++)
	{
		if (!visited[idx] && prev < idx)
		{
			proc.emplace_back(idx);
			visited[idx] = true;
			depth++;
			process(idx);
			proc.erase(proc.end() - 1);
			visited[idx] = false;
			depth--;
		}
	}
}

void Problem_15650()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N >> M;

	process(0);

	std::cout << outputStr;
}
*/

// PROBLEM 15651
/*
std::vector<int> proc;
int N, M, depth;
std::string outputStr;

void process()
{
	if (depth == M)
	{
		for (const auto& elem : proc)
		{
			outputStr += std::to_string(elem) + " ";
		}
		outputStr += '\n';
		return;
	}

	for (int idx = 1; idx <= N; idx++)
	{
		proc.emplace_back(idx);
		depth++;
		process();
		proc.erase(proc.end() - 1);
		depth--;
	}
}

void Problem_15651()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N >> M;

	process();

	std::cout << outputStr;
}
*/

// PROBLEM 15652
/*
std::vector<int> proc;
int N, M, depth;
std::string outputStr;

void process(int prev)
{
	if (depth == M)
	{
		for (const auto& elem : proc)
		{
			outputStr += std::to_string(elem) + " ";
		}
		outputStr += '\n';
		return;
	}

	for (int idx = 1; idx <= N; idx++)
	{
		if (prev <= idx)
		{
			proc.emplace_back(idx);
			depth++;
			process(idx);
			proc.erase(proc.end() - 1);
			depth--;
		}
	}
}

void Problem_15652()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N >> M;

	process(1);

	std::cout << outputStr;
}
*/

// PROBLEM 9663
/*
int board[15][15];
int N, depth, count;

void process(int xPrv)
{
	int xTemp, yTemp;
	for (int in = 1; in <= N; in++)
	{
		if (board[xPrv][in] == 0)
		{
			if (depth + 1 == N) { count++; return; }
			for (int x = 1; x <= N; x++) { board[x][in]++; }
			for (int y = 1; y <= N; y++) { board[xPrv][y]++; }
			xTemp = xPrv; yTemp = in;
			for (int count = 1;; count++) { if (--xTemp > 0 && --yTemp > 0) { board[xTemp][yTemp]++; } else { break; } }
			xTemp = xPrv; yTemp = in;
			for (int count = 1;; count++) { if (++xTemp <= N && ++yTemp <= N) { board[xTemp][yTemp]++; } else { break; } }
			xTemp = xPrv; yTemp = in;
			for (int count = 1;; count++) { if (--xTemp > 0 && ++yTemp <= N) { board[xTemp][yTemp]++; } else { break; } }
			xTemp = xPrv; yTemp = in;
			for (int count = 1;; count++) { if (++xTemp <= N && --yTemp > 0) { board[xTemp][yTemp]++; } else { break; } }
			depth++;
			process(xPrv + 1);
			for (int x = 1; x <= N; x++) { board[x][in]--; }
			for (int y = 1; y <= N; y++) { board[xPrv][y]--; }
			xTemp = xPrv; yTemp = in;
			for (int count = 1;; count++) { if (--xTemp > 0 && --yTemp > 0) { board[xTemp][yTemp]--; } else { break; } }
			xTemp = xPrv; yTemp = in;
			for (int count = 1;; count++) { if (++xTemp <= N && ++yTemp <= N) { board[xTemp][yTemp]--; } else { break; } }
			xTemp = xPrv; yTemp = in;
			for (int count = 1;; count++) { if (--xTemp > 0 && ++yTemp <= N) { board[xTemp][yTemp]--; } else { break; } }
			xTemp = xPrv; yTemp = in;
			for (int count = 1;; count++) { if (++xTemp <= N && --yTemp > 0) { board[xTemp][yTemp]--; } else { break; } }
			depth--;
		}
	}
}


void Problem_9663()
{
	std::cin >> N;
	process(1);
	std::cout << count;
}
*/

// PROBLEM 2580
/*
int data[9][9];
std::vector<std::pair<int, int>> zeroes;

bool process(int idx)
{
	if (idx == zeroes.size()) { return true; }
	std::vector<int> possibles{ 1,2,3,4,5,6,7,8,9 };
	int xTemp, yTemp;
	for (int y = 0; y < 9; y++) { if (std::find(possibles.begin(), possibles.end(), data[zeroes[idx].first][y]) != possibles.end()) { possibles.erase(std::remove(possibles.begin(), possibles.end(), data[zeroes[idx].first][y])); } }
	for (int x = 0; x < 9; x++) { if (std::find(possibles.begin(), possibles.end(), data[x][zeroes[idx].second]) != possibles.end()) { possibles.erase(std::remove(possibles.begin(), possibles.end(), data[x][zeroes[idx].second])); } }
	xTemp = zeroes[idx].first - (zeroes[idx].first % 3) + 3;
	yTemp = zeroes[idx].second - (zeroes[idx].second % 3) + 3;
	for (int x = zeroes[idx].first - (zeroes[idx].first % 3); x < xTemp; x++) { for (int y = zeroes[idx].second - (zeroes[idx].second % 3); y < yTemp; y++) { if (std::find(possibles.begin(), possibles.end(), data[x][y]) != possibles.end()) { possibles.erase(std::remove(possibles.begin(), possibles.end(), data[x][y])); } } }
	for (int possIdx = 0; possIdx < possibles.size(); possIdx++)
	{
		data[zeroes[idx].first][zeroes[idx].second] = possibles[possIdx];
		if (process(idx + 1)) { return true; }
		data[zeroes[idx].first][zeroes[idx].second] = 0;
	}
	return false;
}

void Problem_2580()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string outputStr;

	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			std::cin >> data[x][y];
			if (!data[x][y]) { zeroes.emplace_back(std::make_pair(x, y)); }
		}
	}

	process(0);

	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			outputStr += std::to_string(data[x][y]) + " ";
		}
		outputStr += '\n';
	}

	std::cout << outputStr;
}
*/

// PROBLEM 14888

int N;
int data[11];
int operators[4];
int max = -1000000000, min = 1000000000;

void process(int num, int idx)
{
	if(idx == N)
	{
		if (num > max) { max = num; }
		if (num < min) { min = num; }
		return;
	}
	int numTemp = num;
	for (int operIdx = 0; operIdx < 4; operIdx++)
	{
		if (operators[operIdx] != 0)
		{
			numTemp = num;
			switch (operIdx)
			{
			case 0:
				numTemp += data[idx];
				break;
			case 1:
				numTemp -= data[idx];
				break;
			case 2:
				numTemp *= data[idx];
				break;
			case 3:
				numTemp /= data[idx];
				break;
			default:
				break;
			}
			operators[operIdx]--;
			process(numTemp, idx + 1);
			operators[operIdx]++;
		}
	}
}

void Problem_14888()
{
	std::cin >> N;
	for (int idx = 0; idx < N; idx++){ std::cin >> data[idx]; }
	std::cin >> operators[0] >> operators[1] >> operators[2] >> operators[3];
	process(data[0], 1);
	std::cout << max << '\n';
	std::cout << min << '\n';
}

void ExecuteBackTracking()
{
	//Problem_15649();
	//Problem_15650();
	//Problem_15651();
	//Problem_15652();
	//Problem_9663();
	//Problem_2580();
	Problem_14888();
}