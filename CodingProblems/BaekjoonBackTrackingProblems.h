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

void ExecuteBackTracking()
{
	//Problem_15649();
	//Problem_15650();
	//Problem_15651();
	Problem_15652();
}