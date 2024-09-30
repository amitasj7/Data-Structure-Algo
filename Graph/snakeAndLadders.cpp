#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findRow(int val, int n)
    {

        int row = n - (val - 1) / n - 1;

        return row;
    }

    int findCol(int val, int row, int n)
    {

        int c = (val - 1) % n;

        int col;
        // if dono row and n even hai ya dono odd hai
        if (row % 2 == n % 2)
        {
            col = n - 1 - c;
        }
        else
        {
            col = c;
        }

        return col;
    }
    int snakesAndLadders(vector<vector<int>> &board)
    {

        int n = board.size();

        // take a Queue
        // <no. of cell, steps>
        queue<pair<int, int>> q;

        q.push({1, 0});

        // take a visited vector
        vector<vector<int>> visited(n, vector<int>(n, 0));
        // mark 0th value in bottom left
        visited[n - 1][0] = 1;

        while (!q.empty())
        {
            int size = q.size();

            for (int k = 0; k < size; k++)
            {

                int boxVal = q.front().first;
                int minSteps = q.front().second;
                q.pop();

                if (boxVal == (n * n))
                    return minSteps;

                // fill all 6 condition using dice
                for (int i = 1; i <= 6; i++)
                {

                    int newBoxVal = boxVal + i;

                    if (newBoxVal > (n * n))
                        break;

                    int row = findRow(newBoxVal, n);
                    int col = findCol(newBoxVal, row, n);

                    if (!visited[row][col])
                    {
                        // if snake or ladder exist that box
                        if (board[row][col] != -1)
                        {
                            int finalBoxVal = board[row][col];
                            int finalrow = findRow(finalBoxVal, n);
                            int finalcol = findCol(finalBoxVal, finalrow, n);
                            if (!visited[finalrow][finalcol])
                                q.push({finalBoxVal, minSteps + 1});

                            visited[finalrow][finalcol] = 1;
                        }
                        else
                        {

                            q.push({newBoxVal, minSteps + 1});
                            visited[row][col] = 1;
                        }
                    }
                }
            }
        }

        // not possible to catch goal position
        return -1;
    }
};