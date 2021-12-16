#pragma once

#include <set>
#include <map>
#include <unordered_set>

void primeFactorization(std::set<int>& outArr, int inNum)
{
	int numBuffer = inNum;
	int primeBuffer = 2;
	while (numBuffer != 1)
	{
		if (numBuffer % primeBuffer == 0)
		{
			outArr.insert(primeBuffer);
			numBuffer /= primeBuffer;
		}
		else
		{
			primeBuffer++;
		}
	}
}

void Problem_4354()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int N = 10;
	std::vector<int> possibleNs;
	std::string inputStr;
	std::string sStr;
	std::string outputStr;
	bool checker = true;

	while (N-- > 0)
	{
		std::getline(std::cin, inputStr);
		if (inputStr == ".") { break; }
		possibleNs.clear();
		possibleNs.emplace_back(inputStr.size());
		checker = true;

		for (int nNum = inputStr.size() / 2; nNum > 0;)
		{
			if (*(possibleNs.end() - 1) % nNum != 0) { nNum--; continue; }
			if ((sStr = inputStr.substr(0, nNum)) == inputStr.substr(nNum, nNum))
			{
				for (int range = nNum; range + 2 * nNum <= *(possibleNs.end() - 1); range += nNum)
				{
					if (sStr != inputStr.substr(range + nNum, nNum))
					{
						checker = false;
						break;
					}
				}

				if (!checker) { break; }
				possibleNs.emplace_back(nNum);
				nNum = nNum / 2;
				continue;
			}

			nNum--;
		}

		outputStr.append(std::to_string(inputStr.size() / (*std::min_element(possibleNs.begin(), possibleNs.end()))) + '\n');
	}

	std::cout << outputStr;
}

std::string GetFullStr(std::string str, int count)
{
	std::string result;
	while (count-- > 0)
	{
		result.append(str);
	}
	return result;
}

void Problem_18441_MultiMaxLengthVersion()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T, counter = 1;
	std::cin >> T;
	std::cin.ignore();

	std::string S;
	std::string outputStr;
	std::string subStr;
	std::unordered_map<std::string, int> strResult;

	while (T-- > 0)
	{
		std::getline(std::cin, S);

		strResult.clear();
		// 검사 범위 결정
		for (int range = S.size() / 2; range > 0; range--)
		{
			// 검사 오브셋 결정
			for (int offset = 0; offset + 2 * range <= S.size(); offset++)
			{
				// 검사 중복 확인
				if (strResult.find((subStr = S.substr(offset, range))) != strResult.end()) { continue; }
				// 검사
				for (int operandOffset = offset + range; operandOffset + range <= S.size(); operandOffset++)
				{
					if (subStr == S.substr(operandOffset, range))
					{
						strResult[subStr]++;
					}
				}
			}
		}

		// 제곱 문자열 존재 여부 체크
		if(strResult.size() == 0)
		{ 
			outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(0) + '\n');
			continue;
		}

		// 최대 제곱 문자열 찾기
		auto maxItr = std::max_element(strResult.begin(), strResult.end(), [](const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs) {
			int lhsCount = lhs.first.size() * (lhs.second + 1);
			int rhsCount = rhs.first.size() * (rhs.second + 1);
			if (lhsCount != rhsCount)
			{
				return lhsCount < rhsCount;
			}
			return lhs.first.size() > rhs.first.size();
			});

		outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string((*maxItr).first.size() * ((*maxItr).second + 1)) + '\n' + GetFullStr((*maxItr).first, ((*maxItr).second + 1)) + '\n');
	}

	std::cout << outputStr;

}

int lhsIdxArr[1501];
int rhsIdxArr[1501];
std::string S_18441;
std::unordered_map<char, std::vector<int>> fastTable_18441;

void arrangeArr(int* arr, int offset, int start, int range)
{
	for (int idx = offset; idx < range; idx++)
	{
		arr[idx] = start++;
	}
}

int IncrementMultipleIdx(int* arr, int range, int endIdx)
{
	int maxIdx = endIdx;
	int currIdx = range;
	while (currIdx-- > 0)
	{
		if (arr[currIdx] < maxIdx)
		{
			arrangeArr(arr, currIdx, arr[currIdx] + 1, range - currIdx);
			return arr[range - 1];
		}
		maxIdx--;
	}

	return -1;
}

int IncrementFromFront(int* arr, int range, int endIdx)
{
	int maxIdx = endIdx;
	int currIdx = range;
	while (currIdx-- > 0)
	{
		if (arr[currIdx] < maxIdx)
		{
			arrangeArr(arr, currIdx, arr[currIdx] + 1, range - currIdx);
			return arr[range - 1];
		}
		maxIdx--;
	}

	return -1;
}

std::string GetMultipleIdxStr(std::string& str, int* arr, int range)
{
	std::string result;
	for (int idx = 0; idx < range; idx++)
	{
		result.append(1, str[arr[idx]]);
	}
	return result;
}

bool Compare(std::string& str, int* lhsArr, int* rhsArr, int range)
{
	while (range-- > 0)
	{
		if (str[lhsArr[range]] != str[rhsArr[range]])
		{
			return false;
		}
	}

	return true;
}

void Problem_18441_Trial()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T, counter = 1;
	std::cin >> T;
	std::cin.ignore();

	std::string S;
	std::string outputStr;
	std::string subStr;
	bool checker = false;
	int rhsEndIdx = 0;

	double consumedTime = TimeChecker::CheckTime([&] {

	while (T-- > 0)
	{
		std::getline(std::cin, S);

		checker = false;
		// 검사 범위 결정
		for (int range = S.size() / 2; range > 0; range--)
		{
			arrangeArr(lhsIdxArr, 0, 0, range);
			arrangeArr(rhsIdxArr, 0, range, range);
			// 좌측 값 루프
			while (true)
			{
				// 우측 값 루프
				while (true)
				{
					if (Compare(S, lhsIdxArr, rhsIdxArr, range))
					{
						checker = true;
						subStr = GetMultipleIdxStr(S, lhsIdxArr, range);
						outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(subStr.size() * 2) + '\n' + subStr + subStr + '\n');
						break;
					}

					if (IncrementMultipleIdx(rhsIdxArr, range, S.size() - 1) == -1)
					{
						break;
					}
				}
				if (checker) { break; }

				if ((rhsEndIdx = IncrementMultipleIdx(lhsIdxArr, range, S.size() - 1 - range)) != -1)
				{ 
					arrangeArr(rhsIdxArr, 0, rhsEndIdx + 1, range);
				}
				else { break; }
			}
			if (checker) { break; }
		}

		// 제곱 문자열 존재 여부 체크
		if (!checker)
		{
			outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(0) + '\n');
		}
	}

	std::cout << outputStr;

		});

	std::cout << consumedTime << " ms\n";
}

int GetTableOffset(char ch, int idx)
{
	std::vector<int>& tableArr = fastTable_18441[ch];
	return std::find(tableArr.begin(), tableArr.end(), idx) - tableArr.begin();
}

int GetNextTableOffset(char ch, int prevIdx, int offset)
{
	int result = -1;
	for (int idx = prevIdx + 1; idx < fastTable_18441[ch].size(); idx++)
	{
		if (fastTable_18441[ch][idx] > offset) { result = idx; break; }
	}
	
	return result;
}

void Problem_18441()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T, counter = 1;
	std::cin >> T;
	std::cin.ignore();

	std::string outputStr;
	std::string subStr;

	int lhPivot;
	int rhPivot;

	int lhOffset;
	int rhOffset;

	int lhTableIdx;
	int outerRhTableIdx;
	int rhTableIdx;

	// 결과 데이터
	std::string resultStr;
	std::unordered_set<std::string> history;

	double consumedTime = TimeChecker::CheckTime([&] {

		while (T-- > 0)
		{
			std::getline(std::cin, S_18441);

			resultStr.clear();
			subStr.clear();
			fastTable_18441.clear();
			history.clear();
			// 해쉬 인덱스 테이블
			for (size_t idx = 0; idx < S_18441.size(); idx++)
			{
				fastTable_18441[S_18441[idx]].emplace_back(idx);
			}

			// 오른쪽 값 루프
			for (int mainIdx = 0; mainIdx < S_18441.size(); mainIdx++)
			{
				if (history.find(std::to_string(S_18441[mainIdx])) != history.end()) { continue; }

				lhPivot = mainIdx;
				lhTableIdx = GetTableOffset(S_18441[lhPivot], lhPivot);
				outerRhTableIdx = lhTableIdx;

				while ((outerRhTableIdx = GetNextTableOffset(S_18441[lhPivot], outerRhTableIdx, lhPivot)) != -1)
				{
					rhPivot = fastTable_18441[S_18441[lhPivot]][(rhTableIdx = outerRhTableIdx)];

					lhOffset = lhPivot;
					rhOffset = rhPivot;

					subStr.clear();
					subStr += S_18441[lhPivot];
					if (resultStr.empty()) { resultStr = subStr; }

					//std::cout << "---" << lhOffset << " / " << rhOffset << '\n';

					// 범위 루프
					while (++lhOffset < rhPivot)
					{
						lhTableIdx = GetTableOffset(S_18441[lhOffset], lhOffset);
						if ((rhTableIdx = GetNextTableOffset(S_18441[lhOffset], lhTableIdx, rhOffset)) == -1) { continue; }
						subStr += S_18441[lhOffset];
						rhOffset = fastTable_18441[S_18441[lhOffset]][rhTableIdx];

						if (resultStr.size() < subStr.size()) { resultStr = subStr; }

						//std::cout << lhOffset << " / " << rhOffset << '\n';
					}
				}

				history.emplace(std::to_string(S_18441[mainIdx]));
			}

			// 제곱 문자열 존재 여부 체크
			if (resultStr.empty())
			{
				outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(0) + '\n');
			}
			else
			{
				outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(resultStr.size() * 2) + '\n' + resultStr + resultStr + '\n');
			}
		}

		std::cout << outputStr;

		});

	std::cout << consumedTime << " ms\n";
}

void ExecuteString()
{
	//Problem_4354();
	Problem_18441();
}