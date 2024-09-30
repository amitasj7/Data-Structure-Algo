#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &triangle, int n)
    {

        // BASE CASE
        if (i == n - 1)
            return triangle[n - 1][j];

        // LOGIC

        int down = triangle[i][j] + helper(i + 1, j, triangle, n);
        int dia = triangle[i][j] + helper(i + 1, j + 1, triangle, n);

        // RETURN

        return min(down, dia);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {

        int n = triangle.size();

        return helper(0, 0, triangle, n);
    }
};

// 2. Memoization
class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &triangle, int n)
    {

        // BASE CASE
        if (i == n - 1)
            return triangle[n - 1][j];

        // pre -calculate
        if (dp[i][j] != INT_MAX)
            return dp[i][j];
        // LOGIC

        int down = triangle[i][j] + helper(i + 1, j, dp, triangle, n);
        int dia = triangle[i][j] + helper(i + 1, j + 1, dp, triangle, n);

        // RETURN

        return dp[i][j] = min(down, dia);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); // triangle grid contains negative value also

        return helper(0, 0, dp, triangle, n);
    }
};

// 3. Tabulation

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); // triangle grid contains negative value also

        // BASE CASE
        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {

            for (int j = 0; j <= i; j++)
            {

                // LOGIC

                int down = triangle[i][j] + dp[i + 1][j];
                int dia = triangle[i][j] + dp[i + 1][j + 1];

                // RETURN

                dp[i][j] = min(down, dia);
            }
        }

        int ans = dp[0][0];

        return ans;
    }
};

// 4. Space optimization

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {

        int n = triangle.size();

        vector<int> prev(n, INT_MAX); // triangle grid contains negative value also

        // BASE CASE
        for (int j = 0; j < n; j++)
        {
            prev[j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            vector<int>curr(n,INT_MAX); 

            for (int j = 0; j <= i; j++)
            {

                // LOGIC

                int down = triangle[i][j] + prev[j];
                int dia = triangle[i][j] + prev[j + 1];

                // RETURN

                curr[j] = min(down, dia);
            }

            prev = curr; 
        }

        int ans = prev[0];

        return ans;
    }
};