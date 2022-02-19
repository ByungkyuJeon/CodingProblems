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

void ExecuteStack()
{
	//Problem_10828();
}