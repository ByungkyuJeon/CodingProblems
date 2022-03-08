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

void executeCodilityLessons()
{
    
}