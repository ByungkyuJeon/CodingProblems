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

void executeCodilityLessons()
{
    
}