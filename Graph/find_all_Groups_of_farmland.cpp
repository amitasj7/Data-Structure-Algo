#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<int> &ansHelper, int row, int col,
             vector<vector<int>> &land, int totalRow, int totalCol)
    {

        // mark visited
        land[row][col] = 0;

        // fill row col if greater
        if (ansHelper[2] < row)
        {
            ansHelper[2] = row;
        }
        if (ansHelper[3] < col)
        {
            ansHelper[3] = col;
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
                newCol < totalCol && land[newRow][newCol] == 1)
            {
                dfs(ansHelper, newRow, newCol, land, totalRow, totalCol);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {

        // traverse all matrix and find one 1
        int totalRow = land.size();
        int totalCol = land[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {

                if (land[i][j] == 1)
                {
                    vector<int> ansHelper(4, 0);
                    ansHelper[0] = i;
                    ansHelper[1] = j;
                    ansHelper[2] = i;
                    ansHelper[3] = j;

                    dfs(ansHelper, i, j, land, totalRow, totalCol);
                    ans.push_back(ansHelper);
                }
            }
        }

        return ans;
    }
};