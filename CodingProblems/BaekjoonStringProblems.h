#pragma once

#include <set>
#include <map>
#include <unordered_set>
#include <bitset>
#include <list>

// PROBLEM 4354
/*
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
*/

// PROBLEM 18441
/*
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

struct DpData_18441
{
public:
	DpData_18441(int inPivot, int inLhs, int inRhs) : pivot{ inPivot }, lhs{ inLhs }, rhs{ inRhs }{}

	bool operator==(const DpData_18441& other) const
	{
		return (pivot == other.pivot
			&& lhs == other.lhs
			&& rhs == other.rhs);
	}

	int pivot;
	int lhs;
	int rhs;
};

struct Hash_18441
{
	std::size_t operator()(std::pair<int, int> const& inData) const noexcept
	{
		return inData.first ^ inData.second;
	}
};

int lhsIdxArr[1502];
int rhsIdxArr[1502];

int lcsArr[3001][3001];

std::string S_18441;
std::unordered_map<char, std::vector<int>> fastTable_18441;
std::unordered_map<std::pair<int,int>, std::string, Hash_18441> lookupTable_18441;
std::string resultStr_18441;

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

int GetNextTableOffset(char ch, int prevIdx, int offset, int limit)
{
	int result = -1;
	for (int idx = prevIdx + 1; idx < fastTable_18441[ch].size(); idx++)
	{
		if (fastTable_18441[ch][idx] > offset && fastTable_18441[ch][idx] < limit) { result = idx; break; }
	}
	
	return result;
}


void Problem_18441_Trial_2()
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

	int offsetBuffer;

	int lhDistance;
	int rhDistance;


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
					while (lhOffset + 1 < rhPivot && rhOffset + 1 < S_18441.size())
					{
						// 왼쪽 증가
						lhTableIdx = GetTableOffset(S_18441[lhOffset + 1], lhOffset + 1);
						if ((rhTableIdx = GetNextTableOffset(S_18441[lhOffset + 1], lhTableIdx, rhOffset)) != -1)
						{
							offsetBuffer = fastTable_18441[S_18441[lhOffset + 1]][rhTableIdx];
							lhDistance = offsetBuffer - rhOffset;
						}
						else { lhDistance = INT_MAX; }

						// 오른쪽 증가
						rhTableIdx = GetTableOffset(S_18441[rhOffset + 1], rhOffset + 1);
						if ((lhTableIdx = GetNextTableOffset(S_18441[rhOffset + 1], -1, lhOffset, rhPivot)) != -1)
						{
							offsetBuffer = fastTable_18441[S_18441[rhOffset + 1]][lhTableIdx];
							rhDistance = offsetBuffer - lhOffset;
						}
						else { rhDistance = INT_MAX; }

						if (lhDistance == INT_MAX && rhDistance == INT_MAX) { lhOffset++; rhOffset++; continue; }
						if (lhDistance <= rhDistance)
						{
							lhOffset++;
							rhOffset += lhDistance;
						}
						else
						{
							rhOffset++;
							lhOffset += rhDistance;
						}

						subStr += S_18441[lhOffset];

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


std::string ProcessSearch_18441(int inLhPivot, int inRhPivot, int inLhIdx, int inRhIdx, std::string inStr)
{
	bool lhState = (inLhIdx + 1 < inRhPivot), rhState = (inRhIdx + 1 < S_18441.size());
	if (!lhState && !rhState) { return inStr; }

	std::string nextStr;
	std::pair<int, int> nextIdx;
	int TableIdx;

	if (lhState)
	{
		nextIdx = std::make_pair(inLhIdx + 1, 0);
		if ((TableIdx = GetNextTableOffset(S_18441[nextIdx.first], GetTableOffset(S_18441[nextIdx.first], nextIdx.first), inRhIdx, S_18441.size())) == -1) { return inStr; }
		nextIdx.second = fastTable_18441[S_18441[nextIdx.first]][TableIdx];
		if (lookupTable_18441.find(nextIdx) != lookupTable_18441.end()) { return lookupTable_18441[nextIdx]; }
		if ((lookupTable_18441[nextIdx] = ProcessSearch_18441(inLhPivot, inRhPivot, nextIdx.first, nextIdx.second, nextStr + S_18441[nextIdx.first])).size() > resultStr_18441.size())
		{
			resultStr_18441 = lookupTable_18441[nextIdx];
		}

		return inStr + lookupTable_18441[nextIdx];
	}
	
	if (rhState)
	{
		nextIdx = std::make_pair(0, inRhIdx + 1);
		if ((TableIdx = GetNextTableOffset(S_18441[nextIdx.second], -1, inLhIdx, inRhIdx + 1)) == -1) { return inStr; }
		nextIdx.first = fastTable_18441[S_18441[nextIdx.second]][TableIdx];
		if (lookupTable_18441.find(nextIdx) != lookupTable_18441.end()) { return lookupTable_18441[nextIdx]; }
		if ((lookupTable_18441[nextIdx] = ProcessSearch_18441(inLhPivot, inRhPivot, nextIdx.first, nextIdx.second, nextStr + S_18441[nextIdx.first])).size() > resultStr_18441.size())
		{
			resultStr_18441 = lookupTable_18441[nextIdx];
		}

		return inStr + lookupTable_18441[nextIdx];
	}
}

void Problem_18441_Trial_3()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T, counter = 1;
	std::cin >> T;
	std::cin.ignore();

	std::string outputStr;

	double consumedTime = TimeChecker::CheckTime([&] {

		while (T-- > 0)
		{
			std::getline(std::cin, S_18441);

			if(S_18441.size() == 1)
			{
				outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(0) + '\n');
				continue;
			}

			resultStr_18441.clear();
			fastTable_18441.clear();
			lookupTable_18441.clear();

			for (size_t idx = 0; idx < S_18441.size(); idx++)
			{
				fastTable_18441[S_18441[idx]].emplace_back(idx);
			}

			ProcessSearch_18441(0, 0, -1, -1, "");

			if (resultStr_18441.empty())
			{
				outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(0) + '\n');
			}
			else
			{
				outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(resultStr_18441.size() * 2) + '\n' + resultStr_18441 + resultStr_18441 + '\n');
			}
		}

		std::cout << outputStr;

		});

	std::cout << consumedTime << " ms\n";
}

void LCS_BottomUp_18441(int boundary)
{
	int lhsBuffer, rhsBuffer;
	int rhsLoopEnd = S_18441.size() - boundary;
	std::string result;

	for (int lhsIdx = 0; lhsIdx < boundary; lhsIdx++)
	{
		for (int rhsIdx = 0; rhsIdx < rhsLoopEnd; rhsIdx++)
		{
			if (S_18441[lhsIdx] == S_18441[rhsIdx + boundary])
			{
				if (lhsIdx == 0 || rhsIdx == 0) { lcsArr[lhsIdx][rhsIdx] = 1; continue; }
				else { lcsArr[lhsIdx][rhsIdx] = lcsArr[lhsIdx - 1][rhsIdx - 1] + 1; }
			}
			else
			{
				if (lhsIdx == 0) { lhsBuffer = 0; }
				else { lhsBuffer = lcsArr[lhsIdx - 1][rhsIdx]; }
				if (rhsIdx == 0) { rhsBuffer = 0; }
				else { rhsBuffer = lcsArr[lhsIdx][rhsIdx - 1]; }
				lcsArr[lhsIdx][rhsIdx] = lhsBuffer > rhsBuffer ? lhsBuffer : rhsBuffer;
			}
		}
		if (resultStr_18441.size() > (boundary - lhsIdx - 1) + lcsArr[lhsIdx][rhsLoopEnd - 1]) { return; }
	}

	if (lcsArr[(lhsBuffer = boundary - 1)][(rhsBuffer = rhsLoopEnd - 1)] <= resultStr_18441.size()) { return; }

	while (lhsBuffer >= 0 && rhsBuffer >= 0)
	{
		if (lcsArr[lhsBuffer][rhsBuffer] == lcsArr[lhsBuffer - 1][rhsBuffer])
		{
			lhsBuffer -= 1;
		}
		else if (lcsArr[lhsBuffer][rhsBuffer] == lcsArr[lhsBuffer][rhsBuffer - 1])
		{
			rhsBuffer -= 1;
		}
		else
		{
			result += S_18441[lhsBuffer];
			lhsBuffer -= 1;
			rhsBuffer -= 1;
		}
	}

	for (int strIdx = 0; strIdx < result.size() / 2; strIdx++)
	{
		std::swap(result[strIdx], result[result.size() - strIdx - 1]);
	}

	resultStr_18441 = result;
	
}

struct Lookup_18441
{
	std::size_t operator()(std::pair<std::string, std::string> const& inData) const noexcept
	{
		return (std::hash<std::string>{}(inData.first) ^ (std::hash<std::string>{}(inData.second) << 1));
	}
};

std::unordered_map<std::pair<std::string, std::string>, int, Lookup_18441> LcsLookupTable_18441;

int LCS_ResultBased_HashMap_18441(int lhsEndIdx, int boundary, int rhsEndIdx)
{
	std::unordered_map<std::pair<std::string, std::string>, int>::iterator result;
	std::pair<std::string, std::string> strBuffer = std::make_pair(S_18441.substr(0, lhsEndIdx + 1), S_18441.substr(boundary, rhsEndIdx + 1));

	if ((result = LcsLookupTable_18441.find(strBuffer)) != LcsLookupTable_18441.end())
	{
		return (*result).second;
	}

	if (lhsEndIdx == -1 || rhsEndIdx == -1) { return 0; }
	if (S_18441[lhsEndIdx] == S_18441[boundary + rhsEndIdx])
	{
		return (LcsLookupTable_18441[strBuffer] = 1 + LCS_ResultBased_HashMap_18441(lhsEndIdx - 1, boundary, rhsEndIdx - 1));
	}
	else
	{
		return (LcsLookupTable_18441[strBuffer] = std::max(LCS_ResultBased_HashMap_18441(lhsEndIdx - 1, boundary, rhsEndIdx), LCS_ResultBased_HashMap_18441(lhsEndIdx, boundary, rhsEndIdx - 1)));
	}
}

int counterd = 0;

std::string LCS_ResultBased_HashMap_18441(int boundary)
{
	int lhsBuffer = boundary - 1;
	int rhsBuffer = S_18441.size() - boundary - 1;
	std::string result;

	while (lhsBuffer >= 0 && rhsBuffer >= 0)
	{
		if (LCS_ResultBased_HashMap_18441(lhsBuffer, boundary, rhsBuffer) == LCS_ResultBased_HashMap_18441(lhsBuffer, boundary, rhsBuffer - 1))
		{
			rhsBuffer -= 1;
		}
		else if (LCS_ResultBased_HashMap_18441(lhsBuffer, boundary, rhsBuffer) == LCS_ResultBased_HashMap_18441(lhsBuffer - 1, boundary, rhsBuffer))
		{
			lhsBuffer -= 1;
		}
		else
		{
			result += S_18441[lhsBuffer];
			lhsBuffer -= 1;
			rhsBuffer -= 1;
		}
	}

	for (int strIdx = 0; strIdx < result.size() / 2; strIdx++)
	{
		std::swap(result[strIdx], result[result.size() - strIdx - 1]);
	}

	return result;
}

void Problem_18441_WithHashMapTrial()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	LcsLookupTable_18441.reserve(3000 * 3000);

	int T, counter = 1;
	std::cin >> T;
	std::cin.ignore();

	std::string subStr;
	std::string outputStr;

	double consumedTime = TimeChecker::CheckTime([&] {

	while (T-- > 0)
	{
		std::getline(std::cin, S_18441);

		resultStr_18441.clear();
		LcsLookupTable_18441.clear();

		int boundary = S_18441.size() / 2;
		while (++boundary < S_18441.size())
		{
			// 결과 문자열 보다 길이가 작은 LCS 스킵
			if (S_18441.size() - boundary < resultStr_18441.size()) { continue; }
			if (resultStr_18441.size() < (subStr = LCS_ResultBased_HashMap_18441(boundary)).size())
			{
				resultStr_18441 = subStr;
			}
		}
		boundary = (S_18441.size() / 2) + 1;
		while (--boundary > 0)
		{
			// 결과 문자열 보다 길이가 작은 LCS 스킵
			if (boundary < resultStr_18441.size()) { continue; }
			if (resultStr_18441.size() < (subStr = LCS_ResultBased_HashMap_18441(boundary)).size())
			{
				resultStr_18441 = subStr;
			}
		}

		if (resultStr_18441.empty()) { outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(0) + '\n'); continue; }
		outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(resultStr_18441.size() * 2) + '\n' + resultStr_18441 + resultStr_18441 + '\n');
	}

	std::cout << outputStr;

		});

	std::cout << consumedTime << " ms\n";
}

int LCS_ResultBased_18441(int lhsEndIdx, int boundary, int rhsEndIdx)
{
	if (lhsEndIdx == -1 || rhsEndIdx == -1) { return 0; }

	if (lcsArr[lhsEndIdx][rhsEndIdx] != -1)
	{
		return lcsArr[lhsEndIdx][rhsEndIdx];
	}

	if (S_18441[lhsEndIdx] == S_18441[boundary + rhsEndIdx])
	{
		return (lcsArr[lhsEndIdx][rhsEndIdx] = 1 + LCS_ResultBased_18441(lhsEndIdx - 1, boundary, rhsEndIdx - 1));
	}
	else
	{
		return (lcsArr[lhsEndIdx][rhsEndIdx] = std::max(LCS_ResultBased_18441(lhsEndIdx - 1, boundary, rhsEndIdx), LCS_ResultBased_18441(lhsEndIdx, boundary, rhsEndIdx - 1)));
	}
}

std::string LCS_ResultBased_18441(int boundary)
{
	int lhsBuffer = boundary - 1;
	int rhsBuffer = S_18441.size() - boundary - 1;
	std::string result;

	while (lhsBuffer >= 0 && rhsBuffer >= 0)
	{
		if (LCS_ResultBased_18441(lhsBuffer, boundary, rhsBuffer) == LCS_ResultBased_18441(lhsBuffer, boundary, rhsBuffer - 1))
		{
			rhsBuffer -= 1;
		}
		else if (LCS_ResultBased_18441(lhsBuffer, boundary, rhsBuffer) == LCS_ResultBased_18441(lhsBuffer - 1, boundary, rhsBuffer))
		{
			lhsBuffer -= 1;
		}
		else
		{
			result += S_18441[lhsBuffer];
			lhsBuffer -= 1;
			rhsBuffer -= 1;
		}
	}

	for (int strIdx = 0; strIdx < result.size() / 2; strIdx++)
	{
		std::swap(result[strIdx], result[result.size() - strIdx - 1]);
	}

	return result;
}

void resetDpData(int boundary)
{
	for (int lhsIdx = 0; lhsIdx < boundary; lhsIdx++)
	{
		memset(lcsArr[lhsIdx], 0, sizeof(int) * (S_18441.size() - boundary));
	}
}

int dd = 0;
int ss = 0;

struct DataSet_18441
{
public:
	DataSet_18441(int inStart, int inEnd, int inDirec) :start{ inStart }, end{ inEnd }, direc{ inDirec }{}

	int start;
	int end;
	int direc;
};

void StartSearch(int start, int end, int direc)
{
	if (end - start == 1) { return; }
	int boundary = start + ((end - start) / 2);
	if (direc == -1 && boundary < resultStr_18441.size()) { StartSearch(boundary, end, direc); return; }
	else if (direc == 1 && S_18441.size() - boundary < resultStr_18441.size()) { StartSearch(start, boundary, direc); return; }

	LCS_BottomUp_18441(boundary);
	StartSearch(start, boundary, direc);
	StartSearch(boundary, end, direc);
}

std::queue<DataSet_18441> searchQueue;

void Problem_18441_Trial_4()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T, counter = 1, boundary;
	std::cin >> T;
	std::cin.ignore();

	std::string subStr;
	std::string outputStr;

	double consumedTime = TimeChecker::CheckTime([&] {

		while (T-- > 0)
		{
			std::getline(std::cin, S_18441);

			resultStr_18441.clear();

			LCS_BottomUp_18441(S_18441.size() / 2);

			searchQueue.emplace(DataSet_18441(0, S_18441.size() / 2, -1));
			searchQueue.emplace(DataSet_18441(S_18441.size() / 2, S_18441.size(), 1));
			while (!searchQueue.empty())
			{
				if (searchQueue.front().end - searchQueue.front().start == 1) { searchQueue.pop();  continue; }
				boundary = searchQueue.front().start + ((searchQueue.front().end - searchQueue.front().start) / 2);
				if (searchQueue.front().direc == -1 && boundary < resultStr_18441.size()) { searchQueue.emplace(DataSet_18441(boundary, searchQueue.front().end, searchQueue.front().direc)); searchQueue.pop(); continue; }
				else if (searchQueue.front().direc == 1 && S_18441.size() - boundary < resultStr_18441.size()) { searchQueue.emplace(DataSet_18441(searchQueue.front().start, boundary, searchQueue.front().direc)); searchQueue.pop(); continue; }

				LCS_BottomUp_18441(boundary);
				searchQueue.emplace(DataSet_18441(boundary, searchQueue.front().end, searchQueue.front().direc));
				searchQueue.emplace(DataSet_18441(searchQueue.front().start, boundary, searchQueue.front().direc));
				searchQueue.pop();
			}

			if (resultStr_18441.empty()) { outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(0) + '\n'); continue; }
			outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(resultStr_18441.size() * 2) + '\n' + resultStr_18441 + resultStr_18441 + '\n');
		}

		std::cout << outputStr;

		});

	std::cout << consumedTime << " ms\n";
}

// 패턴 파악 실패 
void LCS_BT_Mem_18441(int boundary)
{
	// 이전 테이블 복사
	for (int lhsIdx = 0; lhsIdx < boundary - 1; lhsIdx++)
	{
		memmove(lcsArr[lhsIdx], &lcsArr[lhsIdx][1], sizeof(int) * (S_18441.size() - boundary));
	}

	int lhsBuffer, rhsBuffer;
	int rhsLoopEnd = S_18441.size() - boundary;
	int newLhsIdx = boundary - 1;
	std::string result;

	for (int rhsIdx = 0; rhsIdx < rhsLoopEnd; rhsIdx++)
	{
		if (S_18441[newLhsIdx] == S_18441[rhsIdx + boundary])
		{
			if (rhsIdx == 0) { lcsArr[newLhsIdx][rhsIdx] = 1; continue; }
			else { lcsArr[newLhsIdx][rhsIdx] = lcsArr[newLhsIdx - 1][rhsIdx - 1] + 1; }
		}
		else
		{
			lhsBuffer = lcsArr[newLhsIdx - 1][rhsIdx];
			if (rhsIdx == 0) { rhsBuffer = 0; }
			else { rhsBuffer = lcsArr[newLhsIdx][rhsIdx - 1]; }
			lcsArr[newLhsIdx][rhsIdx] = lhsBuffer > rhsBuffer ? lhsBuffer : rhsBuffer;
		}
	}

	if (lcsArr[(lhsBuffer = boundary - 1)][(rhsBuffer = rhsLoopEnd - 1)] <= resultStr_18441.size()) { return; }

	while (lhsBuffer >= 0 && rhsBuffer >= 0)
	{
		if (lcsArr[lhsBuffer][rhsBuffer] == lcsArr[lhsBuffer - 1][rhsBuffer])
		{
			lhsBuffer -= 1;
		}
		else if (lcsArr[lhsBuffer][rhsBuffer] == lcsArr[lhsBuffer][rhsBuffer - 1])
		{
			rhsBuffer -= 1;
		}
		else
		{
			result += S_18441[lhsBuffer];
			lhsBuffer -= 1;
			rhsBuffer -= 1;
		}
	}

	for (int strIdx = 0; strIdx < result.size() / 2; strIdx++)
	{
		std::swap(result[strIdx], result[result.size() - strIdx - 1]);
	}

	resultStr_18441 = result;

}

#define get(arr, x) (((arr[x >> 6] >> (x & 63)) & 1) == 1)
#define set(arr, x) (arr[x >> 6] |= 1llu << (x & 63))
using ulint = unsigned long long;

// 비트셋 : 결과 str 에러 출력 실패
void lcs(int boundary) {
	int N = boundary, M = S_18441.size() - boundary;
	int sz = (M >> 6) + 1;

	std::vector<ulint> S[256];
	for (int c = 0; c < 256; c++) S[c].resize(sz);
	for (int j = 0; j < M; j++) set(S[S_18441[j + boundary]], j);

	std::vector<ulint> row(sz);
	for (int j = 0; j < M; j++) if (S_18441[0] == S_18441[j + boundary]) { set(row, j); break; }

	for (int i = 1; i < N; i++) {
		ulint shl_carry = 1;
		ulint minus_carry = 0;

		for (int k = 0; k < sz; k++) {
			ulint x_k = S[S_18441[i]][k] | row[k];

			ulint term_1 = (row[k] << 1) | shl_carry;
			shl_carry = row[k] >> 63;

			auto sub_carry = [](ulint& x, ulint y) {
				ulint tmp = x;
				return (x = tmp - y) > tmp;
			};
			ulint term_2 = x_k;
			minus_carry = sub_carry(term_2, minus_carry);
			minus_carry += sub_carry(term_2, term_1);

			row[k] = x_k & (x_k ^ term_2);
		}

		row[M >> 6] &= (1llu << (M & 63)) - 1;
	}

	int ret = 0;
	std::string result;
	for (int j = 0; j < M; j++)
	{
		if (get(row, j))
		{
			std::cout << j << std::endl;
			result += S_18441[j + boundary];
			ret += 1;
		}

	}

	if (resultStr_18441.size() < ret) { resultStr_18441 = result; }
}


void Problem_18441()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T, counter = 1, boundary;
	std::cin >> T;
	std::cin.ignore();

	std::string subStr;
	std::string outputStr;

	double consumedTime = TimeChecker::CheckTime([&] {

		while (T-- > 0)
		{
			std::getline(std::cin, S_18441);
			std::cout << "----" << std::endl;
			resultStr_18441.clear();
			boundary = (S_18441.size() / 2) - 1;
			while (++boundary < S_18441.size() && boundary > 0)
			{
				if (S_18441.size() - boundary < resultStr_18441.size()) { continue; }
				lcs(boundary);
			}
			boundary = S_18441.size() / 2;
			while (--boundary > 0)
			{
				if (boundary < resultStr_18441.size()) { continue; }
				lcs(boundary);
			}

			if (resultStr_18441.empty()) { outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(0) + '\n'); continue; }
			outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(resultStr_18441.size() * 2) + '\n' + resultStr_18441 + resultStr_18441 + '\n');
		}

		std::cout << outputStr;

		});

	std::cout << consumedTime << " ms\n";
}
*/

// PROBLEM 9251
/*
int LCS_9251(const std::string& str, int boundary)
{
	int lhsBuffer, rhsBuffer;

	for (int lhsIdx = 0; lhsIdx < boundary; lhsIdx++)
	{
		for (int rhsIdx = boundary; rhsIdx < str.size(); rhsIdx++)
		{
			if (str[lhsIdx] == str[rhsIdx])
			{
				if (lhsIdx == 0 || rhsIdx == boundary) { lcsArr[lhsIdx][rhsIdx - boundary] = 1; continue; }
				lcsArr[lhsIdx][rhsIdx - boundary] = lcsArr[lhsIdx - 1][rhsIdx - boundary - 1] + 1;
			}
			else
			{
				if (lhsIdx == 0) { lhsBuffer = 0; }
				else { lhsBuffer = lcsArr[lhsIdx - 1][rhsIdx - boundary]; }
				if (rhsIdx == boundary) { rhsBuffer = 0; }
				else { rhsBuffer = lcsArr[lhsIdx][rhsIdx - boundary - 1]; }
				lcsArr[lhsIdx][rhsIdx - boundary] = lhsBuffer > rhsBuffer ? lhsBuffer : rhsBuffer;
			}
		}
	}
	return lcsArr[boundary - 1][str.size() - boundary - 1];
}

void Problem_9251()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie();

	std::string A, B;
	std::getline(std::cin, A);
	std::getline(std::cin, B);

	std::cout << LCS_9251(A + B, A.size());
}
*/

// PROBLEM 9252
/*
int lcsArr[1001][1001];
std::string resultStr;

int LCS_9252(const std::string& str, int boundary)
{
	int lhsBuffer, rhsBuffer;

	for (int lhsIdx = 0; lhsIdx < boundary; lhsIdx++)
	{
		for (int rhsIdx = boundary; rhsIdx < str.size(); rhsIdx++)
		{
			if (str[lhsIdx] == str[rhsIdx])
			{
				if (lhsIdx == 0 || rhsIdx == boundary) { lcsArr[lhsIdx][rhsIdx - boundary] = 1; continue; }
				lcsArr[lhsIdx][rhsIdx - boundary] = lcsArr[lhsIdx - 1][rhsIdx - boundary - 1] + 1;
			}
			else
			{
				if (lhsIdx == 0) { lhsBuffer = 0; }
				else { lhsBuffer = lcsArr[lhsIdx - 1][rhsIdx - boundary]; }
				if (rhsIdx == boundary) { rhsBuffer = 0; }
				else { rhsBuffer = lcsArr[lhsIdx][rhsIdx - boundary - 1]; }
				lcsArr[lhsIdx][rhsIdx - boundary] = lhsBuffer > rhsBuffer ? lhsBuffer : rhsBuffer;
			}
		}
	}

	lhsBuffer = boundary - 1;
	rhsBuffer = str.size() - boundary - 1;
	while (lhsBuffer >= 0 && rhsBuffer >= 0)
	{
		if (lcsArr[lhsBuffer][rhsBuffer] == lcsArr[lhsBuffer - 1][rhsBuffer])
		{
			lhsBuffer -= 1;
		}
		else if (lcsArr[lhsBuffer][rhsBuffer] == lcsArr[lhsBuffer][rhsBuffer - 1])
		{
			rhsBuffer -= 1;
		}
		else
		{
			resultStr += str[lhsBuffer];
			lhsBuffer -= 1;
			rhsBuffer -= 1;
		}
	}

	for (int strIdx = 0; strIdx < resultStr.size() / 2; strIdx++)
	{
		std::swap(resultStr[strIdx], resultStr[resultStr.size() - strIdx - 1]);
	}

	return lcsArr[boundary - 1][str.size() - boundary - 1];
}

void Problem_9252()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie();

	std::string A, B;
	std::cin >> A >> B;

	std::cout << LCS_9252(A + B, A.size()) << '\n' << resultStr;
}
*/

// PROBLEM 18441 RETRY
// studied with http://www.secmem.org/blog/2019/09/12/lcs-with-bitset/
// but without std::bitset library (length 64 * 8 bits operation several times

// PROBLEM 18441 RETRY
/*
#define get(arr, x) (((arr[x >> 6] >> (x & 63)) & 1) == 1)
#define set(arr, x) (arr[x >> 6] |= 1llu << (x & 63))
using ulint = unsigned long long;

int lcsArr[3001][3001];
std::string S_18441;
std::string resultStr_18441;
int maxLength;
int maxBoundary;

// 비트셋 LCS
// 
void LCS_Bitset(int boundary)
{
	std::string A = S_18441.substr(0, boundary);
	std::string B = S_18441.substr(boundary, S_18441.size() - boundary);
	int N = A.size(), M = B.size(), shM = M >> 6;
	ulint shl_carry, x_k, term_1, term_2, minus_carry = 0, tmp;

	ulint S[26][28]; // a~z 1792 문자열 길이
	for (int j = 0; j < M; j++) set(S[B[j] - 'a'], j); // A[i] == B[i] 전처리

	ulint row[28] = { 0 };
	for (int j = 0; j < M; j++) if (A[0] == B[j]) { set(row, j); break; } // D[0]

	for (int i = 1; i < N; i++) 
	{
		shl_carry = 1;

		// 64비트 단위 M >> 6 개 비트셋 프로세싱
		for (int k = 0; k < shM + 1; k++)
		{
			x_k = S[A[i] - 'a'][k] | row[k];

			// 쉬프트 캐리
			term_1 = (row[k] << 1) | shl_carry;
			shl_carry = row[k] >> 63;

			// 빼기 연산 캐리
			minus_carry = (term_2 = x_k - minus_carry) > x_k;
			tmp = term_2;
			minus_carry += (term_2 = term_2 - term_1) > tmp;

			row[k] = x_k & (x_k ^ term_2);
		}

		row[shM] &= (1llu << (M & 63)) - 1;
	}

	// 결과 D의 true 비트 갯수 카운트
	int ret = 0;
	for (int j = 0; j < M; j++)
	{
		if (get(row, j))
		{
			ret += 1;
		}
	}
	if (maxLength < ret) { maxLength = ret; maxBoundary = boundary;}
}

void LCS_BottomUp_18441(int boundary)
{
	int lhsBuffer, rhsBuffer;
	int rhsLoopEnd = S_18441.size() - boundary;

	for (int lhsIdx = 0; lhsIdx < boundary; lhsIdx++)
	{
		for (int rhsIdx = 0; rhsIdx < rhsLoopEnd; rhsIdx++)
		{
			if (S_18441[lhsIdx] == S_18441[rhsIdx + boundary])
			{
				if (lhsIdx == 0 || rhsIdx == 0) { lcsArr[lhsIdx][rhsIdx] = 1; }
				else { lcsArr[lhsIdx][rhsIdx] = lcsArr[lhsIdx - 1][rhsIdx - 1] + 1; }
			}
			else
			{
				if (lhsIdx == 0) { lhsBuffer = 0; }
				else { lhsBuffer = lcsArr[lhsIdx - 1][rhsIdx]; }
				if (rhsIdx == 0) { rhsBuffer = 0; }
				else { rhsBuffer = lcsArr[lhsIdx][rhsIdx - 1]; }
				lcsArr[lhsIdx][rhsIdx] = lhsBuffer > rhsBuffer ? lhsBuffer : rhsBuffer;
			}
		}
	}

	lhsBuffer = boundary - 1;
	rhsBuffer = rhsLoopEnd - 1;

	while (lhsBuffer >= 0 && rhsBuffer >= 0)
	{
		if (lcsArr[lhsBuffer][rhsBuffer] == lcsArr[lhsBuffer - 1][rhsBuffer])
		{
			lhsBuffer -= 1;
		}
		else if (lcsArr[lhsBuffer][rhsBuffer] == lcsArr[lhsBuffer][rhsBuffer - 1])
		{
			rhsBuffer -= 1;
		}
		else
		{
			resultStr_18441 += S_18441[lhsBuffer];
			lhsBuffer -= 1;
			rhsBuffer -= 1;
		}
	}

	for (int strIdx = 0; strIdx < resultStr_18441.size() / 2; strIdx++)
	{
		std::swap(resultStr_18441[strIdx], resultStr_18441[resultStr_18441.size() - strIdx - 1]);
	}
}

void Problem_18441_Retry()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T, counter = 1, boundary;
	std::cin >> T;

	std::string outputStr;

	double consumedTime = TimeChecker::CheckTime([&] {

	while (T-- > 0)
	{
		std::cin >> S_18441;
		resultStr_18441.clear();
		maxLength = 0;

		// 중앙 길이부터 연산하는 것이 유리하다고 생각
		boundary = (S_18441.size() / 2);
		LCS_Bitset(boundary);
		while (--boundary > 0)
		{
			if (boundary < maxLength) { break; }
			LCS_Bitset(boundary);
			if (boundary < maxLength) { break; }
			LCS_Bitset(S_18441.size() - boundary);
		}

		if (maxLength != 0)
		{
			LCS_BottomUp_18441(maxBoundary);
		}

		if (resultStr_18441.empty()) 
		{ 
			outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(0) + '\n'); 
			continue;
		}
		outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(resultStr_18441.size() * 2) + '\n' + resultStr_18441 + resultStr_18441 + '\n');
	}

	std::cout << outputStr;

		});

	std::cout << '\n' << consumedTime << " ms" << '\n';
}
*/

// PROBLEM 18441 RETRY
// with std::bitset library
/*
std::string S_18441;
std::string resultStr_18441;
int maxLength = 0;

template<int size>
void LCS_Bitset(int boundary)
{
	std::string A;
	std::string B;
	std::bitset<size> S[26];
	std::bitset<size> x, temp, borrow;
	std::bitset<size> D[2000];

	if (boundary > S_18441.size() / 2)
	{
		A = S_18441.substr(0, boundary);
		B = S_18441.substr(boundary, S_18441.size() - boundary);
	}
	else
	{
		A = S_18441.substr(boundary, S_18441.size() - boundary);
		B = S_18441.substr(0, boundary);
	}

	int aSize = A.size();

	for (int idx = 0; idx < B.size(); idx++)
	{
		S[B[idx] - 97][idx] = 1;
	}

	for (int idx = 0; idx < aSize; idx++)
	{
		temp = x = S[A[idx] - 97] | D[idx];
		(D[idx + 1] = D[idx] << 1)[0] = 1;

		while (D[idx + 1].any())
		{
			borrow = (~temp) & D[idx + 1];
			temp ^= D[idx + 1];
			D[idx + 1] = borrow << 1;
		}

		D[idx + 1] = (x & (x ^ temp));
	}

	if (maxLength >= D[aSize].count()) { return; }

	int b = B.size() - 1;
	resultStr_18441.clear();

	for (; aSize > 0; aSize--)
	{
		while (b >= 0 && !D[aSize][b])
		{
			b--;
		}

		if (b < 0)
		{
			break;
		}

		while (aSize > 0 && D[aSize - 1][b])
		{
			aSize--;
		}
		resultStr_18441 += B[b--];
	}

	maxLength = resultStr_18441.size();
}

void LCS(int boundary)
{
	int temp;
	if (boundary > S_18441.size() / 2)
	{
		temp = (S_18441.size() - boundary) >> 6;
	}
	else
	{
		temp = boundary >> 6;
	}

	switch (temp)
	{
	case 23: { LCS_Bitset<1536>(boundary); break; }
	case 22: { LCS_Bitset<1472>(boundary); break; }
	case 21: { LCS_Bitset<1408>(boundary); break; }
	case 20: { LCS_Bitset<1344>(boundary); break; }
	case 19: { LCS_Bitset<1280>(boundary); break; }
	case 18: { LCS_Bitset<1216>(boundary); break; }
	case 17: { LCS_Bitset<1152>(boundary); break; }
	case 16: { LCS_Bitset<1088>(boundary); break; }
	case 15: { LCS_Bitset<1024>(boundary); break; }
	case 14: { LCS_Bitset<960>(boundary); break; }
	case 13: { LCS_Bitset<896>(boundary); break; }
	case 12: { LCS_Bitset<832>(boundary); break; }
	case 11: { LCS_Bitset<768>(boundary); break; }
	case 10: { LCS_Bitset<704>(boundary); break; }
	case 9: { LCS_Bitset<640>(boundary); break; }
	case 8: { LCS_Bitset<576>(boundary); break; }
	case 7: { LCS_Bitset<512>(boundary); break; }
	case 6: { LCS_Bitset<448>(boundary); break; }
	case 5: { LCS_Bitset<384>(boundary); break; }
	case 4: { LCS_Bitset<320>(boundary); break; }
	case 3: { LCS_Bitset<256>(boundary); break; }
	case 2: { LCS_Bitset<192>(boundary); break; }
	case 1: { LCS_Bitset<128>(boundary); break; }
	case 0: { LCS_Bitset<64>(boundary); break; }
	default: break;
	}
}

void Problem_18441_Retry_Bitset()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T, counter = 1, boundary;
	std::cin >> T;

	std::string outputStr;

	double consumedTime = TimeChecker::CheckTime([&] {

		while (T-- > 0)
		{
			std::cin >> S_18441;
			resultStr_18441.clear();
			maxLength = 0;

			boundary = (S_18441.size() / 2);
			LCS(boundary);
			while (--boundary > 0)
			{
				if (boundary < maxLength) { break; }
				LCS(boundary);
				if (boundary < maxLength) { break; }
				LCS(S_18441.size() - boundary);
			}

			if (maxLength == 0)
			{
				outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(0) + '\n');
				continue;
			}

			for (int idx = 0; idx < resultStr_18441.size() / 2; idx++)
			{
				std::swap(resultStr_18441[idx], resultStr_18441[resultStr_18441.size() - idx - 1]);
			}

			outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(resultStr_18441.size() * 2) + '\n' + resultStr_18441 + resultStr_18441 + '\n');
		}

		std::cout << outputStr;

		});

	std::cout << '\n' << consumedTime << " ms" << '\n';
}
*/

// PROBLEM 1152
/*
void Problem_1152()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::string str;
	std::string strBuffer;
	int result = 0;
	std::getline(std::cin, str);

	for (const auto& elem : str)
	{
		if (elem == ' ')
		{
			if (strBuffer.size() > 0)
			{
				strBuffer.clear();
				result++;
			}
		}
		else
		{
			strBuffer += elem;
		}
	}

	if (strBuffer.size() > 0)
	{
		strBuffer.clear();
		result++;
	}

	std::cout << result;
}
*/

// PRBOLEM 1018
/*
void Problem_1018()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int M, N, result = INT_MAX;
	std::cin >> M >> N;
	std::cin.ignore();

	std::vector<std::string> data(M);

	for (int count = 0; count < M; count++)
	{
		std::getline(std::cin, data[count]);
	}

	int counter;
	char currentCharac, lineCharac;

	for (int posX = 0; posX <= M - 8; posX++)
	{
		for (int posY = 0; posY <= N - 8; posY++)
		{
			for (int caseNum = 0; caseNum < 2; caseNum++)
			{
				counter = 0;
				if (caseNum == 0) { lineCharac = 'W'; currentCharac = 'W'; }
				else { lineCharac = 'B'; currentCharac = 'B'; }
				for (int outerIdx = posX; outerIdx < posX + 8; outerIdx++)
				{
					for (int innerIdx = posY; innerIdx < posY + 8; innerIdx++)
					{
						if (data[outerIdx][innerIdx] != currentCharac)
						{
							counter++;
							if (counter > result) { break; }
						}

						if (currentCharac == 'W'){ currentCharac = 'B'; }
						else{ currentCharac = 'W'; }
					}
					if (lineCharac == 'W'){ lineCharac = 'B'; currentCharac = 'B'; }
					else{ lineCharac = 'W'; currentCharac = 'W'; }
				}
				if (counter < result) { result = counter; }
			}
		}
	}

	std::cout << result;
}
*/

// PROBLEM 1120
/*
void Problem_1120()
{
	int min = 51, count = 0;
	std::string A, B;
	std::cin >> A >> B;

	for (int bIdx = 0; bIdx <= B.size() - A.size(); bIdx++)
	{
		count = 0;
		for (int aIdx = 0; aIdx < A.size(); aIdx++)
		{
			if (A[aIdx] != B[bIdx + aIdx])
			{
				count++;
			}
		}
		if (min > count) { min = count; }
	}

	std::cout << min;
}
*/

// PROBLEM 1110
/*
void Problem_1110()
{
	std::string num;
	int digit[2], buffer;
	std::cin >> num;
	if (num.length() != 2)
	{
		digit[1] = num[0] - '0';
		digit[0] = 0;
	}
	else
	{
		digit[1] = num[1] - '0';
		digit[0] = num[0] - '0';
	}

	buffer = digit[1];
	digit[1] = (digit[0] + digit[1]) % 10;
	digit[0] = buffer;
	int count = 1;
	while (std::stoi(num) != digit[0] * 10 + digit[1])
	{
		buffer = digit[1];
		digit[1] = (digit[0] + digit[1]) % 10;
		digit[0] = buffer;
		count++;
	}

	std::cout << count;
}
*/

// PROBLEM 2577
/*
void Problem_2577()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	int counts[10] = { 0 };
	std::string numStr = std::to_string(a * b * c);
	for (const auto& elem : numStr)
	{
		counts[elem - '0']++;
	}
	for (int idx = 0; idx < 10; idx++)
	{
		std::cout << counts[idx] << '\n';
	}
}
*/

// PROBLEM 8958
/*
void Problem_8958()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string str, outputStr;
	int N, count = 1, total = 0;
	std::cin >> N;
	std::cin.ignore();

	while (N-- > 0)
	{
		total = 0; count = 0;
		std::getline(std::cin, str);
		for (const auto& elem : str)
		{
			if (elem == 'O'){ total += ++count; }
			else{ count = 0; }
		}
		outputStr += std::to_string(total) + '\n';
	}
	std::cout << outputStr;
}
*/

// PROBLEM 11720
/*
void Problem_11720()
{
	int N;
	std::cin >> N;
	std::string numStr;
	std::cin >> numStr;
	int result = 0;
	for (const auto& elem : numStr){ result += elem - '0'; }
	std::cout << result;
}
*/

// PROBLEM 10809
/*
void Problem_10809()
{
	int indices[26];
	for (int idx = 0; idx < 26; idx++) { indices[idx] = -1; }
	std::string str;
	std::cin >> str;
	for (int idx = 0; idx < str.size(); idx++){ if (indices[str[idx] - 'a'] == -1) { indices[str[idx] - 'a'] = idx; } }
	for (int idx = 0; idx < 26; idx++) { std::cout << indices[idx] << " "; }
}
*/

// PROBLEM 2675
/*
void Problem_2675()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T, inputBuffer;
	std::string inputStr, outputStr;
	std::cin >> T;
	while (T-- > 0)
	{
		std::cin >> inputBuffer >> inputStr;
		for(const auto& elem : inputStr){ for (int count = 0; count < inputBuffer; count++) { outputStr += elem; } }
		outputStr += '\n';
	}
	std::cout << outputStr;
}
*/

// PROBLEM 1157
/*
void Problem_1157()
{
	int count[26] = { 0 };
	std::string str;
	std::cin >> str;
	for (const auto& elem : str) { if (elem >= 'a') { count[elem - 'a']++; } else { count[elem - 'A']++; } }
	int maxIdx = 0, maxCount = 1;
	for (int idx = 1; idx < 26; idx++) 
	{
		if (count[idx] > count[maxIdx]) { maxIdx = idx; maxCount = 1; }
		else if (count[idx] == count[maxIdx]) { maxCount++; }
	}
	if (maxCount > 1){ std::cout << "?"; }
	else { std::cout << (char)(maxIdx + 'A'); }
}
*/

// PROBLEM 5622
/*
int getDialNum(char ch)
{
	if (ch <= 'O') { return ((ch - 'A') / 3); }
	else if (ch <= 'S') { return 5; }
	else if (ch <= 'V') { return 6; }
	else { return 7; }
}

void Problem_5622()
{
	std::string str;
	std::cin >> str;
	int result = 0;
	for (const auto& elem : str){ result += getDialNum(elem) + 3; }
	std::cout << result;
}
*/

// PROBLEM 2941
/*
void Problem_2941()
{
	std::string croa[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	std::string str;
	std::cin >> str;
	int result = 0, savedIdx = 0;
	size_t found = 0;
	while (found != std::string::npos)
	{
		for (int count = savedIdx; count < 8; count++)
		{
			if ((found = str.find(croa[count])) != std::string::npos)
			{
				savedIdx = count;
				result++;
				str = str.substr(0, found) + " " + str.substr(found + croa[count].size(), str.size() - (found + croa[count].size()));
				break;
			}
		}
	}

	for (const auto& elem : str)
	{
		if (elem != ' ') { result++; }
	}
	std::cout << result;
}
*/

// PROBLEM 1316
/*
void Problem_1316()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	bool check[26], pass = true; char ch;
	std::string inputStr;
	int N, result = 0;
	std::cin >> N;

	while (N-- > 0)
	{
		std::cin >> inputStr; inputStr += " ";
		for (int idx = 0; idx < 26; idx++) { check[idx] = false; }
		ch = inputStr[0];
		pass = true;
		for (int idx = 1; idx < inputStr.size(); idx++)
		{
			if (inputStr[idx] != ch)
			{
				if (check[ch - 'a']) { pass = false; break; }
				else { check[ch - 'a'] = true; ch = inputStr[idx]; }
			}
		}
		if (pass) { result++; }
	}

	std::cout << result;
}
*/

// PROBLEM 11718
/*
void Problem_11718()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string inputStr, outputStr;

	while (std::getline(std::cin, inputStr))
	{
		outputStr += inputStr + '\n';
	}

	std::cout << outputStr;
}
*/

// PROBLEM 11721
/*
void Problem_11721()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string input, output;

	std::cin >> input;

	while (input.length() > 10)
	{
		output += input.substr(0, 10) + '\n';
		input = input.substr(10, input.length() - 10);
	}
	output += input + '\n';

	std::cout << output;
}
*/

// PROBLEM 11719
/*
void Problem_11719()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string input, output;

	while (std::getline(std::cin, input))
	{
		output += input + '\n';
	}

	std::cout << output;
}
*/

// PROBLEM 10808
/*
void Problem_10808()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string input, output;
	int counts[26] = { 0 };

	std::cin >> input;
	for (const auto& elem : input)
	{
		counts[elem - 'a']++;
	}

	for (int idx = 0; idx < 26; idx++)
	{
		output += std::to_string(counts[idx]) + ' ';
	}

	std::cout << output;
}
*/

// PROBLEM 2743
/*
void Problem_2743()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string input;
	std::cin >> input;
	std::cout << input.size();
}
*/

// PROBLEM 1764
/*
void Problem_1764()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::string str;
	std::unordered_set<std::string> data;
	std::set<std::string> res;
	while (n-- > 0)
	{
		std::cin >> str;
		data.emplace(str);
	}

	int count = 0;

	while (m-- > 0)
	{
		std::cin >> str;
		if (data.find(str) == data.end())
		{
			continue;
		}

		count++;
		res.emplace(str);
	}

	std::string outputStr;
	for (const auto& elem : res)
	{
		outputStr += elem + '\n';
	}

	std::cout << count << '\n' << outputStr;
}
*/

// PROBLEM 1259
/*
void Problem_1259()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string inputStr, outputStr;
	while (true)
	{
		std::cin >> inputStr;
		if (inputStr == "0")
		{
			break;
		}

		bool checker = true;
		for (int idx = 0; idx < inputStr.size() / 2; idx++)
		{
			if (inputStr[idx] != inputStr[inputStr.size() - 1 - idx])
			{
				checker = false;
				break;
			}
		}

		if (checker)
		{
			outputStr += "yes\n";
		}
		else
		{
			outputStr += "no\n";
		}
	}

	std::cout << outputStr;
}
*/

// PROBLEM 1032
/*
void Problem_1032()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int num;
	std::cin >> num;

	std::vector<std::string> data(num);

	std::cin >> data[0];
	for(int idx = 1; idx < num; idx++)
	{
		std::cin >> data[idx];
	}
	
	std::string res = data[0];
	res.resize(data[0].size());

	for (int idx = 1; idx < num; idx++)
	{
		for (int secIdx = idx - 1; secIdx >= 0; secIdx--)
		{
			for (int strIdx = 0; strIdx < data[idx].size(); strIdx++)
			{
				if (res[strIdx] == '?') { continue; }
				if (data[idx][strIdx] != data[secIdx][strIdx])
				{
					res[strIdx] = '?';
				}
			}
		}
	}

	std::cout << res;
}
*/

// PROBLEM 10610
/*
void Problem_10610()
{
	std::string numStr;
	std::cin >> numStr;

	int sum = 0; bool hasZero = false;
	for (const auto& elem : numStr)
	{
		if (elem == '0') { hasZero = true; }
		sum += elem - '0';
	}

	if (sum % 3 == 0 && hasZero)
	{
		std::sort(numStr.begin(), numStr.end(), [&](const char& lhs, const char& rhs) {
			return lhs > rhs;
			}
		);

		std::cout << numStr;
	}
	else
	{
		std::cout << -1;
	}
}
*/

// PROBLEM 2902
/*
void Problem_2902()
{
	std::string inputStr;
	std::cin >> inputStr;

	std::string output;
	for (const auto& elem : inputStr)
	{
		if (elem >= 'A' && elem <= 'Z')
		{
			output += elem;
		}
	}

	std::cout << output;
}
*/

// PROBLEM 1212
/*
std::string toBinary(int inOct)
{
	std::string res;
	res.resize(3);

	int digit = 0;
	int temp, check;
	
	while (digit < 3)
	{
		temp = std::pow(2, 2 - digit);
		res[digit++] = (check = inOct >= temp) ? '1' : '0';
		inOct -= check * temp;
	}

	return res;
}

void Problem_1212()
{
	std::string input;
	std::cin >> input;
	if (input == "0")
	{
		std::cout << 0;
	}
	else
	{
		std::string output;
		
		std::string first = toBinary(input[0] - '0');
		while (first[0] == '0')
		{
			first = first.substr(1, first.size() - 1);
		}
		output += first;

		for (int idx = 1; idx < input.size(); idx++)
		{
			output += toBinary(input[idx] - '0');
		}

		std::cout << output;
	}
}
*/

// PROBLEM 1373
/*
void Problem_1373()
{
	std::string input;
	std::cin >> input;

	std::string output;
	int temp, tempIdx, exp;
	for (int idx = input.size() - 1; idx >= 0; idx--)
	{
		tempIdx = idx - 2 >= 0 ? idx - 2 : 0;
		exp = 0;
		temp = 0;
		for (int numIdx = idx; numIdx >= tempIdx; numIdx--)
		{
			temp += std::pow(2, exp) * (input[numIdx] - '0');
			exp++;
		}
		output += std::to_string(temp);
		idx = tempIdx;
	}

	for (int idx = 0; idx < output.size() / 2; idx++)
	{
		std::swap(output[idx], output[output.size() - 1 - idx]);
	}

	std::cout << output;
}
*/

// PROBLEM 9093
/*
void Problem_9093()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string input, output, temp;
	int T;
	std::cin >> T;
	std::cin.ignore();

	while (T-- > 0)
	{
		std::getline(std::cin, input);
		for (const auto& elem : input)
		{
			if (elem == ' ')
			{
				for (int idx = 0; idx < temp.size() / 2; idx++)
				{
					std::swap(temp[idx], temp[temp.size() - 1 - idx]);
				}
				output += temp + ' ';
				temp.clear();
				continue;
			}
			temp += elem;
		}
		for (int idx = 0; idx < temp.size() / 2; idx++)
		{
			std::swap(temp[idx], temp[temp.size() - 1 - idx]);
		}
		output += temp + ' ';
		temp.clear();
		output += '\n';
	}

	std::cout << output;
}
*/

// PROBLEM 11656
/*
void Problem_11656()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::string input, output;

	std::vector<std::string> data(input.size());

	std::cin >> input;
	for (int idx = 0; idx <= input.size() - 1; idx++)
	{
		data.emplace_back(input.substr(idx, input.size() - idx));
	}
	
	std::sort(data.begin(), data.end(), [](const std::string& lhs, const std::string& rhs)
		{
			return lhs < rhs;
		});

	for (const auto& elem : data)
	{
		output += elem + '\n';
	}

	std::cout << output;
}
*/

// PROBLEM 10988
/*
void Problem_10988()
{
	std::string input;
	std::cin >> input;
	int res = 1;
	for (int idx = 0; idx < input.size() / 2; idx++)
	{
		if (input[idx] != input[input.size() - idx - 1])
		{
			res = 0;
			break;
		}
	}

	std::cout << res;
}
*/

// PROBLEM 10798
/*
void Problem_10798()
{
	std::string input[5];
	for (int idx = 0; idx < 5; idx++)
	{
		std::cin >> input[idx];
	}

	std::string output;
	for (int ch = 0; ch < 15; ch++)
	{
		for (int idx = 0; idx < 5; idx++)
		{
			if (input[idx].size() >= ch + 1)
			{
				output += input[idx][ch];
			}
		}
	}

	std::cout << output;
}
*/

// PROBLEM 4458
/*
void Problem_4458()
{
	int n;
	std::cin >> n;
	std::string input, output;
	std::cin.ignore();
	while (n-- > 0)
	{
		std::getline(std::cin, input);
		if (input[0] >= 'a' && input[0] <= 'z')
		{
			input[0] -= 32;
		}

		output += input + '\n';
	}

	std::cout << output;
}
*/

// PROBLEM 11655
/*
void Problme_11655()
{
	std::string input;
	std::getline(std::cin, input);

	for (int idx = 0; idx < input.size(); idx++)
	{
		if (input[idx] >= 'a' && input[idx] <= 'z')
		{
			input[idx] = ((input[idx] - 'a' + 13) % 26) + 'a';
		}
		else if (input[idx] >= 'A' && input[idx] <= 'Z')
		{
			input[idx] = ((input[idx] - 'A' + 13) % 26) + 'A';
		}
	}

	std::cout << input;
}
*/

// PROBLEM 10820
/*
void Problem_10820()
{
	std::string output;
	std::string input;

	while (std::getline(std::cin, input))
	{
		int res[4] = { 0 };

		for (const auto& elem : input)
		{
			if (elem >= 'a' && elem <= 'z') { res[0]++; continue; }
			if (elem >= 'A' && elem <= 'Z') { res[1]++; continue; }
			if (elem >= '0' && elem <= '9') { res[2]++; continue; }
			if (elem == ' ') { res[3]++; }
		}

		for (int idx = 0; idx < 4; idx++)
		{
			output += std::to_string(res[idx]) + ' ';
		}
		output += '\n';
	}

	std::cout << output;
}
*/

// PROBLEM 1439
/*
void Problem_1439()
{
	std::string input;
	std::cin >> input;
	char current = input[0];
	int nums[2] = { 0 };
	for (const auto& elem : input)
	{
		if (current != elem)
		{
			nums[current - '0']++;
			current = elem;
		}
	}
	nums[current - '0']++;

	std::cout << std::min(nums[0], nums[1]);
}
*/

// PROBLEM 1406
/*
void Problem_1406()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T;
	std::string num;
	std::list<char> data;
	char inCh;

	while (true)
	{
		std::cin >> inCh;
		if (inCh >= '0' && inCh <= '9') { num += inCh;  continue; }
		if (num.size() != 0) { break; }
		data.emplace_back(inCh);
	}

	T = std::stoi(num);

	std::list<char>::iterator cursorPos = data.end();
	char operation = inCh;
	bool isFirst = true;
	while (T-- > 0)
	{
		if(!isFirst){ std::cin >> operation; }
		else { isFirst = false; }

		switch (operation)
		{
		case 'L':
			if (cursorPos != data.begin()) { cursorPos--; }
			break;
		case 'D' :
			if (cursorPos != data.end()) { cursorPos++; }
			break;
		case 'B':
			if (cursorPos != data.begin()) { cursorPos = data.erase(--cursorPos); }
			break;
		case 'P':
			std::cin >> operation;
			data.insert(cursorPos, operation);
			break;
		default:
			break;
		}
	}

	std::string output;
	for (const auto& elem : data)
	{
		output += elem;
	}

	std::cout << output;
}
*/

// PROBLEM 7567

void Problem_7567()
{
	std::string input;
	std::cin >> input;

	long long sum = 10;
	char prev = input[0];

	for (int idx = 1; idx < input.size(); idx++)
	{
		if (prev == input[idx])
		{
			sum += 5;
		}
		else { sum += 10; }
		prev = input[idx];
	}

	std::cout << sum;
}

void ExecuteString()
{
	//Problem_7567();
	//Problem_1406();
	//Problem_1439();
	//Problem_10820();
	//Problme_11655();
	//Problem_4458();
	//Problem_10798();
	//Problem_10988();
	//Problem_11656();
	//Problem_9093();
	//Problem_1373();
	//Problem_1212();
	//Problem_2902();
	//Problem_10610();
	//Problem_1032();
	//Problem_1259();
	//Problem_1764();
	//Problem_2743();
	//Problem_10808();
	//Problem_11719();
	//Problem_11721();
	//Problem_11718();
	//Problem_4354();
	//Problem_18441_Trial();
	//Problem_18441();
	//Problem_9251();
	//Problem_18441_Trial_4();
	//Problem_9252();
	//Problem_18441_Retry();
	//Problem_18441_Retry_Bitset();
	//Problem_1152();
	//Problem_1018();
	//Problem_1120();
	//Problem_1110();
	//Problem_2577();
	//Problem_8958();
	//Problem_11720();
	//Problem_10809();
	//Problem_2675();
	//Problem_1157();
	//Problem_5622();
	//Problem_2941();
	//Problem_1316();
}