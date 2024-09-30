#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int index, int buy, vector<int> &prices, int n)
    {
        // Base Case
        if (index == n)
        {
            return 0;
        }

        // Logic
        int profit = 0;
        if (buy)
        {
            profit = max((-prices[index] + helper(index + 1, 0, prices, n)), (0 + helper(index + 1, 1, prices, n)));
        }
        else
        {
            profit = max((prices[index] + helper(index + 1, 1, prices, n)), (0 + helper(index + 1, 0, prices, n)));
        }

        // return

        return profit;
    }
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();

        int ans = helper(0, 1, prices, n);

        return ans;
    }
};

// memo

class Solution
{
public:
    int helper(int index, int buy, vector<vector<int>> &dp, vector<int> &prices, int n)
    {
        // Base Case
        if (index == n)
        {
            return 0;
        }

        if (dp[index][buy] != -1)
            return dp[index][buy];

        // Logic
        int profit = 0;
        if (buy)
        {
            profit = max((-prices[index] + helper(index + 1, 0, dp, prices, n)), (0 + helper(index + 1, 1, dp, prices, n)));
        }
        else
        {
            profit = max((prices[index] + helper(index + 1, 1, dp, prices, n)), (0 + helper(index + 1, 0, dp, prices, n)));
        }

        // return

        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        int ans = helper(0, 1, dp, prices, n);

        return ans;
    }
};

// Tabulation

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base Case
        dp[n][0] = dp[n][1] = 0; // already fill these value

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                // Logic
                int profit = 0;
                if (buy)
                {
                    profit = max((-prices[index] + dp[index + 1][0]), dp[index + 1][1]);
                }
                else
                {
                    
                    profit = max((prices[index] + dp[index + 1][1]), (0 + dp[index + 1][0]));
                }

                dp[index][buy] = profit;
            }
        }

        int ans = dp[0][1];

        return ans;
    }
};

// space optimization

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        vector<int> prev(2, 0);

        // Base Case

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                // Logic
                int profit = 0;
                if (buy)
                {
                    profit = max((-prices[index] + prev[0]), prev[1]);
                }
                else
                {
                    profit = max((prices[index] + prev[1]), (0 + prev[0]));
                }

                prev[buy] = profit;
            }
        }

        int ans = prev[1];

        return ans;
    }
};