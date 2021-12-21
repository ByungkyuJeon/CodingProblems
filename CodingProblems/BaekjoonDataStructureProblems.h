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

struct comp
{
	bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
	{
		return lhs.second < rhs.second;
	}
};

void Problem_1202()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N, K;
	long long result = 0;
	int inputBuffer[2];
	std::cin >> N >> K;
	
	std::unordered_map<int, std::vector<std::pair<int, int>>> waitingJewels;
	std::priority_queue<int, std::vector<int>, std::greater<int>> waitingKeyQueue;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp> jewels;
	std::priority_queue<int, std::vector<int>, std::greater<int>> bags;

	while (N-- > 0)
	{
		std::cin >> inputBuffer[0] >> inputBuffer[1];
		if (inputBuffer[0] == 0)
		{
			jewels.emplace(std::make_pair(inputBuffer[0], inputBuffer[1]));
		}
		else
		{
			waitingJewels[inputBuffer[0]].emplace_back(std::make_pair(inputBuffer[0], inputBuffer[1]));
		}
	}

	while (K-- > 0)
	{
		std::cin >> inputBuffer[0];
		bags.emplace(inputBuffer[0]);
	}

	for (const auto& elem : waitingJewels)
	{
		waitingKeyQueue.emplace(elem.first);
	}

	while (!bags.empty())
	{
		while (!waitingKeyQueue.empty() && waitingKeyQueue.top() <= bags.top())
		{
			for (const auto& elem : waitingJewels[waitingKeyQueue.top()])
			{
				jewels.emplace(elem);
			}
			waitingKeyQueue.pop();
		}

		if (jewels.empty()) { bags.pop(); continue; }
		result += jewels.top().second;
		bags.pop();
		jewels.pop();
	}

	std::cout << result << '\n';

}

int data_6549[100001];
int segTree_6549[400000];
long long result_6549;
long long area;
int N_6549;

int makeSegTree_6549(int start, int end, int node)
{
	if (start == end) { return (segTree_6549[node] = start); }
	int lhSeg, rhSeg;
	int mid = start + ((end - start) / 2);

	return (segTree_6549[node] = data_6549[(lhSeg = makeSegTree_6549(start, mid, 2 * node))] < data_6549[(rhSeg = makeSegTree_6549(mid + 1, end, 2 * node + 1))] ? lhSeg : rhSeg);
}

int getSegMin_6549(int start, int end, int node, int left, int right)
{
	if (right < start || left > end) return 0;

	if (left <= start && right >= end) { return segTree_6549[node]; }
	int mid = start + ((end - start) / 2);
	int lhSeg = getSegMin_6549(start, mid, 2 * node, left, right);
	int rhSeg = getSegMin_6549(mid + 1, end, 2 * node + 1, left, right);
	return data_6549[lhSeg] < data_6549[rhSeg] ? lhSeg : rhSeg;
}

void process_6549(int startIdx, int EndIdx)
{
	if (startIdx > EndIdx) return;
	if(startIdx == EndIdx)
	{
		if (startIdx > 0 && startIdx <= N_6549) { if (result_6549 < data_6549[startIdx]) { result_6549 = data_6549[startIdx]; } }
		else { if (result_6549 < data_6549[EndIdx]) { result_6549 = data_6549[EndIdx]; } }
		return;
	}

	int minIdx = getSegMin_6549(1, N_6549, 1, startIdx, EndIdx);

	if (result_6549 < (area = (long long)data_6549[minIdx] * (EndIdx - startIdx + 1))) { result_6549 = area; }
	
	process_6549(startIdx, minIdx - 1);
	process_6549(minIdx + 1, EndIdx);
}

// 히스토그램 최대 넓이 문제
void Problem_6549()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string outputStr;
	data_6549[0] = INT_MAX;

	while (true)
	{
		std::cin >> N_6549;
		if (N_6549 == 0) { break; }
		for(int i = 1; i <= N_6549; i++){ std::cin >> data_6549[i]; }
		result_6549 = 0;
		makeSegTree_6549(1, N_6549, 1);
		process_6549(1, N_6549);
		outputStr += std::to_string(result_6549) + '\n';
	}

	std::cout << outputStr;
}

void ExecuteDataStructure()
{
	//Problem_1874();
	//Problem_11279();
	//Problem_1927();
	//Problem_1655();
	//Problem_1715();
	//Problem_1202();
	Problem_6549();
}