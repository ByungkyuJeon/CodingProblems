#pragma once

#include <iostream>
#include <vector>
#include <array>

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

void ExecuteBaekjoonMathProblems()
{
	Math_2869();
}