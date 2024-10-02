#include <bits/stdc++.h>
using namespace std;

bool isPossibleThatDays(int days, vector<int> &bloomDay, int requiredtokari, int requiredflowers)
{

    int totaltokari = 0;
    int count = 0;

    long long size = bloomDay.size();

    for (int i = 0; i < size; i++)
    {
        if (bloomDay[i] <= days)
        {
            count++;
        }
        else
        {
            totaltokari += count / requiredflowers;
            count = 0;
        }
    }

    // for ending flowers that have bloom
    totaltokari += count / requiredflowers;

    if (totaltokari >= requiredtokari)
    {
        return true;
    }
    return false;
}
int minDays(vector<int> &bloomDay, int m, int k)
{

    long long size = bloomDay.size();
    long long val = m * 1ll * k * 1ll;
    if (size < val)
    {
        return -1;
    }

    long long min = INT_MAX;
    long long max = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (bloomDay[i] > max)
        {
            max = bloomDay[i];
        }
        if (bloomDay[i] < min)
        {
            min = bloomDay[i];
        }
    }

    int low = min;
    int high = max;
    int min_days = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossibleThatDays(mid, bloomDay, m, k))
        {
            min_days = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return min_days;
}
int main()
{

    return 0;
}