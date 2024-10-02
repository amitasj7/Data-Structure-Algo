#include <bits/stdc++.h>
using namespace std;

bool isPossibleEatbananas(int eatingBanana, vector<int> &piles, int deadlineTime)
{

    int size = piles.size();
    int requiredTime = 0;

    for (int i = 0; i < size; i++)
    {

        requiredTime += ceil(double(piles[i]) / eatingBanana);
        cout << "ceil : " << ceil(double(piles[i]) / eatingBanana) << endl;
        cout << "time: " << requiredTime << endl;
        if (requiredTime > deadlineTime)
        {
            return false;
        }
    }
    return true;
}
int minEatingSpeed(vector<int> &piles, int h)
{

    int size = piles.size();
    int max = INT_MIN;
    // calculate max  value ->
    for (int i = 0; i < size; i++)
    {
        if (piles[i] > max)
        {
            max = piles[i];
        }
    }

    int low = 1;
    int high = max;
    int bananaPerHour = 1;
    while (low <= high)
    {
        // find mid point
        int mid = low + (high - low) / 2;

        if (isPossibleEatbananas(mid, piles, h))
        {
            cout << "True" << endl;
            bananaPerHour = mid;
            high = mid - 1;
        }
        else
        {
            cout << "False" << endl;
            low = mid + 1;
        }
    }
    return bananaPerHour;
}
int main()
{
    vector<int> piles = {30, 11, 23, 4, 20};

    cout << minEatingSpeed(piles, 5) << endl;

    return 0;
}