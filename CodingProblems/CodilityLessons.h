#pragma once
#include <vector>
#include <cmath>
#include <numeric>
#include <unordered_set>

int solution_TapeEquilibrium(std::vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    long long sum[2];

    sum[0] = A[0];
    sum[1] = std::accumulate(A.begin() + 1, A.end(), 0);

    long long temp;
    long long res = std::abs(sum[0] - sum[1]);
    for (int p = 1; p < A.size(); p++)
    {
        sum[0] += A[p];
        sum[1] -= A[p];
        if ((temp = std::abs(sum[0] - sum[1])) < res) { res = temp; }
    }
    return res;
}

int solution_FrogRiverOne(int X, std::vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    std::unordered_set<int> leftLeaves;
    std::unordered_set<int>::iterator itr;
    leftLeaves.reserve(sizeof(int) * X);
    for (int num = 1; num <= X; num++)
    {
        leftLeaves.emplace(num);
    }

    int res;
    for (int idx = 0; idx < A.size(); idx++)
    {
        if ((itr = leftLeaves.find(A[idx])) != leftLeaves.end())
        {
            leftLeaves.erase(itr);
        }
        if (leftLeaves.empty())
        {
            res = idx;
            break;
        }
    }
    if (leftLeaves.empty())
    {
        return res;
    }
    else { return -1; }
}

int solution_PermCheck(std::vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    std::unordered_set<int> check;
    std::unordered_set<int>::iterator itr;
    check.reserve(sizeof(int) * A.size());
    for (int num = 1; num <= A.size(); num++)
    {
        check.emplace(num);
    }
    for (const auto& elem : A)
    {
        if ((itr = check.find(elem)) != check.end())
        {
            check.erase(itr);
        }
        else
        {
            break;
        }
    }

    if (check.empty())
    {
        return 1;
    }
    else { return 0; }
}

std::vector<int> solution_MaxCounters_77p(int N, std::vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    std::vector<int> res(N);
    int max = 0;
    for (const auto& elem : A)
    {
        if (elem <= N)
        {
            res[elem - 1]++;
            if (res[elem - 1] > max) { max = res[elem - 1]; }
        }
        else
        {
            std::fill(res.begin(), res.end(), max);
        }
    }
    return res;
}

std::vector<int> solution_MaxCounters(int N, std::vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    std::vector<int> res(N);
    int max = 0, alocMax = 0, idx;
    for (const auto& elem : A)
    {
        if (elem == N + 1)
        {
            alocMax = max;
            continue;
        }

        idx = elem - 1;
        if (res[idx] < alocMax) { res[idx] = alocMax; }
        if (++res[idx] > max) { max = res[idx]; }
    }
    for (auto& elem : res)
    {
        if (elem < alocMax) { elem = alocMax; }
    }

    return res;
}

int solution_MissingInteger(std::vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    std::set<int> data;
    for (int num = 1; num <= A.size() + 1; num++)
    {
        data.emplace(num);
    }

    std::set<int>::iterator itr;
    for (const auto& elem : A)
    {
        if ((itr = data.find(elem)) != data.end())
        {
            data.erase(itr);
        }
    }
    return *data.begin();
}

int solution_PassingCars(std::vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int easts = 0, res = 0;
    for (const auto& elem : A)
    {
        if (elem)
        {
            res += easts;
            if (res > 1000000000) { res = -1; break; }
        }
        else
        {
            easts++;
        }
    }
    return res;
}

/*
int solution_CountDiv(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    return (B / K) - (A % K == 0 ? A / K : (A / K) + 1) + 1;
}
*/

/*
int getNum(char ch)
{
    switch (ch)
    {
    case 'A': return 1;
    case 'C': return 2;
    case 'G': return 3;
    case 'T': return 4;

    default:
        break;
    }
}

long long makeSegTree(std::vector<int>& seg, const std::string& data, int start, int end, int node)
{
    if (start == end) { seg[node] = getNum(data[start - 1]); return seg[node]; }
    int mid = (start + end) / 2;
    
    seg[node] = std::min(makeSegTree(seg, data, start, mid, 2 * node), makeSegTree(seg, data, mid + 1, end, 2 * node + 1));
    return seg[node];
}

long long getSegNode(std::vector<int>& seg, int start, int end, int node, int left, int right)
{
    if (left > end || right < start) { return INT_MAX; }

    if (start >= left && end <= right) { return seg[node]; }

    int mid = (start + end) / 2;
    return std::min(getSegNode(seg, start, mid, 2 * node, left, right), getSegNode(seg, mid + 1, end, 2 * node + 1, left, right));
}

std::vector<int> solution_GenomicRangeQuery(std::string& S, std::vector<int>& P, std::vector<int>& Q) {
    // write your code in C++14 (g++ 6.2.0)
    std::vector<int> segTree(S.size() * 4);
    makeSegTree(segTree, S, 1, S.size(), 1);
    std::vector<int> res;
    int lhs, rhs;
    for (int idx = 0; idx < P.size(); idx++)
    {
        res.emplace_back(getSegNode(segTree, 1, S.size(), 1, P[idx] + 1, Q[idx] + 1));
    }
    return res;
}
*/

/*
long long makeSegTree(std::vector<long long>& seg, const std::vector<int>& data, int start, int end, int node)
{
    if (start == end) { seg[node] = data[start - 1]; return seg[node]; }
    int mid = (start + end) / 2;
    int size = end - start + 1;

    seg[node] = makeSegTree(seg, data, start, mid, 2 * node) + makeSegTree(seg, data, mid + 1, end, 2 * node + 1);
    return seg[node];
}

long long getSegNode(std::vector<long long>& seg, int start, int end, int node, int left, int right)
{
    if (left > end || right < start) { return 0; }

    if (start >= left && end <= right) { return seg[node]; }

    int mid = (start + end) / 2;
    int size = end - start + 1;
    return getSegNode(seg, start, mid, 2 * node, left, right) + getSegNode(seg, mid + 1, end, 2 * node + 1, left, right);
}

// 60%
int solution_MinAvgTwoSlice60p(std::vector<int>& A) {
    double min = 1000000000;
    double temp;
    int minIdx = 0;
    std::vector<long long> seg(A.size() * 4);
    makeSegTree(seg, A, 1, A.size(), 1);
    for (int idx = 0; idx < A.size(); idx++)
    {
        for (int slice = 2; slice <= 3; slice++)
        {
            if (min > (temp = (double)getSegNode(seg, 1, A.size(), 1, idx + 1, idx + slice) / slice))
            {
                min = temp;
                minIdx = idx;
            }
        }
    }
    return minIdx;
}

int solution_MinAvgTwoSlice(std::vector<int>& A) {
    double min = 1000000000;
    double temp;
    int minIdx = 0;
    int slice = 2;
    for (int idx = 0; idx < A.size() - 1; idx++)
    {
        if (min > (temp = (double)(A[idx] + A[idx + 1]) / 2))
        {
            min = temp;
            minIdx = idx;
        }
    }

    for (int idx = 0; idx < A.size() - 2; idx++)
    {
        if (min > (temp = (double)(A[idx] + A[idx + 1] + A[idx + 2]) / 3))
        {
            min = temp;
            minIdx = idx;
        }
    }

    return minIdx;
}
*/

int solution_MaxProductOfThree(std::vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    std::sort(A.begin(), A.end());
    long long lhs = *(A.end() - 1) * *(A.end() - 2) * *(A.end() - 3);
    long long rhs = LLONG_MIN;
    if ((rhs = *A.begin() * *(A.begin() + 1)) > 0)
    {
        rhs *= *(A.end() - 1);
    }

    return lhs > rhs ? lhs : rhs;
}

void executeCodilityLessons()
{
    std::vector<int> d{ -3,1,2,-2,5,6 };
    std::cout << solution_MaxProductOfThree(d);
}