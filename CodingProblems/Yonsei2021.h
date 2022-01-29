#pragma once

#include"TimeChecker.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <utility>

// PROBLEM 23303
/*
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
*/

// PROBLEM 23005
/*
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
*/

// PROBLEM 23304
/*
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

void Problem_23304()
{
	std::string inputStr;
	std::cin >> inputStr;

	if (isAkaraka(inputStr)) { std::cout << "AKARAKA"; }
	else { std::cout << "IPSELENTI"; }
}
*/

// PROBLEM 23307
/*
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
*/

// PROBLEM 23309
/*
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
*/


void ExecuteYonsei2021()
{
	//Problem_1();
	//Problem_2();
	//Problem_3();
	//Problem_4();

	//Problem_23309();
}
