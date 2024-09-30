#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int ans = 0;

        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));

        // fill 1st row
        for (int j = 0; j < col; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        // fill 1st col
        for (int i = 0; i < row; i++)
        {
            dp[i][0] = matrix[i][0];
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                if (matrix[i][j] == '1')
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                }
            }
        }

// find total sum 
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ans += dp[i][j];
            }
        }

        return ans;
    }
};