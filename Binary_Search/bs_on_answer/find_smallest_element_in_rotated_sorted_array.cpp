#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{

    int n = nums.size();

    int low = 0;
    int high = n - 1;

    int smallest = INT_MAX;
    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        // left half sorted
        // low wala chhota element utho and left ko chhod do
        if (nums[mid] >= nums[low])
        {
            smallest = min(smallest, nums[low]);
            low = mid + 1;
        }

        else
        {

            smallest = min(smallest, nums[mid]);
            high = mid - 1;
        }
    }
    return smallest;
}
int main()
{

    return 0;
}