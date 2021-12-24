#pragma once


// PROBLEM 3020

int lower_3020[500001];
int upper_3020[500001];
int total_3020[500001];

void Problem_3020()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N, H, inputBuffer[2];
	std::cin >> N >> H;

	for (int i = 0; i < N; i += 2)
	{
		std::cin >> inputBuffer[0] >> inputBuffer[1];
		lower_3020[inputBuffer[0]]++;
		upper_3020[inputBuffer[1]]++;
	}

	for (int i = H - 2; i > 0; i--)
	{
		lower_3020[i] += lower_3020[i + 1];
	}

	total_3020[1] = lower_3020[1];
	total_3020[2] = upper_3020[H - 1] + lower_3020[2];
	for (int i = H - 2; i > 0; i--)
	{
		upper_3020[i] += upper_3020[i + 1];
		total_3020[H - i + 1] = upper_3020[i] + lower_3020[H - i + 1];
	}

	std::make_heap(&total_3020[1], &total_3020[H + 1], [](const int& lhs, const int& rhs) {return lhs > rhs; });
	inputBuffer[0] = total_3020[1];
	inputBuffer[1] = 0;
	int counter = 0;
	while (inputBuffer[0] == total_3020[1] && counter <= H)
	{
		inputBuffer[1]++;
		std::pop_heap(&total_3020[1], &total_3020[H + 1 - counter], [](const int& lhs, const int& rhs) {return lhs > rhs; });
		counter++;
	}

	std::cout << inputBuffer[0] << " " << inputBuffer[1] << '\n';
}

void ExecuteBinarySearch()
{
	Problem_3020();
}