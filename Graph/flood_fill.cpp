#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &image, int newColor, int n, int m, vector<vector<int>> &ans, int deltaRow[], int deltaCol[], int initialColor)
{

    // fill new color given cell
    ans[row][col] = newColor;

    for (int i = 0; i < 4; i++)
    {
        int newRow = row + deltaRow[i];
        int newCol = col + deltaCol[i];

        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] == initialColor && ans[newRow][newCol] != newColor)
        {
            dfs(newRow, newCol, image, newColor, n, m, ans, deltaRow, deltaCol, initialColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{

    vector<vector<int>> ans = image; // copy image matrix to ans image
    int initialColor = image[sr][sc];

    int deltaRow[] = {-1, 0, 1, 0};
    int deltaCol[] = {0, 1, 0, -1};

    int n = image.size();
    int m = image[0].size();
    dfs(sr, sc, image, color, n, m, ans, deltaRow, deltaCol, initialColor);

    return ans;
}