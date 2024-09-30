#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {

        int totalRow = grid.size();
        int totalCol = grid[0].size();

        if (totalRow == 1 && totalCol == 1)
        {
            return 1;
        }
        // take a dist matrix
        vector<vector<int>> dist(totalRow, vector<int>(totalCol, INT32_MAX));

        // take a minHeap
        // <distance,row, col>
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        if (grid[0][0] == 0)
        {
            pq.push({1, 0, 0});
            dist[0][0] = 1;
        }

        while (!pq.empty())
        {
            int distance = pq.top()[0];
            int currRow = pq.top()[1];
            int currCol = pq.top()[2];

            pq.pop();

            int delRow[] = {
                -1,
                -1,
                0,
                1,
                1,
                1,
                0,
                -1};
            int delCol[] = {0, 1, 1, 1, 0, -1, -1, -1};

            for (int i = 0; i < 8; i++)
            {
                int newRow = currRow + delRow[i], newCol = currCol + delCol[i];

                if (newRow >= 0 && newRow < totalRow && newCol >= 0 && newCol < totalCol && grid[newRow][newCol] == 0 && (distance + 1) < dist[newRow][newCol])
                {
                    // update distance
                    dist[newRow][newCol] = distance + 1;

                    // push into queue
                    pq.push({distance + 1, newRow, newCol});

                    if (newRow == totalRow - 1 && newCol == totalCol - 1)
                    {
                        return dist[newRow][newCol];
                    }
                }
            }
        }

        return -1;
    }
};