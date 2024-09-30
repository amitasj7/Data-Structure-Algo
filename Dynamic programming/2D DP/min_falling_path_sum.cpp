#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &matrix, int m, int n)
    {
        // BASE CASE

        if (j < 0 || j >= n) // if i == 0 and j ==  out of boundary then --
            return INT_MAX;
        if (i == 0)
            return matrix[0][j];

        // LOGIC
        int up = helper(i - 1, j, matrix, m, n);
        int ld = helper(i - 1, j - 1, matrix, m, n);
        int rd = helper(i - 1, j + 1, matrix, m, n);

        // RETURN

        return matrix[i][j] + min({up, ld, rd});
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        int ans = INT_MAX;

        for (int j = 0; j < n; j++)
        {

            ans = min(ans, helper(m - 1, j, matrix, m, n));
        }
        return ans;
    }
};

// 2. Memoization
class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &matrix, int m, int n)
    {
        // BASE CASE

        if (j < 0 || j >= n) // if i == 0 and j ==  out of boundary then --
            return INT_MAX;
        if (i == 0)
            return matrix[0][j];

        // pre - calculated
        if (dp[i][j] != INT_MAX)
            return dp[i][j];
        // LOGIC
        int up = helper(i - 1, j, dp, matrix, m, n);
        int ld = helper(i - 1, j - 1, dp, matrix, m, n);
        int rd = helper(i - 1, j + 1, dp, matrix, m, n);

        // RETURN

        return dp[i][j] = matrix[i][j] + min({up, ld, rd});
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX)); // matrix[i][j] contains negative value also

        for (int j = 0; j < n; j++)
        {

            ans = min(ans, helper(m - 1, j, dp, matrix, m, n));
        }
        return ans;
    }
};

// 3. Tabulation

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX)); // matrix[i][j] contains negative value also

        // BASE CASE

        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i <= m - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // LOGIC
                int up = dp[i - 1][j];

                int ld = INT_MAX;
                if (j >= 1)
                    ld = dp[i - 1][j - 1];

                int rd = INT_MAX;
                if (j <= m - 2)
                    rd = dp[i - 1][j + 1];

                // RETURN

                dp[i][j] = matrix[i][j] + min({up, ld, rd});
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
        {

            ans = min(ans, dp[m - 1][j]);
        }
        return ans;
    }
};

// 4. Space optimization

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> prev(n, INT_MAX); // matrix[i][j] contains negative value also

        // BASE CASE

        for (int j = 0; j < n; j++)
        {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i <= m - 1; i++)
        {
            vector<int> curr(n, INT_MAX);
            for (int j = 0; j < n; j++)
            {

                // LOGIC
                int up = prev[j];

                int ld = INT_MAX;
                if (j >= 1)
                    ld = prev[j - 1];

                int rd = INT_MAX;
                if (j <= m - 2)
                    rd = prev[j + 1];

                // RETURN

                curr[j] = matrix[i][j] + min({up, ld, rd});
            }
            prev = curr;
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
        {

            ans = min(ans, prev[j]);
        }
        return ans;
    }
};