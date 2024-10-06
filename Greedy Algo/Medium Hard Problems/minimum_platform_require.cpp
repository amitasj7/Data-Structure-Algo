#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    // sort arrival time and departure time
    sort(at, at + n);
    sort(dt, dt + n);

    // maximum 1 platform maintain rahega

    int platform = 1;
    int max_platform = 1;

    int i = 1, j = 0;

    while (i < n && j < n)
    {
        // new Platform add
        if (at[i] <= dt[j])
        {
            platform++;

            // update max_platform

            i++;
        }

        // Platform remove
        else
        {
            j++;
            platform--;
        }
        max_platform = max(max_platform, platform);
    }

    return max_platform;
}