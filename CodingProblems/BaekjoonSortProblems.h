#pragma once
#include <iostream>
#include <bitset>

// PROBLEM 1377

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

        if ((originResult = Problem_1377(N)) == testResult)
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


void ExecuteSort()
{
    //Problem_1377();
    //Problem_1377_Test();
    Problem_1377();
}