#include <bits/stdc++.h>
using namespace std;


    pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    // Write your code here.
    sort(arr, arr + n);

    if (x < arr[0])
    {
        return {-1, arr[0]};
    }
    if (x > arr[n - 1])
    {
        return {arr[n - 1], -1};
    }

    int low = 1;
    int high = n - 2;
    while (low <= high)
    {

        auto it = lower_bound(arr + 1, arr + n - 1, x);

        if (*it == x)
        {

            return {x, x};
        }
        return {*(it - 1), *(it)};
    }
    return {-1, -1};
}
int main()
{

    return 0;
}