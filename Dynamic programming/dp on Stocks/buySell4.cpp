#include <bits/stdc++.h>
using namespace std;

// recursoin 
// using n*4 dp

class Solution
{
public:
    int helper(int index, int trans, int k, vector<int> &prices, int n)
    {
        // Base Case
        if (index == n || trans == 2 * k)
        {
            return 0;
        }

        // Logic
        int profit = 0;
        int buy = (trans % 2 == 0); // 0 than buy it
        if (buy)
        {
            profit = max((-prices[index] + helper(index + 1, trans + 1, k, prices, n)), (0 + helper(index + 1, trans, k, prices, n)));
        }
        else
        {
            profit = max((prices[index] + helper(index + 1, trans + 1, k, prices, n)), (0 + helper(index + 1, trans, k, prices, n)));
        }

        // return

        return profit;
    }
    int maxProfit(int k, vector<int> &prices)
    {

        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2 * k, 0));

        int ans = helper(0, 0, k, prices, n);

        return ans;
    }
};

// tabulation

// using n*4 dp

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {

        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>((2 * k) + 1, 0));

        // // Base Case
        // Already fill by 0
        // if (index == n || trans == 2 * k)
        // {
        //     return 0;
        // }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int trans = 2 * k - 1; trans >= 0; trans--)
            {
                // Logic
                int profit = 0;
                int buy = (trans % 2 == 0); // 0 than buy it
                if (buy)
                {
                    profit = max((-prices[index] + dp[index + 1][trans + 1]), dp[index + 1][trans]);
                }
                else
                {
                    profit = max((prices[index] + dp[index + 1][trans + 1]), dp[index + 1][trans]);
                }

                // return

                dp[index][trans] = profit;
            }
        }

        int ans = dp[0][0];

        return ans;
    }
};

//  Space optimizaiton
// using n*4 dp

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {

        int n = prices.size();

        vector<int> prev((2 * k) + 1, 0), current((2 * k) + 1, 0);

        // // Base Case
        // Already fill by 0
        // if (index == n || trans == 2 * k)
        // {
        //     return 0;
        // }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int trans = 2 * k - 1; trans >= 0; trans--)
            {
                // Logic
                int profit = 0;
                int buy = (trans % 2 == 0); // 0 than buy it
                if (buy)
                {
                    profit = max((-prices[index] + prev[trans + 1]), prev[trans]);
                }
                else
                {
                    profit = max((prices[index] + prev[trans + 1]), prev[trans]);
                }

                // return

                current[trans] = profit;
            }
            prev = current;
        }

        int ans = prev[0];

        return ans;
    }
};
