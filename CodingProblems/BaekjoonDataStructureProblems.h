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

void Problem_11279()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N, inputBuffer;
	std::cin >> N;

	std::string outputStr;
	std::vector<int> heap;

	while (N-- > 0)
	{
		std::cin >> inputBuffer;
		if (inputBuffer)
		{
			heap.emplace_back(inputBuffer);
			std::push_heap(heap.begin(), heap.end());
			continue;
		}
		else
		{
			if (heap.size() > 0)
			{
				outputStr += std::to_string(heap[0]) + '\n';
				std::pop_heap(heap.begin(), heap.end());
				heap.pop_back();
				continue;
			}
			outputStr += "0\n";
		}
		
	}

	std::cout << outputStr;
}

void Problem_1927()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N, inputBuffer;
	std::cin >> N;

	std::string outputStr;
	std::vector<int> heap;

	while (N-- > 0)
	{
		std::cin >> inputBuffer;
		if (inputBuffer)
		{
			heap.emplace_back(inputBuffer);
			std::push_heap(heap.begin(), heap.end(), [](const int& lhs, const int& rhs) { return lhs > rhs; });
			continue;
		}
		else
		{
			if (heap.size() > 0)
			{
				outputStr += std::to_string(heap[0]) + '\n';
				std::pop_heap(heap.begin(), heap.end(), [](const int& lhs, const int& rhs) { return lhs > rhs; });
				heap.pop_back();
				continue;
			}
			outputStr += "0\n";
		}

	}

	std::cout << outputStr;
}

void ExecuteDataStructure()
{
	//Problem_1874();
	//Problem_11279();
	Problem_1927();
}