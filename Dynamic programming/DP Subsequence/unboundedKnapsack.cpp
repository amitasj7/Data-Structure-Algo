#include <bits/stdc++.h>
using namespace std;


// 1. Recursion
class Solution
{
public:
    int helper(int index, int maxWeight, vector<int> weight, vector<int> value)
    {
        // Base Case

        if (index == 0)
        {
            return (int)(maxWeight / weight[0]) * value[0];
        }

        // logic

        int notPick = 0 + helper(index - 1, maxWeight, weight, value);

        int pick = INT16_MIN;

        if (weight[index] <= maxWeight)
        {
            pick = value[index] + helper(index, maxWeight - weight[index], weight, value);
        }

        // return
        return max(notPick, pick);
    }
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        
        int ans = helper(n - 1, w, weight, profit);
        return ans;
    }
};

// 3. Tabulation

class Solution
{
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        // Write Your Code Here.
        vector<vector<int>> dp(n, vector<int>(w + 1, 0));

        // Base Case
        for (int i = weight[0]; i <= w; i++)
        {
            dp[0][i] = (int)(i / weight[0]) * profit[0];
        }

        for (int index = 1; index < n; index++)
        {
            for (int j = 0; j <= w; j++)
            {

                int notPick = 0 + dp[index - 1][j];

                int pick = INT16_MIN;

                if (weight[index] <= j)
                {
                    pick = profit[index] + dp[index][j - weight[index]];
                }

                // return
                dp[index][j] = max(notPick, pick);
            }
        }
        int ans = dp[n - 1][w];

        return ans;
    }
};

// 4. Space Optimization

class Solution
{
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        // Write Your Code Here.

        vector<int> prev(w + 1, 0), current(w + 1, 0);

        // Base Case
        for (int i = weight[0]; i <= w; i++)
        {
            prev[i] = (int)(i / weight[0]) * profit[0];
        }

        for (int index = 1; index < n; index++)
        {
            for (int j = 0; j <= w; j++)
            {

                int notPick = 0 + prev[j];

                int pick = INT16_MIN;

                if (weight[index] <= j)
                {
                    pick = profit[index] + current[j - weight[index]];
                }

                // return
                current[j] = max(notPick, pick);
            }
            prev = current;
        }
        int ans = prev[w];

        return ans;
    }
};

// 5. Single Array Space Optimization

class Solution
{
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        // Write Your Code Here.

        vector<int> prev(w + 1, 0);
        // Base Case
        for (int i = weight[0]; i <= w; i++)
        {
            prev[i] = (int)(i / weight[0]) * profit[0];
        }

        for (int index = 1; index < n; index++)
        {
            for (int j = 0; j <= w; j++)
            {

                int notPick = 0 + prev[j];

                int pick = INT16_MIN;

                if (weight[index] <= j)
                {
                    pick = profit[index] + prev[j - weight[index]];
                }

                // return
                prev[j] = max(notPick, pick);
            }
        }
        int ans = prev[w];

        return ans;
    }
};