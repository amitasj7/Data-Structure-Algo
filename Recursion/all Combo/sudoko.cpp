#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(int row, int col, vector<vector<char>> &board, char val)
    {

        // 9 cell of Row and 9 cell of column and 9 cell of box
        for (int i = 0; i < 9; i++)
        {

            if (board[i][col] == val)
            {
                return false;
            }
            if (board[row][i] == val)
            {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            {
                return false;
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // traverse whole matrix
        int totalRow = board.size();
        int totalCol = board[0].size();

        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {

                // fill by dot

                char val = board[i][j];
                if (val != '.')
                {

                    board[i][j] = '.';

                    if (isValid(i, j, board, val))
                    {
                        board[i][j] = val;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};