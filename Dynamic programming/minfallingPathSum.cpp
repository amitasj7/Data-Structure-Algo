#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(vector<vector<int>> &grid, int row, int col, int totalRow, int totalCol)
    {

        // BASE CASE
        if (row == totalRow || col == totalCol)
            return 0;

        // LOGIC

        int minSum = INT_MAX;
        for (int i = 0; i < totalCol; i++)
        {
            if (i == col)
                continue;

            minSum = min(minSum, helper(grid, row + 1, i, totalRow, totalCol));
        }

        // update minisum
        if (minSum >= INT_MAX)

            minSum = grid[row][col];
        else
            minSum += grid[row][col];

        // RETURN
        return minSum;
    }
    int minFallingPathSum(vector<vector<int>> &grid)
    {

        int totalRow = grid.size();
        int totalCol = grid[0].size();
        int ans = INT_MAX;

        // traverse first Row's All Elements and find minimum Sum
        for (int i = 0; i < totalCol; i++)
        {
            // row = 0 and col = i
            ans = min(ans, helper(grid, 0, i, totalRow, totalCol));
        }

        return ans;
    }
};

// Memorization
class Solution
{
public:
    int helper(vector<vector<int>> &grid, vector<vector<int>> &dp, int row, int col, int totalRow, int totalCol)
    {

        // BASE CASE
        if (row == totalRow || col == totalCol)
            return 0;

        if (dp[row][col] != INT_MAX)
            return dp[row][col];
        // LOGIC

        int minSum = INT_MAX;
        for (int i = 0; i < totalCol; i++)
        {
            if (i == col)
                continue;

            minSum = min(minSum, helper(grid, dp, row + 1, i, totalRow, totalCol));
        }

        // update minisum
        if (minSum >= INT_MAX)

            minSum = grid[row][col];
        else
            minSum += grid[row][col];

        // RETURN
        return dp[row][col] = minSum;
    }
    int minFallingPathSum(vector<vector<int>> &grid)
    {

        int totalRow = grid.size();
        int totalCol = grid[0].size();
        int ans = INT_MAX;

        vector<vector<int>> dp(totalRow, vector<int>(totalCol, INT_MAX));

        // traverse first Row's All Elements and find minimum Sum
        for (int i = 0; i < totalCol; i++)
        {
            // row = 0 and col = i
            ans = min(ans, helper(grid, dp, 0, i, totalRow, totalCol));
        }

        return ans;
    }
};

