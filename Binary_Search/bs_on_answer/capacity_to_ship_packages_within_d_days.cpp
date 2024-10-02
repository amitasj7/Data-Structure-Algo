#include <bits/stdc++.h>
using namespace std;

bool capacityPossible(int capacity, vector<int> &weights, int maxdays, long long size)
{
    int totaldays = 1;
    int load = 0;
    for (int i = 0; i < size; i++)
    {
        load += weights[i];
        if (load > capacity)
        {
            totaldays++;
            load = weights[i];
        }
    }
    if (totaldays <= maxdays)
    {
        return true;
    }

    return false;
}
int shipWithinDays(vector<int> &weights, int days)
{

    long long size = weights.size();
    int sum = 0;

    int max = INT_MIN;
    // calculate total weight ->
    for (int i = 0; i < size; i++)
    {
        if (weights[i] > max)
        {
            max = weights[i];
        }
        sum += weights[i];
    }
    int low = max;
    int high = sum;

    int capacity = 0;
    // mid point capacity
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (capacityPossible(mid, weights, days, size))
        {
            capacity = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return capacity;
}
int main()
{

    return 0;
}