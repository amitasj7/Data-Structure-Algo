#include <bits/stdc++.h>
using namespace std;

// using Tabulation
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        // dp[0][0] = 1;

        // fill dp grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if (i == 0 && j == 0)
                    dp[0][0] = 1;
                else
                {
                    int left = 0, up = 0;
                    if (j >= 1)
                        left = dp[i][j - 1];
                    if (i >= 1)
                        up = dp[i - 1][j];

                    dp[i][j] = left + up;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

// sapce optimization
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> pre(n, 0);

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // dp[0][0] = 1;

        // fill dp grid
        int mod1 = int(2 * pow(10, 9));
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {

                if (obstacleGrid[i][j] == 1)
                {
                    temp[j] = 0;
                }
                else if (i == 0 && j == 0)
                    temp[j] = 1;
                else
                {
                    int up = 0;
                    int left = 0;
                    if (j >= 1)
                        left = temp[j - 1];
                    if (i >= 1)
                        up = pre[j];

                    temp[i] = (up + left) % mod1;
                }
            }
            pre = temp;
        }

        return pre[n - 1];
    }
};
