#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int totalRow = heights.size();
        int totalCol = heights[0].size();

        // take a effort matrix
        vector<vector<int>> dist(totalRow, vector<int>(totalCol, INT32_MAX));

        // take a minHeap

        // <Effort,row, col>
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            int effort = pq.top()[0];
            int currRow = pq.top()[1];
            int currCol = pq.top()[2];

            pq.pop();

            if (currRow == totalRow - 1 && currCol == totalCol - 1)
            {
                return effort;
            }

            // traverse all four direction
            for (int i = 0; i < 4; i++)
            {
                int newRow = currRow + delRow[i];
                int newCol = currCol + delCol[i];

                if (newRow >= 0 && newRow < totalRow && newCol >= 0 && newCol < totalCol)
                {

                    int maxEffort = max(abs(heights[newRow][newCol] - heights[currRow][currCol]), effort);

                    if (maxEffort < dist[newRow][newCol])
                    {
                        // update effort matrix
                        dist[newRow][newCol] = maxEffort;

                        // push into queue
                        pq.push({maxEffort, newRow, newCol});
                    }
                }
            }
        }
        return 0;
    }
};