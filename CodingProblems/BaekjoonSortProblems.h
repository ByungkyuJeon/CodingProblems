#pragma once
#include <iostream>
#include <bitset>
#include <string>

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
/*
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
            
            //crossCounts[idicesTemp[offset]] += rightCount - ((start + offset) - idicesTemp[offset])
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
*/

// PRBOLEM 11920
/*
int data_11920[100001];
std::priority_queue<int, std::vector<int>, std::greater<int>> subData;

void Problem_11920()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    std::string outputStr;
    int N, K;
    std::cin >> N >> K;

    for (int idx = 0; idx < N; idx++)
    {
        std::cin >> data_11920[idx];
        if (idx < K) { subData.emplace(data_11920[idx]); }
    }

    for (int idx = 0; idx < N - K; idx++)
    {
        subData.emplace(data_11920[idx + K]);
        data_11920[idx] = subData.top();
        subData.pop();

        outputStr += std::to_string(data_11920[idx]) + ' ';
    }

    while (!subData.empty())
    {
        outputStr += std::to_string(subData.top()) + ' ';
        subData.pop();
    }

    std::cout << outputStr;
}
*/

// PROBLEM 24046
/*
int data[500001];
std::vector<std::pair<int, int>> mergeData;
std::vector<std::pair<int, int>> mergeTemp;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> subData;

long long merge(int start, int mid, int end)
{
    int leftIdx = start;
    int rightIdx = mid + 1;
    int offset = -1;
    long long crossCount = 0;
    long long rightCount = 0;
    mergeTemp.resize(end - start + 1);

    while (++offset <= end - start)
    {
        if (leftIdx > mid || (leftIdx <= mid && rightIdx <= end && mergeData[leftIdx].first > mergeData[rightIdx].first))
        {
            mergeTemp[offset] = mergeData[rightIdx++];
            rightCount++;
        }
        else
        {
            mergeTemp[offset] = mergeData[leftIdx++];
            crossCount += rightCount;
        }
    }

    offset = 0;
    for (int idx = start; idx <= end; idx++)
    {
        mergeData[idx] = mergeTemp[offset++];
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

void Problem_24046()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    long long N, K;
    std::cin >> N >> K;

    for (int idx = 0; idx < N; idx++){ std::cin >> data[idx]; }

    long long fullK = 0;
    long long subK;
    int completed = 0;

    while (fullK < K && completed != N - 1)
    {
        if ((subK = ((K - fullK) / (N - 1 - completed)) - 1) > 0)
        {
            mergeData.clear();
            mergeData.resize(subK);
            for (int idx = 0; idx < subK; idx++)
            {
                subData.emplace(std::make_pair(data[idx], idx));
            }
            for (int idx = 0; idx < N - completed; idx++)
            {
                if(idx < N - completed - subK)
                { 
                    subData.emplace(std::make_pair(data[idx + subK], idx + subK));
                    data[idx] = subData.top().first;
                }
                else{ mergeData[idx - (N - completed - subK)] = subData.top(); }
                if (idx - subData.top().second > 0)
                {
                    fullK += idx - subData.top().second;
                }
                subData.pop();
            }

            std::sort(mergeData.begin(), mergeData.end(), [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) { return lhs.second < rhs.second; });
            fullK += mergeSort(0, subK - 1);
            for (int idx = 0; idx < subK; idx++)
            {
                data[idx + N - subK - completed] = mergeData[idx].first;
            }
            completed += subK;
        }
        else
        {
            bool swapped;
            for (int endPoint = 0; endPoint < N - completed; endPoint++)
            {
                swapped = false;
                for (int idx = 0; idx < N - completed - endPoint - 1; idx++)
                {
                    if (data[idx] > data[idx + 1])
                    {
                        if (++fullK == K)
                        {
                            std::cout << data[idx + 1] << " " << data[idx];
                            return;
                        }
                        std::swap(data[idx], data[idx + 1]);
                        swapped = true;
                    }
                }
                if (!swapped)
                {
                    std::cout << -1;
                    return;
                }
            }
        }
    }

    std::cout << -1;
}
*/

// PROBLEM 10818
/*
void Problem_10818()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int N, inputBuffer;
    int min = 1000001, max = -1000001;
    std::cin >> N;

    while (N-- > 0)
    {
        std::cin >> inputBuffer;
        if (inputBuffer > max) { max = inputBuffer; }
        if (inputBuffer < min) { min = inputBuffer; }
    }

    std::cout << min << " " << max;
}
*/

// PROBLEM 2562
/*
void Problem_2562()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int max = INT_MIN, maxIdx, inputBuffer;

    for (int idx = 1; idx < 10; idx++)
    {
        std::cin >> inputBuffer;
        if (inputBuffer > max) { max = inputBuffer; maxIdx = idx; }
    }

    std::cout << max << '\n' << maxIdx;
}
*/

// PROBLEM 3052
/*
void Problem_3052()
{
    typedef int i; std::unordered_map<i, i> m; i b;
    for (i c = 0; c < 10; c++) { std::cin >> b; m[b % 42]; }
    std::cout << m.size();
}
*/

// PROBLEM 2750, 2751
/*
int nums[1000001];

void Problem_2750()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    for (int idx = 0; idx < N; idx++)
    {
        std::cin >> nums[idx];
    }
    std::sort(nums, nums + N);
    std::string outputStr;
    for (int idx = 0; idx < N; idx++)
    {
        outputStr += std::to_string(nums[idx]) + '\n';
    }
    std::cout << outputStr;
}
*/

// PROBLEM 10989
/*
int nums[10001];

void Problem_10989()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    std::string outputStr, tempStr;
    outputStr.reserve(1000000);
    int N, input;
    std::cin >> N;

    while (N-- > 0)
    {
        std::cin >> input;
        nums[input]++;
    }

    for (int num = 1; num <= 10000; num++)
    {
        if ((input = nums[num]) == 0) { continue; }
        else{ tempStr = std::to_string(num) + '\n'; }
        for (int count = 0; count < input; count++)
        {
            outputStr += tempStr;
            if (outputStr.size() > 999900)
            {
                std::cout << outputStr;
                outputStr.clear();
                outputStr.reserve(1000000);
            }
        }
    }

    std::cout << outputStr;
}
*/

// PROBLEM 2108
/*
int nums[500001];
std::unordered_map<int, int> counts;

void Problem_2108()
{
    typedef std::priority_queue<int, std::vector<int>, std::greater<int>> q; q countQueue;
    int N, sum = 0, maxNum = 0, temp;
    std::cin >> N;
    for (int idx = 0; idx < N; idx++)
    {
        std::cin >> nums[idx];
        sum += nums[idx];
        ++counts[nums[idx]];
    }
    for (const auto& elem : counts)
    {
        if (elem.second > counts[maxNum]) { maxNum = elem.first; countQueue = q(); countQueue.emplace(maxNum); }
        else if (elem.second == counts[maxNum]) { countQueue.emplace(elem.first); }
    }
    
    std::sort(nums, nums + N);
    float avr = (float)sum / N;
    if (avr > 0 && avr + 0.5f >= 1 + (int)avr) { std::cout << 1 + (int)avr << '\n'; }
    else if (avr < 0 && avr - 0.5f <= -1 + (int)avr) { std::cout << -1 + (int)avr << '\n'; }
    else { std::cout << (int)avr << '\n'; }
    std::cout << nums[N / 2] << '\n';
    if (countQueue.size() > 1){ countQueue.pop(); }
    std::cout << countQueue.top() << '\n';
    std::cout << nums[N - 1] - nums[0];
}
*/

// PROBLEM 1427
/*
void Problem_1427()
{
    std::string numStr;
    int counts[10] = { 0 };
    std::cin >> numStr;
    for (const auto& elem : numStr){ counts[elem - '0']++; }
    int numIdx = 0;
    for (int idx = 9; idx >= 0; idx--)
    {
        for (int count = 0; count < counts[idx]; count++)
        {
            numStr[numIdx++] = idx + '0';
        }
    }

    std::cout << numStr;
}
*/

// PROBLEM 11650
/*
std::pair<int, int> dots[100001];

void Problem_11650()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    for (int idx = 0; idx < N; idx++)
    {
        std::cin >> dots[idx].first >> dots[idx].second;
    }

    std::sort(dots, dots + N, [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
        if (lhs.first == rhs.first)
        {
            return lhs.second < rhs.second;
        }
        return lhs.first < rhs.first;
        });

    std::string outputStr;
    for (int idx = 0; idx < N; idx++)
    {
        outputStr += std::to_string(dots[idx].first) + " " + std::to_string(dots[idx].second) + '\n';
    }

    std::cout << outputStr;
}
*/

// PROBLEM 11651
/*
std::pair<int, int> dots[100001];

void Problem_11651()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    for (int idx = 0; idx < N; idx++)
    {
        std::cin >> dots[idx].first >> dots[idx].second;
    }

    std::sort(dots, dots + N, [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
        if (lhs.second == rhs.second)
        {
            return lhs.first < rhs.first;
        }
        return lhs.second < rhs.second;
        });

    std::string outputStr;
    for (int idx = 0; idx < N; idx++)
    {
        outputStr += std::to_string(dots[idx].first) + " " + std::to_string(dots[idx].second) + '\n';
    }

    std::cout << outputStr;
}
*/

// PROBLEM 1181
/*
struct Comp
{
    bool operator()(const std::string& lhs, const std::string& rhs) const
    {
        if (lhs.size() == rhs.size())
        {
            return lhs < rhs;
        }
        return lhs.size() < rhs.size();
    }
};

std::set<std::string, Comp> data;

void Problem_1181()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    std::string outputStr, input;
    int N;
    std::cin >> N;
    for (int idx = 0; idx < N; idx++)
    {
        std::cin >> input;
        data.emplace(input);
    }

    for(const auto& elem : data)
    {
        outputStr += elem + '\n';
    }
    std::cout << outputStr;
}
*/

// PROBLEM 10814
/*
std::pair<int, std::string> data[100001];

void Problem_10814()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    for (int idx = 0; idx < N; idx++)
    {
        std::cin >> data[idx].first >> data[idx].second;
    }

    std::stable_sort(data, data + N, [](const std::pair<int, std::string>& lhs, const std::pair<int, std::string>& rhs)
        {
            return lhs.first < rhs.first;
        }
    );

    std::string outputStr;
    for (int idx = 0; idx < N; idx++)
    {
        outputStr += std::to_string(data[idx].first) + " " + data[idx].second + '\n';
    }

    std::cout << outputStr;
}
*/

// PROBLEM 18870
/*
std::map<int, std::vector<int>> data;

void Problem_18870()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int N, input;
    std::cin >> N;
    for (int idx = 0; idx < N; idx++)
    {
        std::cin >> input;
        data[input].emplace_back(idx);
    }

    std::vector<int> outputNums(N);
    int count = 0;
    for (const auto& elem : data)
    {
        for (const auto& indices : elem.second)
        {
            outputNums[indices] = count;
        }
        count++;
    }

    std::string outputStr;
    for (const auto& elem : outputNums)
    {
        outputStr += std::to_string(elem) + " ";
    }

    std::cout << outputStr;
}
*/

void ExecuteSort()
{
    //Problem_1377();
    //Problem_1377_Test();
    //Problem_1377();
    //Problem_1838();
    //Problem_1517();
    //Problem_1083_Test();
    //Problem_1083();
    //Problem_20190();
    //Problem_11920();
    //Problem_24046();
    //Problem_10818();
    //Problem_2562();
    //Problem_3052();
    //Problem_2750();
    //Problem_10989();
    //Problem_2108();
    //Problem_1427();
    //Problem_11650();
    //Problem_11651();
    //Problem_1181();
    //Problem_10814();
    //Problem_18870();
}