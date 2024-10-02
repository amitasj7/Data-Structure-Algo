#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)
{
    // Write your code here.

    int n = arr.size();

    int low = 0;
    int high = n - 1;

    int smallest_index = -1;
    int smallest = INT_MAX;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        // left half sorted
        // low wala chhota element utho and left ko chhod do
        if (arr[mid] >= arr[low])
        {
            if (smallest > arr[low])
            {
                smallest = arr[low];
                smallest_index = low;
            }

            low = mid + 1;
        }

        else
        {

            if (smallest < arr[mid])
            {
                smallest = arr[mid];
                smallest_index = mid;
            }

            high = mid - 1;
        }
    }
    return smallest_index;
}
int main()
{

    return 0;
}