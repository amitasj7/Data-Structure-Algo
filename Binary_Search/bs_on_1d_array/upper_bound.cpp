#include<bits/stdc++.h>
using namespace std;



    if (arr[n - 1] <= x)
        return n;

    int low = 0, high = n - 1;

    int lower_bound = INT_MIN;
    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
        {
            lower_bound = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return lower_bound;
int main()
{
    

return 0;
}