#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &grid)
    {

        // BASE CASE

        if (i == 0 && j == 0)
            return grid[0][0];

        if (i < 0 || j < 0)
            return INT_MAX;

        // LOGIC

        int up = helper(i - 1, j, grid);
        int left = helper(i, j - 1, grid);

        // RETURN
        return grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        return helper(m - 1, n - 1, grid);
    }
};

// 2. memorization
class Solution
{
public:
    int minPathSumHelper(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
    {

        // BASE CASE

        if (i == 0 && j == 0)
            return grid[0][0];

        if (i < 0 || j < 0)
            return INT_MAX;

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int up = minPathSumHelper(grid, dp, i - 1, j);
        int left = minPathSumHelper(grid, dp, i, j - 1);

        return dp[i][j] = min(up, left) + grid[i][j];
    }
    int minPathSum(vector<vector<int>> &grid)
    {

        int totalRow = grid.size();
        int totalCol = grid[0].size();

        vector<vector<int>> dp(totalRow, vector<int>(totalCol, -1));

        return minPathSumHelper(grid, dp, totalRow - 1, totalCol - 1);
    }
};

// 3. Tabulation
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {

        int totalRow = grid.size();
        int totalCol = grid[0].size();

        vector<vector<int>> dp(totalRow, vector<int>(totalCol, -1));

        // BASE CASE

        // if (i == 0 && j == 0)
        //     return grid[0][0];

        // if (i < 0 || j < 0)
        //     return INT_MAX;

        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {

                // Base case handle at this point
                if (i == 0 && j == 0)
                {
                    dp[0][0] = grid[0][0];
                }

                int up = INT_MAX;
                if (i >= 1)
                    up = dp[i - 1][j];

                int left = INT_MAX;
                if (j >= 1)
                    left = dp[i][j - 1];

                if (left != INT_MAX || up != INT_MAX)
                    dp[i][j] = grid[i][j] + min(left, up);
            }
        }

        int ans = dp[totalRow - 1][totalCol - 1];

        return ans;
    }
};

// 4. Space optimization
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {

        int totalRow = grid.size();
        int totalCol = grid[0].size();

        vector<int> prev(totalCol, 0);

        // BASE CASE

        // if (i == 0 && j == 0)
        //     return grid[0][0];

        // if (i < 0 || j < 0)
        //     return INT_MAX;

        for (int i = 0; i < totalRow; i++)
        {
            vector<int> curr(totalCol, 0);

            for (int j = 0; j < totalCol; j++)
            {

                // Base case handle at this point
                if (i == 0 && j == 0)
                {
                    curr[0] = grid[0][0];
                }

                int up = INT_MAX;
                if (i >= 1)
                    up = prev[j];

                int left = INT_MAX;
                if (j >= 1)
                    left = curr[j - 1];

                if (left != INT_MAX || up != INT_MAX)
                    curr[j] = grid[i][j] + min(left, up);
            }

            prev = curr;
        }

        int ans = prev[totalCol - 1];

        return ans;
    }
};