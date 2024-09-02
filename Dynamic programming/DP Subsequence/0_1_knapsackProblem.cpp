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
            if (weight[0] <= maxWeight)
                return value[0];

            else
            {
                return 0;
            }
        }

        // logic

        int notPick = 0 + helper(index - 1, maxWeight, weight, value);

        int pick = INT16_MIN;

        if (weight[index] <= maxWeight)
        {
            pick = value[index] + helper(index - 1, maxWeight - weight[index], weight, value);
        }

        // return
        return max(notPick, pick);
    }
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        // Write your code here

        int ans = helper(n - 1, maxWeight, weight, value);
        return ans;
    }
};

// 2. memorization
class Solution
{
public:
    int helper(int index, int maxWeight, vector<vector<int>> dp, vector<int> weight, vector<int> value)
    {
        // Base Case

        if (index == 0)
        {
            if (weight[0] <= maxWeight)
                return value[0];

            else
            {
                return 0;
            }
        }
        if (dp[index][maxWeight] != -1)
            return dp[index][maxWeight];

        // logic

        int notPick = 0 + helper(index - 1, maxWeight, dp, weight, value);

        int pick = INT16_MIN;

        if (weight[index] <= maxWeight)
        {
            pick = value[index] + helper(index - 1, maxWeight - weight[index], dp, weight, value);
        }

        // return
        return dp[index][maxWeight] = max(notPick, pick);
    }
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        // Write your code here
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
        int ans = helper(n - 1, maxWeight, dp, weight, value);
        return ans;
    }
};

// 3. Tabulation
class Solution
{
public:
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        // Write your code here
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

        // Base Case
        for (int i = weight[0]; i <= maxWeight; i++)
        {
            dp[0][i] = value[0];
        }

        for (int index = 1; index < n; index++)
        {
            for (int j = 0; j <= maxWeight; j++)
            {
                // logic

                int notPick = 0 + dp[index - 1][j];

                int pick = INT16_MIN;

                if (weight[index] <= j)
                {
                    pick = value[index] + dp[index - 1][j - weight[index]];
                }

                dp[index][j] = max(notPick, pick);
            }
        }

        int ans = dp[n - 1][maxWeight];
        return ans;
    }
};

// 4. Space Optimization
class Solution
{
public:
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        // Write your code here

        vector<int> prev(maxWeight + 1, 0), current(maxWeight + 1, 0);
        // Base Case
        for (int i = weight[0]; i <= maxWeight; i++)
        {
            prev[i] = value[0];
        }

        for (int index = 1; index < n; index++)
        {
            for (int j = 0; j <= maxWeight; j++)
            {
                // logic

                int notPick = 0 + prev[j];

                int pick = INT16_MIN;

                if (weight[index] <= j)
                {
                    pick = value[index] + prev[j - weight[index]];
                }

                current[j] = max(notPick, pick);
            }
            prev = current;
        }

        int ans = prev[maxWeight];
        return ans;
    }
};

// 5. Single Array Space Optimization

class Solution
{
public:
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        // Write your code here

        vector<int> prev(maxWeight + 1, 0);
        // Base Case
        for (int i = weight[0]; i <= maxWeight; i++)
        {
            prev[i] = value[0];
        }

        for (int index = 1; index < n; index++)
        {
            // reverse loop
            // current -- > prev
            for (int j = maxWeight; j >= 0; j--)
            {
                // logic

                int notPick = 0 + prev[j];

                int pick = INT16_MIN;

                if (weight[index] <= j)
                {
                    pick = value[index] + prev[j - weight[index]];
                }

                prev[j] = max(notPick, pick);
            }
        }

        int ans = prev[maxWeight];
        return ans;
    }
};