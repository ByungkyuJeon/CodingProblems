#pragma once

#include <iostream>
#include <string>

// ù �ٿ� ���ĺ� ��ҹ��� �� ����, �׸��� �������� ������ ���ڿ��� ���´�. �� ���ڿ��� ���̴� $10\ 000$�� ���ϴ�.
// ���ڿ��� �� ���̳� �� �ڴ� ������ �ƴ��� ����ȴ�.
// ���ڿ� �ȿ� $D2$�� $d2$�� ����ִٸ� D2�� ����Ѵ�. �� ���ڴ� �ݵ�� �پ��־�� �ϸ�, $D$/$d$�� $2$ ���̿� ������ �־ �� �ȴ�.
// ���� ���ڿ� �ȿ� �ش� ���ڰ� ���ٸ� unrated�� ����Ѵ�.
void Problem_1()
{
	std::string Str;
	std::getline(std::cin, Str);

	if (Str.find("D2") != std::string::npos || Str.find("d2") != std::string::npos)
	{
		std::cout << "D2" << std::endl;
	}
	else
	{
		std::cout << "unrated" << std::endl;
	}
}


void ExecuteYonsei2021()
{
	Problem_1();
}
