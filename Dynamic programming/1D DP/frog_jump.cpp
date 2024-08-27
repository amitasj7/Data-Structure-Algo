#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights)
{

    vector<int> dp(n, -1);
    // 1. Base Case
    dp[0] = 0;

    // 2. fill DP vector
    for (int i = 1; i < n; i++)
    {

        int firstJump = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int secondJump = INT_MAX;
        if (i > 1)
            secondJump = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(firstJump, secondJump);
    }

    // 3. return last value;
    return dp[n - 1];
}

int minimizeCost(int n, int k, vector<int> &height)
{
    // Write your code here.

    vector<int> cost(n, -1);

    cost[0] = 0;

    int minCost = INT_MAX;

    for (int i = 1; i < n; i++)
    {

        // for loop for k-steps back se jump krne liye
        for (int j = 1; j <= k; j++)
        {
            int currentcost;
            if (i - j >= 0)
                currentcost = cost[i - j] + abs(height[i] - height[j]);

            minCost = min(minCost, currentcost);
        }

        cost[i] = minCost;
    }

    return cost[n - 1];
}