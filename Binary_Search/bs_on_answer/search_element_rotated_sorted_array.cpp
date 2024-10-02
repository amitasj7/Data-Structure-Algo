#include <bits/stdc++.h>
using namespace std;


// if  element repeat then process this -> 
bool search(vector<int> &nums, int target)
{

    int n = nums.size();

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[mid] == nums[low] && nums[mid] == nums[high])
        {
            // shrink array
            low++;
            high--;
            continue;
        }

        // left array is sorted then

        if (nums[low] <= nums[mid])
        {
            // target exist
            if (target >= nums[low] && target <= nums[mid])
            {

                high = mid - 1;
            }
            else
            {
                // leave sorted array
                low = mid + 1;
            }
        }

        // Right array is sorted then

        if (nums[high] >= nums[mid])
        {
            // target exist
            if (target <= nums[high] && target >= nums[mid])
            {

                low = mid + 1;
            }
            else
            {
                // leave sorted array
                high = mid - 1;
            }
        }
    }

    return false;
}

// if element are unique 
int search(vector<int> &nums, int target)
{

    int n = nums.size();

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        // left array is sorted then

        if (nums[low] <= nums[mid])
        {
            // target exist
            if (target >= nums[low] && target <= nums[mid])
            {

                high = mid - 1;
            }
            else
            {
                // leave sorted array
                low = mid + 1;
            }
        }

        // Right array is sorted then

        if (nums[high] >= nums[mid])
        {
            // target exist
            if (target <= nums[high] && target >= nums[mid])
            {

                low = mid + 1;
            }
            else
            {
                // leave sorted array
                high = mid - 1;
            }
        }
    }

    return -1;
}
int main()
{

    return 0;
}