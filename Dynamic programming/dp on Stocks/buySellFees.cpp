#include <bits/stdc++.h>
using namespace std;

// space optimization single array
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
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
                    profit = max((prices[index] - fee + prev[1]), (0 + prev[0]));
                }

                prev[buy] = profit;
            }
        }

        int ans = prev[1];

        return ans;
    }
};

// space optimization two variable
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {

        int n = prices.size();
        int first = 0, second = 0;

        // Base Case

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                // Logic
                int profit = 0;
                if (buy)
                {
                    profit = max((-prices[index] + first), second);
                    second = profit;
                }
                else
                {
                    profit = max((prices[index] - fee + second), (first));
                    first = profit;
                }
            }
        }

        int ans = second;

        return ans;
    }
};