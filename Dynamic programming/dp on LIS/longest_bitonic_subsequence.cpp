#include <bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int> &arr, int n)

{

    vector<int> dp1(n, 1), dp2(n, 1);

    int ans = 0;

    // fill dp1
    for (int current = 0; current < n; current++)
    {
        // fill current element longest incresing subsequence
        for (int prev = 0; prev < current; prev++)
        {

            if (arr[prev] < arr[current] && 1 + dp1[prev] > dp1[current])
            {
                // update current length
                dp1[current] = 1 + dp1[prev];
            }
        }
    }

    //   fill dp2 and calculate ans
    for (int current = n - 1; current >= 0; current--)
    {
        // fill current element longest incresing subsequence
        for (int prev = n - 1; prev > current; prev--)
        {

            if (arr[prev] < arr[current] && 1 + dp2[prev] > dp2[current])
            {
                // update current length
                dp2[current] = 1 + dp2[prev];
            }
        }
        // fill ans
        ans = max(ans, dp1[current] + dp2[current] - 1);
    }

    return ans;
}