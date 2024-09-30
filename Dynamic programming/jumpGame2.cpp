#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int index, vector<int> &nums, int n)
    {
        // BASE CASE
        if (index == n - 1)
            return 0;
        if (nums[index] == 0)
            return INT_MAX;

        // LOGIC
        long long minJump = INT16_MAX;
        for (int i = 1; i <= nums[index]; i++)
        {

            if (index + i < n)
            {

                long long jump = 1 + (long long)helper(index + i, nums, n);

                minJump = min(minJump, jump);
            }
        }

        // RETURN
        return (int)minJump;
    }
    int jump(vector<int> &nums)
    {
        int n = nums.size();

        int ans = helper(0, nums, n);

        return ans;
    }
};

// tabulation
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, 0);

        // BASE CASE already fill with 0

        for (int index = n - 2; index >= 0; index--)
        {
            if (nums[index] == 0)
                dp[index] = INT_MAX;
            // LOGIC
            long long minJump = INT16_MAX;
            for (int i = 1; i <= nums[index]; i++)
            {

                if (index + i < n)
                {

                    long long jump = 1 + (long long)dp[index + i];

                    minJump = min(minJump, jump);
                }
            }

            // RETURN
            dp[index] = (int)minJump;
        }

        int ans = dp[0];

        return ans;
    }
};

