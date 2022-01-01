#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <array>
#include <cmath>

// PROBLEM 2869
/*
// 땅 위에 달팽이가 있다.이 달팽이는 높이가 V미터인 나무 막대를 올라갈 것이다.
// 달팽이는 낮에 A미터 올라갈 수 있다.하지만, 밤에 잠을 자는 동안 B미터 미끄러진다.또, 정상에 올라간 후에는 미끄러지지 않는다.
// 달팽이가 나무 막대를 모두 올라가려면, 며칠이 걸리는지 구하는 프로그램을 작성하시오.
// 첫째 줄에 세 정수 A, B, V가 공백으로 구분되어서 주어진다. (1 ≤ B < A ≤ V ≤ 1, 000, 000, 000)
void Math_2869()
{
	int A, B, V;
	std::cin >> A >> B >> V;

	int consumedDays = ((V - A) / (A - B));
	V -= consumedDays * (A - B);

	std::cout << V << std::endl;

	while (true)
	{
		consumedDays++;
		if ((V -= A) <= 0)
		{
			break;
		}

		V += B;
	}

	std::cout << consumedDays << std::endl;
}
*/

// PROBLEM 3053
/*
// 19세기 독일 수학자 헤르만 민코프스키는 비유클리드 기하학 중 택시 기하학을 고안했다.
// 택시 기하학에서 두 점 T1(x1, y1), T2(x2, y2) 사이의 거리는 다음과 같이 구할 수 있다.
// D(T1, T2) = | x1 - x2 | +| y1 - y2 |
// 두 점 사이의 거리를 제외한 나머지 정의는 유클리드 기하학에서의 정의와 같다.
// 따라서 택시 기하학에서 원의 정의는 유클리드 기하학에서 원의 정의와 같다.
// 원: 평면 상의 어떤 점에서 거리가 일정한 점들의 집합
// 반지름 R이 주어졌을 때, 유클리드 기하학에서 원의 넓이와, 택시 기하학에서 원의 넓이를 구하는 프로그램을 작성하시오.
// 첫째 줄에 반지름 R이 주어진다.R은 10, 000보다 작거나 같은 자연수이다.
void Math_3053()
{
	int R;
	std::cin >> R;

	std::cout << std::fixed;
	std::cout.precision(6);
	std::cout << pow(R, 2) * M_PI << '\n' << 2 * pow(R, 2);
}
*/

// PROBLEM 4342
/*
bool process_4342(int bigger, int smaller,  bool turn)
{
	if (bigger % smaller == 0 || bigger - smaller > smaller) { return turn; }

	return process_4342(smaller, bigger - smaller, !turn);
}

// 유클리드 게임
void Math_4342()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int gameNum[2];
	std::string outputStr;

	while (true)
	{
		std::cin >> gameNum[0] >> gameNum[1];
		if (!gameNum[0] && !gameNum[1]) { break; }

		if (gameNum[0] < gameNum[1]) { std::swap(gameNum[0], gameNum[1]); }
		
		if (process_4342(gameNum[0], gameNum[1], 1)) { outputStr += "A wins\n"; }
		else { outputStr += "B wins\n"; }
	}

	std::cout << outputStr;
}
*/

void ExecuteBaekjoonMathProblems()
{
	//Math_2869();
	//Math_3053();
	//Math_4342();
}