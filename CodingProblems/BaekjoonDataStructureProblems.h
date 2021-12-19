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

int max_heap[50001];
int min_heap[50001];

void Problem_1655_Trial()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N, inputBuffer, maxHeapSize = 0, minHeapSize = 0;
	std::cin >> N;

	std::string outputStr;

	while (N-- > 0)
	{
		std::cin >> inputBuffer;
		if (maxHeapSize == minHeapSize) 
		{ 
			max_heap[maxHeapSize++] = inputBuffer;
			std::push_heap(max_heap, &max_heap[maxHeapSize]);
		}
		else
		{
			min_heap[minHeapSize++] = inputBuffer;
			std::push_heap(min_heap, &min_heap[minHeapSize], [](const int& lhs, const int& rhs) {return lhs > rhs; });
		}
		if ((maxHeapSize > 0 && minHeapSize > 0) && max_heap[0] > min_heap[0])
		{
			std::swap(max_heap[0], min_heap[0]);
			std::push_heap(max_heap, &max_heap[maxHeapSize]);
			std::push_heap(min_heap, &min_heap[minHeapSize], [](const int& lhs, const int& rhs) {return lhs > rhs; });
		}
		
		outputStr += std::to_string(max_heap[0]) + '\n';
	}

	std::cout << outputStr;
}

void Problem_1655()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, inputBuffer, maxTemp, minTemp;
	std::cin >> N;

	std::string outputStr;
	std::priority_queue<int> maxHeap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

	while (N-- > 0)
	{
		std::cin >> inputBuffer;
		if (maxHeap.size() == minHeap.size()){ maxHeap.emplace(inputBuffer); }
		else{ minHeap.emplace(inputBuffer); }
		if ((maxHeap.size() > 0 && minHeap.size() > 0) && maxHeap.top() > minHeap.top())
		{
			maxTemp = maxHeap.top();
			minTemp = minHeap.top();
			maxHeap.pop(); maxHeap.emplace(minTemp);
			minHeap.pop(); minHeap.emplace(maxTemp);
		}

		outputStr += std::to_string(maxHeap.top()) + '\n';
	}

	std::cout << outputStr;
}

void Problem_1715()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, inputBuffer;
	std::cin >> N;

	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

	while (N-- > 0)
	{
		std::cin >> inputBuffer;
		minHeap.emplace(inputBuffer);
	}

	N = 0;
	while (minHeap.size() > 1)
	{
		inputBuffer = minHeap.top();
		minHeap.pop();
		inputBuffer += minHeap.top();
		minHeap.pop();

		N += inputBuffer;
		minHeap.emplace((inputBuffer));
	}

	std::cout << N << '\n';
}

void ExecuteDataStructure()
{
	//Problem_1874();
	//Problem_11279();
	//Problem_1927();
	//Problem_1655();
	Problem_1715();
}