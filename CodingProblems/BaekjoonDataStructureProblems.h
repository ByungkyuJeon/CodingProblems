#pragma once

#include <stack>

void Problem_1874()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, inputBuffer, currentNum = 1;
	std::cin >> N;
	std::stack<int> stack_1874;
	std::string outputs_1874;
	bool isError = 0;

	for (size_t idx = 0; idx < N; idx++)
	{
		std::cin >> inputBuffer;

		while (currentNum <= inputBuffer)
		{
			outputs_1874.append("+\n");
			stack_1874.push(currentNum++);
		}

		if (stack_1874.top() == inputBuffer)
		{
			stack_1874.pop();
			outputs_1874.append("-\n");
		}
		else
		{
			isError = true;
			break;
		}
	}

	if (isError)
	{
		std::cout << "NO";
	}
	else
	{
		std::cout << outputs_1874;
	}
}

void ExecuteDataStructure()
{
	Problem_1874();
}