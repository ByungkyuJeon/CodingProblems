#pragma once

#include <iostream>
#include <string>

// 첫 줄에 알파벳 대소문자 및 숫자, 그리고 공백으로 구성된 문자열이 들어온다. 이 문자열의 길이는 $10\ 000$자 이하다.
// 문자열의 맨 앞이나 맨 뒤는 공백이 아님이 보장된다.
// 문자열 안에 $D2$나 $d2$가 들어있다면 D2를 출력한다. 두 글자는 반드시 붙어있어야 하며, $D$/$d$와 $2$ 사이에 공백이 있어도 안 된다.
// 만약 문자열 안에 해당 문자가 없다면 unrated를 출력한다.
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
