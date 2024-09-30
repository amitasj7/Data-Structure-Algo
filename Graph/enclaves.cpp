#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void BFSCall(vector<vector<int>> &grid, int totalRow, int totalCol, vector<vector<int>> &visited, int row, int col)
    {

        // mark in visited
        queue<pair<int, int>> q;

        q.push({row, col});
        visited[row][col] = 1;

        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();

            row = cell.first;
            col = cell.second;

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            // move into four directions
            for (int i = 0; i < 4; i++)
            {

                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if (newRow >= 0 && newRow < totalRow && newCol >= 0 && newCol < totalCol && grid[newRow][newCol] == 1 && !visited[newRow][newCol])
                {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = 1;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int enclaves = 0;

        int totalRow = grid.size();
        int totalCol = grid[0].size();

        vector<vector<int>> visited(totalRow, vector<int>(totalCol, 0));

        for (int i = 0; i < totalCol; i++)
        {
            // first row

            if (grid[0][i] == 1 && !visited[0][i])
            {

                BFSCall(grid, totalRow, totalCol, visited, 0, i);
            }

            if (grid[totalRow - 1][i] == 1 && !visited[totalRow - 1][i])
            {
                BFSCall(grid, totalRow, totalCol, visited, totalRow - 1, i);
            }

            // last row
        }

        for (int i = 1; i < totalRow - 1; i++)
        {

            // first column
            if (grid[i][0] == 1 && !visited[i][0])
            {
                BFSCall(grid, totalRow, totalCol, visited, i, 0);
            }

            // last column
            if (grid[i][totalCol - 1] == 1 && !visited[i][totalCol - 1])
            {
                BFSCall(grid, totalRow, totalCol, visited, i, totalCol - 1);
            }
        }

        // traverse origin grid

        for (int i = 0; i < totalRow; i++)
        {

            for (int j = 0; j < totalCol; j++)
            {

                if (grid[i][j] == 1 && !visited[i][j])
                {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};