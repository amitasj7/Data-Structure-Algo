#include <bits/stdc++.h>
using namespace std;


// check all pairs using Recursion ---
class Solution
{
public:
    int helper(int index, int amount, vector<int> &coins)
    {
        // Base Case
        if (index == 0)
        {
            if (amount % coins[index] == 0)
                return amount / coins[index];
            else
            {
                return INT16_MAX;
            }
        }

        int not_take = 0 + helper(index - 1, amount, coins);

        int take = INT16_MAX;
        if (coins[index] <= amount)
        {
            take = 1 + (helper(index, amount - coins[index], coins));
        }

        return (min(not_take, take));
    }

    int coinChange(vector<int> &coins, int amount)
    {

        int ans = 0;

        int n = coins.size();
        ans = helper(n - 1, amount, coins);
        if (ans >= INT16_MAX)
            return -1;
        return ans;
    }
};

// memorization
class Solution
{
public:
    int helper(int index, int amount, vector<int> &coins, vector<vector<int>> dp)
    {
        // Base Case
        if (index == 0)
        {
            if (amount % coins[index] == 0)
                return amount / coins[index];
            else
            {
                return INT16_MAX;
            }
        }

        if (dp[index][amount] != -1)
            return dp[index][amount];

        int not_take = 0 + helper(index - 1, amount, coins, dp);

        int take = INT16_MAX;
        if (coins[index] <= amount)
        {
            take = 1 + (helper(index, amount - coins[index], coins, dp));
        }

        return dp[index][amount] = (min(not_take, take));
    }

    int coinChange(vector<int> &coins, int amount)
    {

        int ans = 0;

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        ans = helper(n - 1, amount, coins, dp);
        if (ans >= INT16_MAX)
            return -1;
        return ans;
    }
};

// Tabulation method
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        int ans = 0;

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // fill 0th row  of dp
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
            {
                dp[0][i] = INT16_MAX;
            }
        }

        for (int index = 1; index < n; index++)
        {
            for (int j = 0; j <= amount; j++)
            {

                int not_take = 0 + dp[index - 1][j];

                int take = INT16_MAX;
                if (coins[index] <= j)
                {
                    take = 1 + dp[index][j - coins[index]];
                }

                dp[index][j] = min(not_take, take);
            }
        }

        ans = dp[n - 1][amount];
        if (ans >= INT16_MAX)
            return -1;
        return ans;
    }
};

// Space Sort method ---

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        int ans = 0;

        int n = coins.size();

        vector<int> prev(amount + 1, 0), current(amount + 1, 0);

        // fill 0th row  of dp
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
            {
                prev[i] = INT16_MAX;
            }
        }

        for (int index = 1; index < n; index++)
        {
            for (int j = 0; j <= amount; j++)
            {

                int not_take = 0 + prev[j];

                int take = INT16_MAX;
                if (coins[index] <= j)
                {
                    take = 1 + current[j - coins[index]];
                }

                current[j] = min(not_take, take);
            }
            prev = current;
        }

        ans = prev[amount];
        if (ans >= INT16_MAX)
            return -1;
        return ans;
    }
};