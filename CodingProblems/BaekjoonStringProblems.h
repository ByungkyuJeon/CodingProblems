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

	/*int lhsBuffer, rhsBuffer;
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
	}*/

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

			resultStr_18441.clear();
			boundary = 0;
			while (++boundary < S_18441.size())
			{
				LCS_BT_Mem_18441(boundary);
			}

			if (resultStr_18441.empty()) { outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(0) + '\n'); continue; }
			outputStr.append("Case #" + std::to_string(counter++) + ": " + std::to_string(resultStr_18441.size() * 2) + '\n' + resultStr_18441 + resultStr_18441 + '\n');
		}

		std::cout << outputStr;

		});

	std::cout << consumedTime << " ms\n";
}

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

void ExecuteString()
{
	//Problem_4354();
	//Problem_18441_Trial();
	//Problem_18441();
	//Problem_9251();
	Problem_18441();
}