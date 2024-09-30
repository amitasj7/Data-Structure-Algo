#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);

        int lis = 0;
        int noLis = 0;

        for (int current = 0; current < n; current++)
        {
            // fill current element longest incresing subsequence
            for (int prev = 0; prev < current; prev++)
            {

                if (nums[prev] < nums[current] && 1 + dp[prev] > dp[current])
                {
                    // update current length
                    dp[current] = 1 + dp[prev];
                    count[current] = count[prev];
                }
                else if (nums[prev] < nums[current] && 1 + dp[prev] == dp[current])
                {
                    count[current] += count[prev];
                }
            }

            if (lis < dp[current])
            {
                lis = dp[current];
            }
        }

        // find all longest increasing subsequence
        for (int i = 0; i < n; i++)
        {
            if (lis == dp[i])
                noLis += count[i];
        }

        return noLis;
    }
};