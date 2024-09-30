#include <bits/stdc++.h>
using namespace std;

// Tabulation

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        // Base Case
        dp[n + 1][0] = dp[n + 1][1] = 0; // already fill these value

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
                    // change when sell --> current day + 2
                    profit = max((prices[index] + dp[index + 2][1]), (0 + dp[index + 1][0]));
                }

                dp[index][buy] = profit;
            }
        }

        int ans = dp[0][1];

        return ans;
    }
};

//  Space optimization

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();

        vector<int> f2(2, 0);
        vector<int> f1(2, 0);
        vector<int> curr(2, 0);

        // Base Case

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                // Logic
                int profit = 0;
                if (buy)
                {
                    profit = max((-prices[index] + f1[0]), f1[1]);
                }
                else
                {
                    // change when sell --> current day + 2
                    profit = max((prices[index] + f2[1]), (0 + f1[0]));
                }

                curr[buy] = profit;
            }
            f2 = f1;
            f1 = curr;
        }

        int ans = f2[1];

        return ans;
    }
};