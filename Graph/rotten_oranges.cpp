#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int time = 0;

        int n = grid.size();
        int m = grid[0].size();

        // rottenTime, row, col
        queue<pair<int, pair<int, int>>> q;
        int fresh = 0;

        int rotten = 0;
        vector<vector<int>> check = grid;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] == 2)
                {
                    rotten++;
                    q.push({0, {i, j}});
                }
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, +1, 0, -1};

        int count = 0;

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            count++;

            int rottenTime = node.first;
            time = max(time, rottenTime);

            for (int i = 0; i < 4; i++)
            {
                int newRow = node.second.first + deltaRow[i];
                int newCol = node.second.second + deltaCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && check[newRow][newCol] != 2)
                {
                    q.push({rottenTime + 1, {newRow, newCol}});
                    check[newRow][newCol] = 2;
                }
            }
        }

        if ((fresh + rotten) != count)
        {
            return -1;
        }

        return time;
    }
};