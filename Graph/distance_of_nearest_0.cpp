#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int totalRow = mat.size();
        int totalCol = mat[0].size();
        // 0th row size and 1st row size is equal or not ?

        // take visited array and ans array
        vector<vector<int>> visited(totalRow, vector<int>(totalCol, 0));
        vector<vector<int>> ans(totalRow, vector<int>(totalCol, 0));

        // take a queue <distance,row,col>
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {
                if (mat[i][j] == 0)
                {
                    // push into queue
                    q.push({0, {i, j}});

                    // mark visited array
                    visited[i][j] = 1;
                }
            }
        }
        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();

            int distance = cell.first;
            int row = cell.second.first;
            int col = cell.second.second;

            // mark distance into ans
            ans[row][col] = distance;

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            // move into four directions
            for (int i = 0; i < 4; i++)
            {

                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if (newRow >= 0 && newRow < totalRow && newCol >= 0 && newCol < totalCol && !visited[newRow][newCol])
                {
                    q.push({distance + 1, {newRow, newCol}});
                    visited[newRow][newCol] = 1;
                }
            }
        }

        return ans;
    }
};