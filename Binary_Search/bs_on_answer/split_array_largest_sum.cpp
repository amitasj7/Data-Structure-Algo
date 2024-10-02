#include <bits/stdc++.h>
using namespace std;

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.

    int size = boards.size();

    int maxele = INT_MIN;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += boards[i];

        maxele = max(maxele, boards[i]);
    }

    // apply binary search b/w maxelement and sum

    int low = maxele;
    int high = sum;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (countpainters(mid, boards, size) > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int countpainters(int time, vector<int> &nums, int size)
{
    int totalpainters = 1;
    int totaltime = 0;
    for (int i = 0; i < size; i++)
    {
        totaltime += nums[i];

        if (totaltime > time)
        {
            totalpainters++;
            totaltime = nums[i];
        }
    }

    return totalpainters;
}
int splitArray(vector<int> &nums, int k)
{

    int size = nums.size();

    int maxele = INT_MIN;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += nums[i];

        maxele = max(maxele, nums[i]);
    }

    // apply binary search b/w maxelement and sum

    int low = maxele;
    int high = sum;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (countpainters(mid, nums, size) > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{

    return 0;
}