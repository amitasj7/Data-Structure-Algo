#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;

    // first element is peak element
    if (nums[0] > nums[1])
        return 0;

    // last element is peak element
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    // for remaining element
    int low = 1, high = n - 2;
    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        // if mid present on left side of peak element
        if (nums[mid - 1] < nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{

    return 0;
}