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
/*
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
*/

// PROBLEM 1083
/*
std::vector<int> v;
int data[51];
int test[51];
int count = 0;

std::vector<int> Problem_1083(int N, int S)
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    
    std::vector<int> result;
    //int data[51];

    //int N, S;
    //std::cin >> N;

    for (int idx = 0; idx < N; idx++)
    {
        //std::cin >> data[idx];
        //data[idx] = v[idx];
    }
    //std::cin >> S;
    int maxIdx, startIdx, endIdx;
    int completed = -1;
    while (completed != N - 1)
    {
        startIdx = completed + 1;
        endIdx = startIdx + (S + 1 < N - 1 - completed ? S + 1 : N - 1 - completed);
        maxIdx = startIdx;
        for (int idx = startIdx + 1; idx < endIdx; idx++){ if (data[idx] > data[maxIdx]) { maxIdx = idx; } }
        for (int idx = maxIdx; idx > completed + 1; idx--)
        {
            std::swap(data[idx], data[idx - 1]);
            S--;
        }
        completed++;
        if (S <= 0) { break; }
    }

    for (int idx = 0; idx < N; idx++)
    {
        //std::cout << data[idx] << " ";
        result.emplace_back(data[idx]);
    }

    return result;
}

void Problem_1083_Test()
{
    std::srand(std::time(NULL));

    int n = 50;
   
    v.resize(n);
    while (true)
    {
        n = 5;
        v.clear();
        v.resize(n);
        for (int idx = 0; idx < n; idx++)
        {
            v[idx] = (std::rand() % 1000000) + 1;
            data[idx] = v[idx];
            test[idx] = v[idx];
        }

        int s = 10;
        int cpyS = s;

        int mx, idx;
        for (int i = 0; i < n && s; ++i) {
            mx = idx = -1;
            for (int j = i, k = 0; j < n && k <= s; ++j, ++k)
                if (mx < v[j]) {
                    mx = v[j];
                    idx = j;
                }

            for (int j = idx; j > i && s; --j, --s)
                std::swap(v[j], v[j - 1]);
        }

        std::vector<int> ret = Problem_1083(n, cpyS);

        for (int idx = 0; idx < n; idx++)
        {
            if (ret[idx] != v[idx])
            {
                std::cout << "false";
            }
        }
        std::cout << count++ << std::endl;
    }
}

void Problem_1083()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int nums[51];

    int N, S;
    std::cin >> N;

    for (int idx = 0; idx < N; idx++)
    {
        std::cin >> nums[idx];
    }
    std::cin >> S;
    int maxIdx, startIdx, endIdx;
    int completed = -1;
    while (completed != N - 1)
    {
        startIdx = completed + 1;
        endIdx = startIdx + (S + 1 < N - 1 - completed ? S + 1 : N - 1 - completed);
        maxIdx = startIdx;
        for (int idx = startIdx + 1; idx < endIdx; idx++) { if (nums[idx] > nums[maxIdx]) { maxIdx = idx; } }
        for (int idx = maxIdx; idx > completed + 1; idx--)
        {
            std::swap(nums[idx], nums[idx - 1]);
            S--;
        }
        completed++;
        if (S <= 0) { break; }
    }

    for (int idx = 0; idx < N; idx++)
    {
        std::cout << nums[idx] << " ";
    }
}
*/

// PROBLEM 11920

void Probme_11920()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    
    int N, K;
    std::cin >> N >> K;


}

// PROBLEM 20190

int data[300001];
int dataIdices[300001];
int mergeTemp[300001];
int idicesTemp[300001];
long long crossCounts[300001];
int N;

long long merge(int start, int mid, int end)
{
    int leftIdx = start;
    int rightIdx = mid + 1;
    int offset = -1;
    long long crossCount = 0;
    long long rightCount = 0;

    while (++offset <= end - start)
    {
        if (leftIdx > mid || (leftIdx <= mid && rightIdx <= end && data[leftIdx] > data[rightIdx]))
        {
            mergeTemp[offset] = data[rightIdx];
            idicesTemp[offset] = dataIdices[rightIdx++];
            rightCount++;
            if (idicesTemp[offset] != start + offset)
            {
                crossCounts[idicesTemp[offset]] += (mid - leftIdx + 1) - (rightCount - 1);
            }
        }
        else
        {
            mergeTemp[offset] = data[leftIdx];
            idicesTemp[offset] = dataIdices[leftIdx++];
            crossCount += rightCount;
            if (idicesTemp[offset] != start + offset)
            {
                crossCounts[idicesTemp[offset]] += rightCount - (mid - leftIdx + 1);
            }
        }
    }

    offset = 0;
    for (int idx = start; idx <= end; idx++)
    {
        dataIdices[idx] = idicesTemp[offset];
        data[idx] = mergeTemp[offset++];
    }

    return crossCount;
}

long long mergeSort(int start, int end)
{
    if (!(end - start <= 1))
    {
        int mid = (start + end) / 2;
        long long lhCrossCount = mergeSort(start, mid);
        long long rhCrossCount = mergeSort(mid + 1, end);
        return merge(start, mid, end) + lhCrossCount + rhCrossCount;
    }
    if (start == end) { return 0; }
    return merge(start, start, end);
}

void Problem_20190()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    long long totalCrossCount = 0;

    std::cin >> N;
    for (int idx = 0; idx < N; idx++)
    {
        std::cin >> data[idx];
        dataIdices[idx] = idx;
    }

    totalCrossCount = mergeSort(0, N - 1);

    for (int idx = 0; idx < N; idx++)
    {
        std::cout << totalCrossCount - crossCounts[idx] << " ";
    }
}

void ExecuteSort()
{
    //Problem_1377();
    //Problem_1377_Test();
    //Problem_1377();
    //Problem_1838();
    //Problem_1517();
    //Problem_1083_Test();
    //Problem_1083();
    Problem_20190();
}