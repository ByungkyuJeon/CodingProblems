#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>

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

/*
20XX년, 전국 유일의 마일리지 수강신청 제도를 채택하고 있는 연세대는 수강변경에서도 혁신적인 시스템을 도입하려고 한다.

20XX년을 기점으로 수강변경 기간 동안에는 "수업 교환"이 허용된다!

수업 교환은 두 사람이 서로 다른 수업을 교환하는 것으로, 두 사람 모두의 동의가 있어야만 수업 교환이 가능하다.

이때, 삼자 교환은 불가능하지만, 두 사람이 수업을 교환하고, 교환한 사람 중 다른 사람이 그 수업을 또 다른 사람과 교환하는 것은 허용된다.

처음 제도가 도입되었을 때는 말이 많았지만, 서로의 전공 수업을 수강하고 싶은 학생들이 수업을 교환하거나, 마일리지가 많이 남는 졸예자들이 후배들에게 수업을 물려주는 등의 좋은 상황이 많이 생기고 있다.

어느 때와 같이 수강변경이 시작되었다. 학생들이 수강하고 싶은 수업이 $1$개씩 주어지고, 교환하고 싶은 수업이 $1$개씩 주어질 때, 수업 교환이 끝나고 본인이 원하는 수업을 수강하지 못하는 인원의 최솟값을 구해보자.


* 입력

첫 줄에 학생의 수 N이 주어진다. (1 <= N <= 1,000,000)

두 번째 줄에 정수 A_1, A_2, ..., A_N이 주어진다. 여기서 A_i는 i번 학생이 현재 신청한 수업이며, 동시에 교환하고 싶은 수업의 번호를 의미한다. (1 <= A_i <= 1,000,000)

세 번째 줄에 정수 B_1, B_2, ..., B_N이 주어진다. 여기서 B_i는 i번 학생이 교환을 통해 수강하고 싶은 수업의 번호를 의미한다. (1 <= B_i <= 1,000,000)

모든 입력은 공백으로 구분되어 주어진다.


* 출력

모든 학생들이 최적의 방법을 사용해서 수업 교환을 완료했을 때, 원하는 수업을 수강하지 못하는 학생들의 수를 출력한다.
*/
void Problem_2_Trial_1()
{
	int N, inputBuffer;
	std::vector<int>::iterator itr;
	std::cin >> N;
	int result = N;

	std::vector<int> A, B;
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		A.emplace_back(inputBuffer);
	}
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		B.emplace_back(inputBuffer);
	}

	for (size_t idx = 0; idx < N; idx++)
	{
		if (A[idx] != B[idx])
		{
			if ((itr = std::find_if(A.begin(), A.end(), [&](int& num)
				{
					return num == B[idx] && num != B[&num - &A[0]];
				})) != A.end())
			{
				std::swap(*itr, A[idx]);
				result--;
			}
		}
		else
		{
			result--;
		}
	}

	std::cout << result << std::endl;
}

void Problem_2_Trial_2()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int N, inputBuffer;
	std::cin >> N;
	int result = 0;

	std::vector<int> A, B;
	std::unordered_map<int, int> countsOfA, countsOfB;

	A.reserve(1000000);
	B.reserve(1000000);
	countsOfA.reserve(1000000);
	countsOfB.reserve(1000000);

	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		A.emplace_back(inputBuffer);
		countsOfA[inputBuffer]++;
	}
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		B.emplace_back(inputBuffer);
		countsOfB[inputBuffer]++;
	}

	for (const auto& elem : countsOfB)
	{
		if ((inputBuffer = elem.second - countsOfA[elem.first]) > 0)
		{
			result += inputBuffer;
		}
	}

	std::cout << result;
}

int countsOfA[1000000], countsOfB[1000000];

void Problem_2_Trial_3()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int N, inputBuffer, maxNum = 0;
	std::cin >> N;
	int result = 0;

	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		countsOfA[inputBuffer]++;
		if (inputBuffer > maxNum) { maxNum = inputBuffer; }
	}
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		countsOfB[inputBuffer]++;
		if (inputBuffer > maxNum) { maxNum = inputBuffer; }
	}

	for (int idx = 0; idx <= maxNum; idx++)
	{
		if ((inputBuffer = countsOfB[idx] - countsOfA[idx]) > 0)
		{
			result += inputBuffer;
		}
	}

	std::cout << result;
}

int counts[1000000];

void Problem_2()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, inputBuffer;
	std::cin >> N;
	int result = 0;

	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		counts[inputBuffer]--;
	}
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		if (counts[inputBuffer]++ >= 0) { result++; }
	}

	std::cout << result;

}


std::string getSuffix(const std::string& str)
{
	return str.substr(str.size() - (str.size() / 2), (str.size() / 2));
}

std::string getPrefix(const std::string& str)
{
	return str.substr(0, (str.size() / 2));
}

std::string getReversedString(const std::string& str)
{
	std::string reversedStr;
	reversedStr.reserve(str.size());

	for (int idx = str.size() - 1; idx >= 0; idx--)
	{
		reversedStr.push_back(str[idx]);
	}

	return reversedStr;
}

bool isAkaraka(const std::string& str)
{
	if (str.size() == 1) { return 1; }

	std::string pfxStr = getPrefix(str);
	std::string sfxStr = getSuffix(str);

	if(str == getReversedString(str)
		&& pfxStr == getReversedString(pfxStr)
		&& sfxStr == getReversedString(sfxStr))
	{
		return isAkaraka(pfxStr) && isAkaraka(sfxStr);
	}

	return 0;
}

void Problem_3()
{
	std::string inputStr;
	std::cin >> inputStr;

	if (isAkaraka(inputStr)) { std::cout << "AKARAKA"; }
	else { std::cout << "IPSELENTI"; }
}

void ExecuteYonsei2021()
{
	//Problem_1();
	//Problem_2();
	Problem_3();
}
