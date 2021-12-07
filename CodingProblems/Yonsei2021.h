#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>

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

/*
20XX��, ���� ������ ���ϸ��� ������û ������ ä���ϰ� �ִ� ������� �������濡���� �������� �ý����� �����Ϸ��� �Ѵ�.

20XX���� �������� �������� �Ⱓ ���ȿ��� "���� ��ȯ"�� ���ȴ�!

���� ��ȯ�� �� ����� ���� �ٸ� ������ ��ȯ�ϴ� ������, �� ��� ����� ���ǰ� �־�߸� ���� ��ȯ�� �����ϴ�.

�̶�, ���� ��ȯ�� �Ұ���������, �� ����� ������ ��ȯ�ϰ�, ��ȯ�� ��� �� �ٸ� ����� �� ������ �� �ٸ� ����� ��ȯ�ϴ� ���� ���ȴ�.

ó�� ������ ���ԵǾ��� ���� ���� ��������, ������ ���� ������ �����ϰ� ���� �л����� ������ ��ȯ�ϰų�, ���ϸ����� ���� ���� �����ڵ��� �Ĺ�鿡�� ������ �����ִ� ���� ���� ��Ȳ�� ���� ����� �ִ�.

��� ���� ���� ���������� ���۵Ǿ���. �л����� �����ϰ� ���� ������ $1$���� �־�����, ��ȯ�ϰ� ���� ������ $1$���� �־��� ��, ���� ��ȯ�� ������ ������ ���ϴ� ������ �������� ���ϴ� �ο��� �ּڰ��� ���غ���.


* �Է�

ù �ٿ� �л��� �� N�� �־�����. (1 <= N <= 1,000,000)

�� ��° �ٿ� ���� A_1, A_2, ..., A_N�� �־�����. ���⼭ A_i�� i�� �л��� ���� ��û�� �����̸�, ���ÿ� ��ȯ�ϰ� ���� ������ ��ȣ�� �ǹ��Ѵ�. (1 <= A_i <= 1,000,000)

�� ��° �ٿ� ���� B_1, B_2, ..., B_N�� �־�����. ���⼭ B_i�� i�� �л��� ��ȯ�� ���� �����ϰ� ���� ������ ��ȣ�� �ǹ��Ѵ�. (1 <= B_i <= 1,000,000)

��� �Է��� �������� ���еǾ� �־�����.


* ���

��� �л����� ������ ����� ����ؼ� ���� ��ȯ�� �Ϸ����� ��, ���ϴ� ������ �������� ���ϴ� �л����� ���� ����Ѵ�.
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
