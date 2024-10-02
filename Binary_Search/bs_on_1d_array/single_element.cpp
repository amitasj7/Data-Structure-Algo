#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();

    // for single element
    if (n == 1)
        return nums[0];

    // for 1st element and last element
    if (nums[0] != nums[1])
        return nums[0];

    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {

        int mid = low + (high - low) / 2;
        if ((nums[mid] != nums[mid - 1]) && (nums[mid] != nums[mid + 1]))
        {

            return nums[mid];
        }

        // left half (even,odd)
        // if we stand on even condition then next element same
        // if we stand on odd condition then previous element same
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
        {
            low = mid + 1;
        }
        // right half(odd,even)
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