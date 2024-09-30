#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(bool &check, int row, int col, vector<vector<int>> &grid1, vector<vector<int>> &grid2, int totalRow, int totalCol)
    {
        // mark visited
        grid2[row][col] = 0;

        if (grid1[row][col] == 0)
        {
            check = false;
        }
        // traverse all four directions
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            // check valid or not
            if (newRow >= 0 && newRow < totalRow && newCol >= 0 &&
                newCol < totalCol && grid2[newRow][newCol] == 1)
            {
                dfs(check, newRow, newCol, grid1, grid2, totalRow, totalCol);
            }
        }
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        // traverse all matrix and find one 1
        int totalRow = grid2.size();
        int totalCol = grid2[0].size();

        int ans = 0;

        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {

                if (grid2[i][j] == 1)

                {
                    bool check = true;
                    // dfs call 1. visited mark all completly island
                    // 2.  check for subisland or not
                    dfs(check, i, j, grid1, grid2, totalRow, totalCol);
                    if (check)
                        ans++;
                }
            }
        }
        return ans;
    }
};