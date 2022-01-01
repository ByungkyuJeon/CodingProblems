#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <array>
#include <cmath>

// PROBLEM 2869
/*
// �� ���� �����̰� �ִ�.�� �����̴� ���̰� V������ ���� ���븦 �ö� ���̴�.
// �����̴� ���� A���� �ö� �� �ִ�.������, �㿡 ���� �ڴ� ���� B���� �̲�������.��, ���� �ö� �Ŀ��� �̲������� �ʴ´�.
// �����̰� ���� ���븦 ��� �ö󰡷���, ��ĥ�� �ɸ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ù° �ٿ� �� ���� A, B, V�� �������� ���еǾ �־�����. (1 �� B < A �� V �� 1, 000, 000, 000)
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
// 19���� ���� ������ �츣�� ��������Ű�� ����Ŭ���� ������ �� �ý� �������� ����ߴ�.
// �ý� �����п��� �� �� T1(x1, y1), T2(x2, y2) ������ �Ÿ��� ������ ���� ���� �� �ִ�.
// D(T1, T2) = | x1 - x2 | +| y1 - y2 |
// �� �� ������ �Ÿ��� ������ ������ ���Ǵ� ��Ŭ���� �����п����� ���ǿ� ����.
// ���� �ý� �����п��� ���� ���Ǵ� ��Ŭ���� �����п��� ���� ���ǿ� ����.
// ��: ��� ���� � ������ �Ÿ��� ������ ������ ����
// ������ R�� �־����� ��, ��Ŭ���� �����п��� ���� ���̿�, �ý� �����п��� ���� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ù° �ٿ� ������ R�� �־�����.R�� 10, 000���� �۰ų� ���� �ڿ����̴�.
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

// ��Ŭ���� ����
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