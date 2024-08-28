#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
class Solution
{
public:
    int helper(int i, int j1, int j2, vector<vector<int>> &grid, int m, int n)
    {

        // BASE CASE

        // 1. out of Boundary
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
        {
            return INT_MIN;
        }
        // 2. at last row
        if (i == m - 1)
        {

            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        // LOGIC

        int maxi = INT_MIN;

        // {-1,0,+1} dono bande ese hi change karege so 9 direction aaigi
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                int value = 0;

                if (j1 == j2)
                    value = grid[i][j1]; // only ek banda hi chocolate le paiga
                else
                    value = grid[i][j1] + grid[i][j2]; // dono bande hi chocolate le paige

                value += helper(i + 1, j1 + dj1, j2 + dj2, grid, m, n); // aage ki calculate kar ke le aaiga

                // update maxi
                maxi = max(maxi, value);
            }
        }

        // RETURN

        return maxi;
    }
    int solve(int n, int m, vector<vector<int>> &grid)
    {

        swap(n, m);

        return helper(0, 0, n - 1, grid, m, n);
    }
};

// 2. Memoization
class Solution
{
public:
    int helper(int i, int j1, int j2, vector<vector<vector<int>>> &dp, vector<vector<int>> &grid, int m, int n)
    {

        // BASE CASE

        // 1. out of Boundary
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
        {
            return INT_MIN;
        }
        // 2. at last row
        if (i == m - 1)
        {

            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        // pre - calculated
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        // LOGIC

        int maxi = INT_MIN;

        // {-1,0,+1} dono bande ese hi change karege so 9 direction aaigi
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                int value = 0;

                if (j1 == j2)
                    value = grid[i][j1]; // only ek banda hi chocolate le paiga
                else
                    value = grid[i][j1] + grid[i][j2]; // dono bande hi chocolate le paige

                value += helper(i + 1, j1 + dj1, j2 + dj2, dp, grid, m, n); // aage ki calculate kar ke le aaiga

                // update maxi
                maxi = max(maxi, value);
            }
        }

        // RETURN

        return dp[i][j1][j2] = maxi;
    }
    int solve(int n, int m, vector<vector<int>> &grid)
    {

        swap(n, m);

        // take a 3D - DP
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        return helper(0, 0, n - 1, dp, grid, m, n);
    }
};

// 3. Tabulation
class Solution
{
public:
    int solve(int n, int m, vector<vector<int>> &grid)
    {

        swap(n, m);

        // take a 3D - DP
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

        // BASE CASE

        // 2. for last row
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {

                if (j1 == j2)
                    dp[m - 1][j1][j2] = grid[m - 1][j1];
                else
                    dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        for (int i = m - 2; i >= 0; i--)
        {

            for (int j1 = 0; j1 < n; j1++)
            {
                for (int j2 = 0; j2 < n; j2++)
                {

                    // LOGIC

                    int maxi = INT_MIN;

                    // {-1,0,+1} dono bande ese hi change karege so 9 direction aaigi
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int value = INT_MIN;

                            if (j1 == j2)
                                value = grid[i][j1]; // only ek banda hi chocolate le paiga
                            else
                                value = grid[i][j1] + grid[i][j2]; // dono bande hi chocolate le paige

                            if (j1 + dj1 >= 0 && j1 + dj1 < n && j2 + dj2 >= 0 && j2 + dj2 < n)
                                value += dp[i + 1][j1 + dj1][j2 + dj2]; // aage ki calculate kar ke le aaiga

                            else
                                value += INT_MIN;
                            // update maxi
                            maxi = max(maxi, value);
                        }
                    }

                    // RETURN

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        int ans = dp[0][0][n - 1]; // ans hamesha fixed point par milega (0,0) and (0,n-1)  ==> (0,0,n-1)

        return ans;
    }
};

// 4. Space Optimization
class Solution
{
public:
    int solve(int n, int m, vector<vector<int>> &grid)
    {

        swap(n, m);

        // take a 3D - DP
        vector<vector<int>> prev(n, vector<int>(n, 0));

        // BASE CASE

        // 2. for last row
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {

                if (j1 == j2)
                    prev[j1][j2] = grid[m - 1][j1];
                else
                    prev[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        for (int i = m - 2; i >= 0; i--)
        {
            vector<vector<int>> curr(n, vector<int>(n, 0));

            for (int j1 = 0; j1 < n; j1++)
            {
                for (int j2 = 0; j2 < n; j2++)
                {

                    // LOGIC

                    int maxi = INT_MIN;

                    // {-1,0,+1} dono bande ese hi change karege so 9 direction aaigi
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int value = INT_MIN;

                            if (j1 == j2)
                                value = grid[i][j1]; // only ek banda hi chocolate le paiga
                            else
                                value = grid[i][j1] + grid[i][j2]; // dono bande hi chocolate le paige

                            if (j1 + dj1 >= 0 && j1 + dj1 < n && j2 + dj2 >= 0 && j2 + dj2 < n)
                                value += prev[j1 + dj1][j2 + dj2]; // aage ki calculate kar ke le aaiga

                            else
                                value += INT_MIN;
                            // update maxi
                            maxi = max(maxi, value);
                        }
                    }

                    // RETURN

                    curr[j1][j2] = maxi;
                }
            }
            prev = curr;
        }

        int ans = prev[0][n - 1]; // ans hamesha fixed point par milega (0,0) and (0,n-1)  ==> (0,0,n-1)

        return ans;
    }
};