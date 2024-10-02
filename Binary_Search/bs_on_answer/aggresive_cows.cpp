#include <bits/stdc++.h>
using namespace std;

bool midDistancePossible(int requiredDistance, vector<int> &stalls, int requiredCows)
{

    int TotalCows = 1;
    int lastCowsPosition = stalls[0];

    // update TotalCows
    for (int i = 0; i < stalls.size(); i++)
    {

        if ((stalls[i] - lastCowsPosition) >= requiredDistance)
        {
            TotalCows++;
            lastCowsPosition = stalls[i];
        }
    }

    if (TotalCows >= requiredCows)
    {
        return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.

    // sort stalls
    sort(stalls.begin(), stalls.end());

    // apply binary search between 1 and max-min

    int low = 1;
    int high = stalls.back() - stalls[0];

    int ans = 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (midDistancePossible(mid, stalls, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{

    return 0;
}