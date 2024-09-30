#include <bits/stdc++.h>
using namespace std;

// using n*4 dp

class Solution
{
public:
    int helper(int index, int trans, vector<int> &prices, int n)
    {
        // Base Case
        if (index == n || trans == 4)
        {
            return 0;
        }

        // Logic
        int profit = 0;
        int buy = (trans % 2 == 0); // 0 than buy it
        if (buy)
        {
            profit = max((-prices[index] + helper(index + 1, trans + 1, prices, n)), (0 + helper(index + 1, trans, prices, n)));
        }
        else
        {
            profit = max((prices[index] + helper(index + 1, trans + 1, prices, n)), (0 + helper(index + 1, trans, prices, n)));
        }

        // return

        return profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        int ans = helper(0, 0, prices, n);

        return ans;
    }
};

// using 3rd Dp 
class Solution
{
public:
    int helper(int index, int buy, int cap, vector<int> &prices, int n)
    {
        // Base Case
        if (index == n || cap == 0)
        {
            return 0;
        }

        // Logic
        int profit = 0;
        if (buy)
        {
            profit = max((-prices[index] + helper(index + 1, 0, cap, prices, n)), (0 + helper(index + 1, 1, cap, prices, n)));
        }
        else
        {
            profit = max((prices[index] + helper(index + 1, 1, cap - 1, prices, n)), (0 + helper(index + 1, 0, cap, prices, n)));
        }

        // return

        return profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        int ans = helper(0, 1, 2, prices, n);

        return ans;
    }
};

// try it with memorization

// Tabulation

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Base Case
        // index == n
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 0; cap < 3; cap++)
            {
                dp[n][buy][cap] = 0;
            }
        }

        // capcity = 0
        for (int index = 0; index <= n; index++)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                dp[index][buy][0] = 0;
            }
        }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    // Logic
                    int profit = 0;
                    if (buy)
                    {
                        profit = max((-prices[index] + dp[index + 1][0][cap]), dp[index + 1][1][cap]);
                    }
                    else
                    {
                        profit = max((prices[index] + dp[index + 1][1][cap - 1]), (0 + dp[index + 1][0][cap]));
                    }

                    dp[index][buy][cap] = profit;
                }
            }
        }

        int ans = dp[0][1][2];

        return ans;
    }
};

// try it with space optimization
