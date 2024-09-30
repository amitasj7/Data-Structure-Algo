#include <bits/stdc++.h>
using namespace std;

/*
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
 */
class Solution
{
public:
    int helper(int i, int j, vector<int> &cuts)
    {
        // Base Case
        if (i > j)
        {
            return 0;
        }

        // Logic
        int mini = INT32_MAX;

        for (int index = i; index <= j; index++)
        {
            int cost = (cuts[j + 1] - cuts[i - 1]) + helper(i, index - 1, cuts) + helper(index + 1, j, cuts);

            mini = min(mini, cost);
        }

        // return
        return mini;
    }
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        int lastindex = cuts.size() - 2;

        int ans = helper(1, lastindex, cuts);
        return ans;
    }
};

// memo
class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &dp, vector<int> &cuts)
    {
        // Base Case
        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        // Logic
        int mini = INT32_MAX;

        for (int index = i; index <= j; index++)
        {
            int cost = (cuts[j + 1] - cuts[i - 1]) + helper(i, index - 1, dp, cuts) + helper(index + 1, j, dp, cuts);

            mini = min(mini, cost);
        }

        // return
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));

        int ans = helper(1, c, dp, cuts);
        return ans;
    }
};

// Tabulation
class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        // Base Case Already filll with 0
        // if (i > j)
        // {
        //     return 0;
        // }

        for (int i = c; i >= 1; i--)
        {
            for (int j = 1; j <= c; j++)
            {
                if (i > j)
                    continue;

                // Logic
                int mini = INT32_MAX;

                for (int index = i; index <= j; index++)
                {
                    int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][index - 1] + dp[index + 1][j];

                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }
        int ans = dp[1][c];
        return ans;
    }
};