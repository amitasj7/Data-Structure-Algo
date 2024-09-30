#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // dfs ka kaam hai visited matrix ko fill krna

    void dfs(vector<vector<char>> &board, vector<vector<int>> &visited, int row, int col)
    {

        int totalRow = board.size();
        int totalCol = board[0].size();
        // mark it visited
        visited[row][col] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // move into four directions
        for (int i = 0; i < 4; i++)
        {

            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (newRow >= 0 && newRow < totalRow && newCol >= 0 && newCol < totalCol && board[newRow][newCol] == 'O' && !visited[newRow][newCol])
            {
                dfs(board, visited, newRow, newCol);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {

        int totalRow = board.size();
        int totalCol = board[0].size();

        vector<vector<int>> visited(totalRow, vector<int>(totalCol, 0));

        for (int i = 0; i < totalCol; i++)
        {
            // visit firstRow

            if (board[0][i] == 'O' && !visited[0][i])
            {
                dfs(board, visited, 0, i);
            }

            // visit lastRow
            if (board[totalRow - 1][i] == 'O' && !visited[totalRow - 1][i])
            {

                dfs(board, visited, totalRow - 1, i);
            }
        }

        for (int i = 0; i < totalRow; i++)
        {
            // visit firstCol
            if (board[i][0] == 'O' && !visited[i][0])
            {

                dfs(board, visited, i, 0);
            }

            // visit lastCol
            if (board[i][totalCol - 1] == 'O' && !visited[i][totalCol - 1])
            {

                dfs(board, visited, i, totalCol - 1);
            }
        }

        // traverse original board
        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {
                if (board[i][j] == 'O' && !visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};