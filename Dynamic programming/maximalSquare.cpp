#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSquare(vector<vector<char>> &matrix, int row, int col, int totalRow, int totalCol)
    {
        if (row == totalRow || col == totalCol)
            return 0;

        if (matrix[row][col] == '0')
            return 0;

        // calculate all three directions
        int right = findSquare(matrix, row, col + 1, totalRow, totalCol);
        int diagonal = findSquare(matrix, row + 1, col + 1, totalRow, totalCol);
        int down = findSquare(matrix, row + 1, col, totalRow, totalCol);

        return 1 + min(right, min(down, diagonal));
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {

        // find every cell max square
        int totalRow = matrix.size();
        int totalCol = matrix[0].size();

        int ans = 0;
        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {
                int maxSquare = findSquare(matrix, i, j, totalRow, totalCol);

                ans = max(ans, maxSquare);
            }
        }

        return ans * ans;
    }
};

// tabulation

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {

        // find every cell max square
        int totalRow = matrix.size();
        int totalCol = matrix[0].size();

        int ans = 0;

        vector<vector<int>> dp(totalRow, vector<int>(totalCol, 0));

        for (int i = totalRow - 1; i >= 0; i--)
        {
            for (int j = totalCol - 1; j >= 0; j--)
            {

                if (matrix[i][j] == '0')
                {
                    dp[i][j] = 0; // already fill
                    continue;
                }

                // update value
                int right = (j + 1 < totalCol) ? dp[i][j + 1] : 0;
                int diagonal = (j + 1 < totalCol && i + 1 < totalRow) ? dp[i + 1][j + 1] : 0;
                int down = (i + 1 < totalRow) ? dp[i + 1][j] : 0;

                dp[i][j] = 1 + min(right, min(diagonal, down));

                ans = max(ans, dp[i][j]);
            }
        }

        return ans*ans;
    }
};