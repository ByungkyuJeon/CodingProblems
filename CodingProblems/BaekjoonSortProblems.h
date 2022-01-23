#pragma once
#include <iostream>
#include <bitset>

// PROBLEM 1377
/*
std::pair<int,int> data[500001];
int test[500001];

int Problem_1377_Testee(int N)
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    //int N; 
    int result = 0;
   // std::cin >> N;
   // for (int idx = 1; idx <= N; idx++)
   // {
   //     std::cin >> data[idx];
   // }

    std::sort(data + 1, data + N + 1);

    for (int idx = 1; idx < N; idx++)
    {
        if (result < data[idx].second - idx)
        {
            result = data[idx].second - idx;
        }
    }

    return result + 1;
    //std::cout << result;
}

void Problem_1377_Test()
{
    std::srand(std::time(NULL));

    int N = (std::rand() % 100) + 1;
    int testResult = 1, originResult;
    
    while (true)
    {
        N = 5;

        for (int idx = 1; idx <= N; idx++)
        {
            test[idx] = (std::rand() % 1000000) + 1;
            data[idx].first = test[idx];
            data[idx].second = idx;
        }

        bool changed = false;
        for (int i = 1; i <= N + 1; i++) {
            changed = false;
            for (int j = 1; j <= N - i; j++) {
                if (test[j] > test[j + 1]) {
                    changed = true;
                    std::swap(test[j], test[j + 1]);
                }
            }
            if (changed == false) {
                testResult = i;
                break;
            }
        }

        if ((originResult = Problem_1377_Testee(N)) == testResult)
        {
            std::cout << "pass" << '\n';
        }
        else
        {
            std::cout << "fail" << '\n';
            break;
        }
    }
}

void Problem_1377()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int N; 
    int result = 0;
    std::cin >> N;
    for (int idx = 1; idx <= N; idx++)
    {
        std::cin >> data[idx].first;
        data[idx].second = idx;
    }

    std::sort(data + 1, data + N + 1);

    for (int idx = 1; idx < N; idx++)
    {
        if (result < data[idx].second - idx)
        {
            result = data[idx].second - idx;
        }
    }

    std::cout << result + 1;
}
*/

// PROBLEM 1838
/*
std::pair<int, int> data[500001];

void Problem_1838()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int N;
    int result = 0;
    std::cin >> N;
    for (int idx = 1; idx <= N; idx++)
    {
        std::cin >> data[idx].first;
        data[idx].second = idx;
    }

    std::sort(data + 1, data + N + 1);

    for (int idx = 1; idx < N; idx++)
    {
        if (result < data[idx].second - idx)
        {
            result = data[idx].second - idx;
        }
    }

    std::cout << result;
}
*/

// PROBLEM 1517

int data[500001];
int temp[500001];

long long merge(int left,int mid, int right)
{
    int lhsStart = left;
    int rhsStart = mid + 1;
    int count = 0;
    long long crossCount = 0;
    long long rightCount = 0;

    while (lhsStart <= mid && rhsStart <= right)
    {
        if (data[lhsStart] <= data[rhsStart]) { temp[left + count++] = data[lhsStart++]; crossCount += rightCount; }
        else { temp[left + count++] = data[rhsStart++]; rightCount++; }
    }

    while (lhsStart <= mid){ temp[left + count++] = data[lhsStart++]; crossCount += rightCount; }
    while (rhsStart <= right){ temp[left + count++] = data[rhsStart++]; rightCount++; }

    memcpy(data + left, temp + left, sizeof(int) * (right - left + 1));

    return crossCount;
}

long long mergeSort(int start, int end)
{
    if (start == end) { return 0; }
    int mid = start + (end - start) / 2;
    long long lhsCrossCount = mergeSort(start, mid);
    long long rhsCrossCount = mergeSort(mid + 1, end);
    return merge(start, mid, end) + lhsCrossCount + rhsCrossCount;
}

void Problem_1517()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    for (int idx = 0; idx < N; idx++)
    {
        std::cin >> data[idx];
    }

    std::cout << mergeSort(0, N - 1);
}

void ExecuteSort()
{
    //Problem_1377();
    //Problem_1377_Test();
    //Problem_1377();
    //Problem_1838();
    Problem_1517();
}