#pragma once

#include"TimeChecker.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <utility>

// 첫 줄에 알파벳 대소문자 및 숫자, 그리고 공백으로 구성된 문자열이 들어온다. 이 문자열의 길이는 $10\ 000$자 이하다.
// 문자열의 맨 앞이나 맨 뒤는 공백이 아님이 보장된다.
// 문자열 안에 $D2$나 $d2$가 들어있다면 D2를 출력한다. 두 글자는 반드시 붙어있어야 하며, $D$/$d$와 $2$ 사이에 공백이 있어도 안 된다.
// 만약 문자열 안에 해당 문자가 없다면 unrated를 출력한다.
void Problem_23303()
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
void Problem_23305_Trial_1()
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

void Problem_23305_Trial_2()
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

void Problem_23305_Trial_3()
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

void Problem_23305()
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

/*
* AKARAKA(아카라카)는 컴퓨터 과학적 관점으로 바라봤을 때, 튜링도 기립 박수를 치고 갈 가히 최고의 구호라 할 수 있다. AKARAKA는 그 자체로도 팰린드롬이고, 접두사이자 접미사인 AKA가 또한 팰린드롬이기 때문이다.

신촌에서는 AKARAKA같은 특성을 가진 팰린드롬을, 아카라카 팰린드롬이라 아래와 같이 정의한다.

문자열 $S$가 팰린드롬이다. 팰린드롬이란 거꾸로 뒤집어 읽어도 같은 문자열을 뜻한다.
문자열 $S$의 길이를 $|S|$라 할 때, 
 
$\lfloor\frac{|S|}{2}\rfloor$ 길이의 접두사와 접미사가 모두 아카라카 팰린드롬이다. 만약 $|S| = 1$이면, $S$는 아카라카 팰린드롬이다.
임의의 문자열이 주어졌을 때, 그 문자열이 아카라카 팰린드롬인지 알아보자. 만약 알아내지 못하면, 졸업할 때까지 아카라카를 못 갈지도 모른다!
*/
void Problem_23304()
{
	std::string inputStr;
	std::cin >> inputStr;

	if (isAkaraka(inputStr)) { std::cout << "AKARAKA"; }
	else { std::cout << "IPSELENTI"; }
}

/*
국렬이는 연세대학교 신입생 프로그래밍 경진대회를 개최한 기념으로 공학관 근처 $N \times N$ 크기의 운동장에서 화석 발굴 이벤트를 진행하려고 했다. 
그러나 공학관 내의 무수히 많은 실험으로 인해 운동장의 일부가 인체에 매우 위험한 물질로 오염되었기에 이 이벤트는 취소되었다. 
다행히 우수한 연세대학교 신입생들의 도움을 받아서 오염되지 않은 흙을 공학관 근처 언덕으로 옮기는 작업을 마무리했다. 
덕분에 국렬이는 드디어 화석 발굴 이벤트를 진행할 수 있게 되었다.

화석은 그림과 같이 정사각형 크기의 달팽이 형태로, 한 변의 길이는 무조건 $4k+1$ 꼴이다. 화석의 중심은 위에서 $2k+1$칸, 왼쪽에서 $2k+1$칸 떨어진 칸을 의미한다. ($k$는 양의 정수)

화석 발굴 이벤트는 공학관 근처 운동장에 묻힌 화석을 찾는 이벤트이다. 당신은 주어진 흙 속에서 화석들을 전부 찾아내야 한다.

첫 번째 줄에 운동장의 한 변의 길이를 의미하는 양의 정수 $N$이 주어진다. ($5 \le N \le 1\,250$)

두 번째 줄부터 $N$개의 줄에 걸쳐서 운동장에 대한 정보가 주어진다. .은 흙만 있는 칸을 의미하고, #은 화석이 있는 칸을 의미한다. 입력으로 들어오는 화석의 형태는 언제나 달팽이 형태로만 나온다.

운동장에 최소 $1$개 이상의 화석이 묻혀있으며, 화석들은 붙어있거나 운동장 밖으로 빠져나온 경우는 주어지지 않는다.

첫 번째 줄에 화석의 개수를 출력한다.

두 번째 줄부터 각 줄에 화석의 중심의 위치의 행 번호와 열 번호, 화석의 한 변의 길이, 그리고 화석의 방향을 출력한다.
화석의 정보는 화석의 중심 위치의 행 번호가 작은 것부터, 행 번호가 같은 경우 열 번호가 작은 것부터 출력한다.
*/
struct Fossil
{
public:

	Fossil() : mX{ 0 }, mY{ 0 }, mLength{ 0 }, mDirection{ "" }{}
	Fossil(const std::pair<int, int>& inCenter, int inLength) : mX{ inCenter.first }, mY{ inCenter.second }, mLength{ inLength }, mDirection{ "" }{}

	int mX;
	int mY;
	int mLength;
	std::string mDirection;
};

bool operator<(const Fossil& lhs, const Fossil& rhs)
{
	if (lhs.mX == rhs.mX)
	{
		return lhs.mY < rhs.mY;
	}
	else
	{
		return lhs.mX < rhs.mX;
	}
}

int N;
std::array<int, 4> columnMovement{ 1, -1, 0, 0 };
std::array<int, 4> rowMovement{ 0, 0, 1, -1 };
std::vector<std::string> field;
std::vector<Fossil> fossils;
std::vector<int> directions;
std::vector<int> lengths;
std::pair<int, int> upperLeftPoint = std::make_pair(0, 0);

int getLength(int x, int y)
{
	return 1;
}

void findPrimaryDot(int x, int y)
{
	if (x + 1 >= N || x - 1 < 0
		|| y + 1 >= N || y - 1 < 0)
	{
		return;
	}

	std::pair<int, int> secondaryDot = std::make_pair(-1, -1);

	// check if tile is primary dot
	int dotCount = 0;
	for (int movementIdx = 0; movementIdx < 4; movementIdx++)
	{
		if (field[x + rowMovement[movementIdx]][y + columnMovement[movementIdx]] == '.')
		{
			if (dotCount++ > 0)
			{
				return;
			}
			secondaryDot.first = x + rowMovement[movementIdx];
			secondaryDot.second = y + columnMovement[movementIdx];
		}
	}

	Fossil tempFossil;
	std::pair<int, int> thirdDot = std::make_pair(-1, -1);

	// primary, secondary dot found
	if (x == secondaryDot.first)
	{
		if (y > secondaryDot.second)
		{
			tempFossil.mDirection.append("U");
		}
		else
		{
			tempFossil.mDirection.append("D");
		}

		for (int movementIdx = 0; movementIdx < 2; movementIdx++)
		{
			if (field[x + rowMovement[movementIdx]][y + columnMovement[movementIdx]] == '.')
			{
				thirdDot.first = x + rowMovement[movementIdx];
				thirdDot.second = y + columnMovement[movementIdx];
				if(movementIdx == 0){ tempFossil.mDirection.append("R"); }
				else { tempFossil.mDirection.append("L"); }
			}
		}

		tempFossil.mX = thirdDot.first - (secondaryDot.first - x);
		tempFossil.mY = thirdDot.second - (secondaryDot.second - y);

		// get length
	}
	else
	{
		if (y > secondaryDot.second)
		{
			tempFossil.mDirection.append("R");
		}
		else
		{
			tempFossil.mDirection.append("L");
		}

		for (int movementIdx = 2; movementIdx < 4; movementIdx++)
		{
			if (field[x + rowMovement[movementIdx]][y + columnMovement[movementIdx]] == '.')
			{
				thirdDot.first = x + rowMovement[movementIdx];
				thirdDot.second = y + columnMovement[movementIdx];
				if (movementIdx == 2) { tempFossil.mDirection.append("D"); }
				else { tempFossil.mDirection.append("U"); }
			}
		}

		tempFossil.mX = thirdDot.first - (secondaryDot.first - x);
		tempFossil.mY = thirdDot.second - (secondaryDot.second - y);

		// get length
	}

	fossils.emplace_back(std::move(tempFossil));
}

void Problem_23307_Trial()
{
	std::cin >> N;
	std::string inputBuffer;
	std::getline(std::cin, inputBuffer);

	for (int counter = N; counter > 0; counter--)
	{
		std::getline(std::cin, inputBuffer);
		field.emplace_back(std::move(inputBuffer));
	}

	for (size_t outerIdx = 0; outerIdx < N; outerIdx++)
	{
		for (size_t innerIdx = 0; innerIdx < N; innerIdx++)
		{
			findPrimaryDot(outerIdx, innerIdx);
		}
	}

	for (const auto& elem : fossils)
	{
		std::cout << elem.mX << " " << elem.mY << " " << elem.mLength << " " << elem.mDirection << "\n";
	}
}

int ReverseDirection(int inDirec)
{
	switch (inDirec)
	{
	case(0):
		return 1;
	case(1):
		return 0;
	case(2):
		return 3;
		break;
	case(3):
		return 2;
		break;
	default:
		return -1;
	}
}

void SetDirection(std::string& str, int inDirec)
{
	switch (inDirec)
	{
	case(0):
		str.append("R");
		break;
	case(1):
		str.append("L");
		break;
	case(2):
		str.append("D");
		break;
	case(3):
		str.append("U");
		break;
	default:
		break;
	}
}

std::pair<int, int> findCenter(const std::pair<int, int>& inNextPoint)
{
	int LoopCounter = 0;

	for (int direnctionIdx = *(directions.end() - 1);;)
	{
		if (!(inNextPoint.first + rowMovement[direnctionIdx] < 0 || inNextPoint.first + rowMovement[direnctionIdx] >= N
			|| inNextPoint.second + columnMovement[direnctionIdx] < 0 || inNextPoint.second + columnMovement[direnctionIdx] >= N)
			&& field[inNextPoint.first + rowMovement[direnctionIdx]][inNextPoint.second + columnMovement[direnctionIdx]] == '#')
		{
			field[inNextPoint.first][inNextPoint.second] = '.';

			if (direnctionIdx != *(directions.end() - 1))
			{
				directions.emplace_back(direnctionIdx);
				lengths.emplace_back(2);
			}
			else
			{
				(*(lengths.end() - 1))++;
			}
			if (upperLeftPoint.first > inNextPoint.first + rowMovement[direnctionIdx]) { upperLeftPoint.first = inNextPoint.first + rowMovement[direnctionIdx]; }
			if (upperLeftPoint.second > inNextPoint.second + columnMovement[direnctionIdx]) { upperLeftPoint.second = inNextPoint.second + columnMovement[direnctionIdx]; }

			return findCenter(std::make_pair(inNextPoint.first + rowMovement[direnctionIdx], inNextPoint.second + columnMovement[direnctionIdx]));
		}

		LoopCounter++;

		if (LoopCounter == 4)
		{
			break;
		}
		else if(direnctionIdx == 3)
		{
			direnctionIdx = 0;
		}
		else
		{
			direnctionIdx++;
		}
	}
	field[inNextPoint.first][inNextPoint.second] = '.';
	return inNextPoint;
}

void findEdge(int x, int y)
{
	int dotCount = 0;
	std::pair<int, int> nextPoint = std::make_pair(-1, -1);
	upperLeftPoint.first = x;
	upperLeftPoint.second = y;

	for (int direnctionIdx = 0; direnctionIdx < 4; direnctionIdx++)
	{
		if (x + rowMovement[direnctionIdx] < 0 || x + rowMovement[direnctionIdx] >= N
			|| y + columnMovement[direnctionIdx] < 0 || y + columnMovement[direnctionIdx] >= N)
		{
			dotCount++;
		}
		else if (field[x + rowMovement[direnctionIdx]][y + columnMovement[direnctionIdx]] == '.')
		{
			dotCount++;
		}
		else
		{
			nextPoint.first = x + rowMovement[direnctionIdx];
			nextPoint.second = y + columnMovement[direnctionIdx];
			directions.emplace_back(direnctionIdx);
			lengths.emplace_back(2);
			if (upperLeftPoint.first > nextPoint.first) { upperLeftPoint.first = nextPoint.first; }
			if (upperLeftPoint.second > nextPoint.second) { upperLeftPoint.second = nextPoint.second; }
		}
	}

	if (dotCount != 3) 
	{ 
		directions.clear();
		lengths.clear();
		return; 
	}

	field[x][y] = '.';
	std::pair<int, int> endPoint = findCenter(std::make_pair(nextPoint.first, nextPoint.second));
	int distanceToCenter = 0;

	if (*(lengths.begin()) > *(lengths.end() - 1))
	{
		distanceToCenter = (((lengths[0] - 1) / 4) * 2) + 1;
		fossils.emplace_back(Fossil(std::make_pair(upperLeftPoint.first + distanceToCenter, upperLeftPoint.second + distanceToCenter), lengths[0]));

		SetDirection((*(fossils.end() - 1)).mDirection, ReverseDirection(*(directions.end() - 1)));
		SetDirection((*(fossils.end() - 1)).mDirection, *(directions.end() - 2));
	}
	else
	{
		distanceToCenter = ((((*(lengths.end() - 1)) - 1) / 4) * 2) + 1;
		fossils.emplace_back(Fossil(std::make_pair(upperLeftPoint.first + distanceToCenter, upperLeftPoint.second + distanceToCenter), *(lengths.end() - 1)));

		SetDirection((*(fossils.end() - 1)).mDirection, *(directions.begin()));
		SetDirection((*(fossils.end() - 1)).mDirection, ReverseDirection (*(directions.begin() + 1)));
	}

	directions.clear();
	lengths.clear();
}

void Problem_23307()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> N;
	std::string inputBuffer;
	std::cin.ignore();

	for (int counter = N; counter > 0; counter--)
	{
		std::getline(std::cin, inputBuffer);
		field.emplace_back(std::move(inputBuffer));
	}

	for (size_t x = 0; x < N; x++)
	{
		for (size_t y = 0; y < N; y++)
		{
			if (field[x][y] == '#')
			{
				findEdge(x, y);
			}
		}
	}

	std::sort(fossils.begin(), fossils.end());

	std::cout << fossils.size() << "\n";

	for (const auto& elem : fossils)
	{
		std::cout << elem.mX << " " << elem.mY << " " << elem.mLength << " " << elem.mDirection << "\n";
	}
}

void Problem_23309_Trial_1()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(NULL);

	int N, M, inputStationBuffer;
	std::string inputWorkBuffer;
	std::pair<int, int> workStationsBuffer;
	std::cin >> N >> M;

	std::list<int> stations;

	for (size_t idx = N; idx > 0; idx--)
	{
		std::cin >> inputStationBuffer;
		stations.emplace_back(inputStationBuffer);
	}

	std::list<int>::iterator tempItr_1, tempItr_2;

	while (M-- > 0)
	{
		std::cin >> inputWorkBuffer;

		if (inputWorkBuffer == "BN")
		{
			std::cin >> workStationsBuffer.first >> workStationsBuffer.second;
			if (std::find(stations.begin(), stations.end(), workStationsBuffer.second) == stations.end())
			{
				tempItr_1 = std::find(stations.begin(), stations.end(), workStationsBuffer.first);

				if ((tempItr_2 = std::next(tempItr_1, 1)) == stations.end())
				{
					tempItr_2 = stations.begin();
				}

				std::cout << *tempItr_2 << "\n";
				stations.emplace(tempItr_2, workStationsBuffer.second);
			}
		}
		else if (inputWorkBuffer == "BP")
		{
			std::cin >> workStationsBuffer.first >> workStationsBuffer.second;
			if (std::find(stations.begin(), stations.end(), workStationsBuffer.second) == stations.end())
			{
				tempItr_1 = std::find(stations.begin(), stations.end(), workStationsBuffer.first);

				if (tempItr_1 == stations.begin())
				{
					tempItr_2 = std::next(stations.end(), -1);
				}
				else
				{
					tempItr_2 = std::next(tempItr_1, -1);
				}

				std::cout << *tempItr_2 << "\n";
				stations.emplace(tempItr_1, workStationsBuffer.second);
			}
		}
		else if (inputWorkBuffer == "CN")
		{
			std::cin >> workStationsBuffer.first;
			tempItr_1 = std::find(stations.begin(), stations.end(), workStationsBuffer.first);

			if ((tempItr_2 = std::next(tempItr_1, 1)) == stations.end())
			{
				tempItr_2 = stations.begin();
			}

			std::cout << *tempItr_2 << "\n";

			stations.erase(tempItr_2);
		}
		else if (inputWorkBuffer == "CP")
		{
			std::cin >> workStationsBuffer.first;
			tempItr_1 = std::find(stations.begin(), stations.end(), workStationsBuffer.first);

			if (tempItr_1 == stations.begin())
			{
				tempItr_2 = std::next(stations.end(), -1);
			}
			else
			{
				tempItr_2 = std::next(tempItr_1, -1);
			}

			std::cout << *tempItr_2 << "\n";

			stations.erase(tempItr_2);
		}
	}
}

class Station
{
public:

	Station() :mID{ 0 }, Next{ NULL }, Prev{ NULL }{}
	Station(Station* inPrev, Station* inNext, int id) : mID{ id }, Next{ inNext }, Prev{ inPrev }{}

	Station* Remove()
	{
		Prev->Next = Next;
		Next->Prev = Prev;
		return this;
	}

	int mID;
	Station* Next;
	Station* Prev;
};

double consumedTime;
std::string io;
std::unordered_map<int, Station*> lookupTable;

std::chrono::steady_clock::time_point startTime;
std::chrono::steady_clock::time_point endTime;

void Problem_23309()
{
	// fast io
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M, inputStationBuffer;
	std::string inputWorkBuffer;

	Station* baseStation = new Station();
	Station* currentStationBuffer = 0;

	std::cin >> N >> M;
	std::cin >> inputStationBuffer;

	startTime = std::chrono::high_resolution_clock::now();

	lookupTable[(baseStation->mID = inputStationBuffer)] = baseStation;
	currentStationBuffer = baseStation;

	for (size_t idx = N - 1; idx > 0; idx--)
	{
		std::cin >> inputStationBuffer;
		currentStationBuffer->Next = new Station(currentStationBuffer, NULL, inputStationBuffer);
		currentStationBuffer = currentStationBuffer->Next;
		lookupTable[inputStationBuffer] = currentStationBuffer;
	}

	currentStationBuffer->Next = baseStation;
	baseStation->Prev = currentStationBuffer;


	while (M-- > 1)
	{
		std::cin >> inputWorkBuffer >> inputStationBuffer;

		currentStationBuffer = lookupTable[inputStationBuffer];

		if (inputWorkBuffer == "BN")
		{
			std::cin >> inputStationBuffer;

			io.append(std::to_string(currentStationBuffer->Next->mID) + '\n');

			currentStationBuffer->Next = new Station(currentStationBuffer, currentStationBuffer->Next, inputStationBuffer);
			currentStationBuffer->Next->Next->Prev = currentStationBuffer->Next;
			lookupTable[inputStationBuffer] = currentStationBuffer->Next;
		}
		else if (inputWorkBuffer == "BP")
		{
			std::cin >> inputStationBuffer;

			io.append(std::to_string(currentStationBuffer->Prev->mID) + '\n');

			currentStationBuffer->Prev = new Station(currentStationBuffer->Prev, currentStationBuffer, inputStationBuffer);
			currentStationBuffer->Prev->Prev->Next = currentStationBuffer->Prev;
			lookupTable[inputStationBuffer] = currentStationBuffer->Prev;
		}
		else if (inputWorkBuffer == "CN")
		{
			io.append(std::to_string(currentStationBuffer->Next->mID) + '\n');

			lookupTable.erase(currentStationBuffer->Next->mID);
			if (currentStationBuffer->Next == baseStation) { baseStation = currentStationBuffer; }
			delete(currentStationBuffer->Next->Remove());
		}
		else if (inputWorkBuffer == "CP")
		{
			io.append(std::to_string(currentStationBuffer->Prev->mID) + '\n');

			lookupTable.erase(currentStationBuffer->Prev->mID);
			if (currentStationBuffer->Prev == baseStation) { baseStation = currentStationBuffer; }
			delete(currentStationBuffer->Prev->Remove());
		}
	}

	std::cout << io;

	endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> timeSpan = endTime - startTime;
	std::cout << "consumed time : " << timeSpan.count() << " ms" << std::endl;
}


void ExecuteYonsei2021()
{
	//Problem_1();
	//Problem_2();
	//Problem_3();
	//Problem_4();

	Problem_23309();
}
