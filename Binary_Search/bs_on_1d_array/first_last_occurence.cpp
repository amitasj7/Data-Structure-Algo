#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();

    int first = -1;
    int last = -1;
    // target doesn't exist in nums
    if (n == 0 || target < nums[0] || target > nums[n - 1])
    {
        return {first, last};
    }

    int low = 0, high = n - 1;

    // finding first position
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }

        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {

            high = mid - 1;
        }
    }

    // finding last position
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }

        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {

            high = mid - 1;
        }
    }

    return {first, last};
}
int main()
{

    return 0;
}