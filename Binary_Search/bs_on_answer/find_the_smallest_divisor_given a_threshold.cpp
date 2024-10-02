#include <bits/stdc++.h>
using namespace std;

bool isPossibledivisor(int divisor, vector<int> &nums, int threshold)
{
    int size = nums.size();
    int divisorsum = 0;

    for (int i = 0; i < size; i++)
    {

        divisorsum += ceil(double(nums[i]) / divisor);
        // cout << "ceil : " << ceil(double(nums[i]) / divisor) << endl;
        // cout << "time: " << divisorsum << endl;
        if (divisorsum > threshold)
        {
            return false;
        }
    }
    return true;
}
int smallestDivisor(vector<int> &nums, int threshold)
{

    int size = nums.size();
    int max = INT_MIN;
    // calculate max  value ->
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }

    int low = 1;
    int high = max;
    int smallestdivisor = 1;
    while (low <= high)
    {
        // find mid point
        int mid = low + (high - low) / 2;

        if (isPossibledivisor(mid, nums, threshold))
        {
            // cout << "True" << endl;
            smallestdivisor = mid;
            high = mid - 1;
        }
        else
        {
            // cout << "False" << endl;
            low = mid + 1;
        }
    }
    return smallestdivisor;
}
int main()
{

    return 0;
}