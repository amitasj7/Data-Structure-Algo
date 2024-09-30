#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int i, int j, vector<int> &nums)
    {
        // Base Case
        if (i > j)
            return 0;

        // logic
        int maxi = INT32_MIN;
        // firstly burst last ballons
        for (int index = i; index <= j; index++)
        {
            int coins = (nums[i - 1] * nums[index] * nums[j + 1]) + helper(i, index - 1, nums) + helper(index + 1, j, nums);

            maxi = max(maxi, coins);
        }

        // return
        return maxi;
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        int ans = helper(1, n, nums);

        return ans;
    }
};

// Memo
class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &dp, vector<int> &nums)
    {
        // Base Case
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        // logic
        int maxi = INT32_MIN;
        // firstly burst last ballons
        for (int index = i; index <= j; index++)
        {
            int coins = (nums[i - 1] * nums[index] * nums[j + 1]) + helper(i, index - 1, dp, nums) + helper(index + 1, j, dp, nums);

            maxi = max(maxi, coins);
        }

        // return
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        int ans = helper(1, n, dp, nums);

        return ans;
    }
};

// Tabulation
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        //    // Base Case already fill with 0
        // if (i > j)
        //     return 0;

        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    continue;
                // logic
                int maxi = INT32_MIN;
                // firstly burst last ballons
                for (int index = i; index <= j; index++)
                {
                    int coins = (nums[i - 1] * nums[index] * nums[j + 1]) + dp[i][index - 1] + dp[index + 1][j];

                    maxi = max(maxi, coins);
                }

                // return
                dp[i][j] = maxi;
            }
        }

        int ans = dp[1][n];

        return ans;
    }
};