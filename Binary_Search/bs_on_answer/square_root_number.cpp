#include <bits/stdc++.h>
using namespace std;

int findNroot(int mid, int n, int number)
{

    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {

        ans = ans * mid;

        if (ans > number)
        {
            return 2;
        }
    }

    if (ans == number)
    {
        return 1;
    }
    return 0;
}
int NthRoot(int n, int m)
{
    // Write your code here.

    int low = 0;
    int high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (findNroot(mid, n, m) == 1)
        {
            return mid;
        }
        else if (findNroot(mid, n, m) == 2)
        {
            // update high
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}
int floorSqrt(int n)
{
    // Write your code here.

    int low = 0;
    int high = n;

    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long square = mid * mid;
        if (square > long long(n))
        {
            // update high
            high = mid - 1;
        }
        else
        {
            ans = mid;
            // update low
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{

    return 0;
}