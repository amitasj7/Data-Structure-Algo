#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve_N_Queens(int col, vector<string> &board, int n, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal)
    {

        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        // col 1 me queen kha aaigi
        for (int row = 0; row < n; row++)
        {

            // check valid or not
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
            {

                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // call for next column
                solve_N_Queens(col + 1, board, n, ans, leftRow, lowerDiagonal, upperDiagonal);

                // remove all Queen and aage check kare
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    int totalNQueens(int n)
    {

        string s(n, '.');
        vector<vector<string>> ans;
        vector<string> board(n, s);
        // board name ka vector hai jiska size n hai and pura vector s se fill ho jaigaa mean that 0 index s se, 1 index s se , 2 index s se, and so on.

        // take hashMap to reduce time complexity
        vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
        solve_N_Queens(0, board, n, ans, leftRow, lowerDiagonal, upperDiagonal);

        return ans.size();
    }
};

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {

        int fix_row = row;
        int fix_col = col;

        // row and col value for a queen particular position ke liye fix kiya hai.

        // upper diagonal checking condition
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = fix_row;
        col = fix_col;
        // again row , col value fix ki gai hai

        // mid horizontal line ke liye checking
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = fix_row;
        col = fix_col;

        // 3rd down diagonal ke liye condition checking
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }

    void solve_N_Queens(int col, vector<string> &board, int n, vector<vector<string>> &ans)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n)) // isSafe fucntion work for queen position is valid aur not ?
            {
                board[row][col] = 'Q';
                solve_N_Queens(col + 1, board, n, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        string s(n, '.');
        vector<vector<string>> ans;
        vector<string> board(n, s);
        // board name ka vector hai jiska size n hai and pura vector s se fill ho jaigaa mean that 0 index s se, 1 index s se , 2 index s se, and so on.

        solve_N_Queens(0, board, n, ans);

        return ans;
    }
};
