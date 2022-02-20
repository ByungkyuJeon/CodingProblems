#pragma once
#include <stack>

// PROBLEM 10828
/*
void Problem_10828()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::stack<int> data;
	int N, inputNum;
	std::cin >> N;
	std::string inputStr, outputStr;

	while (N-- > 0)
	{
		std::cin >> inputStr;
		if (inputStr == "push")
		{
			std::cin >> inputNum;
			data.push(inputNum);
		}
		else if (inputStr == "pop")
		{
			if (data.empty()) { outputStr += std::to_string(-1) + '\n'; }
			else { outputStr += std::to_string(data.top()) + '\n'; data.pop(); }
		}
		else if (inputStr == "size")
		{
			outputStr += std::to_string(data.size()) + '\n';
		}
		else if (inputStr == "empty")
		{
			if (data.empty()) { outputStr += std::to_string(1) + '\n'; }
			else { outputStr += std::to_string(0) + '\n'; }
		}
		else if (inputStr == "top")
		{
			if (data.empty()) { outputStr += std::to_string(-1) + '\n'; }
			else { outputStr += std::to_string(data.top()) + '\n'; }
		}
	}

	std::cout << outputStr;
}
*/

// PROBLEM 10773
/*
void Problem_10773()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::stack<int> data;
	int K, inputNum, sum = 0;
	std::cin >> K;
	while (K-- > 0)
	{
		std::cin >> inputNum;
		if (inputNum == 0)
		{
			data.pop();
			continue;
		}
		data.push(inputNum);
	}

	while (!data.empty())
	{
		sum += data.top();
		data.pop();
	}

	std::cout << sum;
}
*/

// PROBLEM 9012
/*
void Problem_9012()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, count;
	bool check;
	std::cin >> N;
	std::string inputStr, outputStr;

	while (N-- > 0)
	{
		std::cin >> inputStr;
		count = 0; check = true;
		for (int idx = inputStr.size() - 1; idx >= 0; idx--)
		{
			if (inputStr[idx] == ')'){ count++; }
			else { if (--count < 0) { check = false; break; } }
		}
		if (check && count == 0) { outputStr += "YES\n"; }
		else{ outputStr += "NO\n"; }
	}

	std::cout << outputStr;
}
*/

// PROBLEM 4949
/*
void Problem_4949()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	bool check; std::stack<char> data;
	std::string inputStr, outputStr;
	while (true)
	{
		std::getline(std::cin, inputStr);
		if (inputStr == ".") { break; }
		data = std::stack<char>(); check = true;
		for (int idx = 0; idx < inputStr.size(); idx++)
		{
			if (inputStr[idx] == ')')
			{
				if (!data.empty() && data.top() == '(') { data.pop(); continue; }
				check = false; break;
			}
			else if (inputStr[idx] == ']')
			{
				if (!data.empty() && data.top() == '[') { data.pop(); continue; }
				check = false; break;
			}
			else if (inputStr[idx] == '[' || inputStr[idx] == '(')
			{
				data.emplace(inputStr[idx]);
			}
		}
		if (check && data.empty()) { outputStr += "yes\n"; }
		else { outputStr += "no\n"; }
	}

	std::cout << outputStr;
}
*/

// PROBLEM 17298 Trial (time out)
//
// time complexity : under O(N^2)
// best time complexity : O(N)
/*
int data[1000000];
int res[1000000];

void Problem_17298()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::vector<int> notSets;
	int N;
	std::cin >> N >> data[0];
	notSets.emplace_back(0);
	for (int idx = 1; idx < N; idx++)
	{
		std::cin >> data[idx];

		for (int setIdx = 0; setIdx < notSets.size(); setIdx++)
		{
			if (data[notSets[setIdx]] < data[idx])
			{
				res[notSets[setIdx]] = data[idx];
				notSets.erase(std::remove(notSets.begin(), notSets.end(), notSets[setIdx]));
				setIdx--;
			}
		}
		notSets.emplace_back(idx);
	}

	std::string outputStr;
	for (int idx = 0; idx < N; idx++)
	{
		if (res[idx] != 0) { outputStr += std::to_string(res[idx]) + " "; }
		else { outputStr += std::to_string(-1) + " "; }
	}

	std::cout << outputStr;
}
*/

// PROBLEM 17298
//
// time complexity : under O(N^2)
// best time complexity : O(N)

int res[1000000];

void Problem_17298()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> notSets;
	int N, inputNum;
	std::cin >> N >> inputNum;
	notSets.emplace(std::make_pair(inputNum, 0));
	for (int idx = 1; idx < N; idx++)
	{
		std::cin >> inputNum;

		while (!notSets.empty() && notSets.top().first < inputNum)
		{
			res[notSets.top().second] = inputNum;
			notSets.pop();
		}
		notSets.emplace(std::make_pair(inputNum, idx));
	}

	std::string outputStr;
	for (int idx = 0; idx < N; idx++)
	{
		if (res[idx] != 0) { outputStr += std::to_string(res[idx]) + " "; }
		else { outputStr += std::to_string(-1) + " "; }
	}

	std::cout << outputStr;
}

void ExecuteStack()
{
	//Problem_10828();
	//Problem_10773();
	//Problem_9012();
	//Problem_4949();
	Problem_17298();
}