#include <bits/stdc++.h>
using namespace std;

/*
Problem link -
https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

*/

// only for positive value  0<= nums[i] <= 107
class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;
        // find total sum of nums
        for (int num : nums)
        {
            sum += abs(num);
        }
        vector<vector<long long>> dp(n, vector<long long>(sum + 1, 0));

        // BASE CASE
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if (nums[0] <= sum) // agar 0th element sum se bda nikal gya to dp me cell nahi milegi
            dp[0][nums[0]] = true;

        for (int index = 1; index < n; index++)
        {
            for (int target = 1; target <= sum; target++)
            {
                // LOGIC
                bool notPick = dp[index - 1][target];

                bool pick = false; // abhi possible nahi hai isliye false de diya hia
                if (nums[index] <= target)
                {

                    pick = dp[index - 1][target - nums[index]];
                }

                // RETURN

                dp[index][target] = pick || notPick;
            }
        }

        int mini = 1e9;

        for (int i = 0; i <= sum; i++)
        {

            if (dp[n - 1][i] == true)
            {
                int s1 = i;
                int s2 = sum - s1;

                mini = min(mini, abs(s1 - s2));
            }
        }

        return mini;
    }
};