#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int i, int j, vector<int> &nums)
    {
        // BASE CASE
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];

        // LOGIC
        // if p1-p2 >= 0 then true
        int takei = nums[i] - helper(i + 1, j, nums);
        int takej = nums[j] - helper(i, j - 1, nums);

        // RETURN
        return max(takei, takej);
    }
    bool predictTheWinner(vector<int> &nums)
    {

        int n = nums.size();

        // find totalSum
        int sum = 0;
        for (auto &it : nums)
        {
            sum += it;
        }
        return helper(0, n - 1, nums) >= 0;
    }
};
// Memo
class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &dp, vector<int> &nums)
    {
        // BASE CASE
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];

        if (dp[i][j] != -1)
            return dp[i][j];
        // LOGIC
        // if p1-p2 >= 0 then true
        int takei = nums[i] - helper(i + 1, j, dp, nums);
        int takej = nums[j] - helper(i, j - 1, dp, nums);

        // RETURN
        return dp[i][j] = max(takei, takej);
    }
    bool predictTheWinner(vector<int> &nums)
    {

        int n = nums.size();

        // find totalSum
        int sum = 0;
        for (auto &it : nums)
        {
            sum += it;
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n - 1, dp, nums) >= 0;
    }
};

class Solution
{
public:
    int helper(int i, int j, vector<int> &nums)
    {
        // BASE CASE
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];

        // LOGIC
        // if p1-p2 >= 0 then true
        int takei = nums[i] + min(helper(i + 2, j, nums), helper(i + 1, j - 1, nums));
        int takej = nums[j] + min(helper(i + 1, j - 1, nums), helper(i, j - 2, nums));

        // RETURN
        return max(takei, takej);
    }
    bool predictTheWinner(vector<int> &nums)
    {

        int n = nums.size();

        // find totalSum
        int sum = 0;
        for (auto &it : nums)
        {
            sum += it;
        }
        int p1 = helper(0, n - 1, nums);

        int p2 = sum - p1;

        return p1 >= p2;
    }
};


// tabulation wrong 
class Solution
{
public:
    bool predictTheWinner(vector<int> &nums)
    {

        int n = nums.size();

        // find totalSum
        int sum = 0;
        for (auto &it : nums)
        {
            sum += it;
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        // BASE CASE
        // if (i > j)
        //     return 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j)
                {
                    dp[i][j] = nums[i];
                    continue;
                }

                // LOGIC
                // if p1-p2 >= 0 then true
                int takei = nums[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int takej = nums[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);

                // RETURN
                dp[i][j] = max(takei, takej);
            }
        }

        int p1 = dp[0][n - 1];

        int p2 = sum - p1;

        return p1 >= p2;
    }
};