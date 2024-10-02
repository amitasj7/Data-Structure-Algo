
#include <bits/stdc++.h>
using namespace std;

int maxEle(vector<vector<int>> &mat, int m, int n, int mid)
{

    int index = -1;
    int maxElement = INT_MIN;

    // traverse mid column every element ;
    for (int i = 0; i < m; i++)
    {
        if (maxElement < mat[i][mid])
        {
            // find row value;
            maxElement = mat[i][mid];
            index = i;
        }
    }

    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &mat)
{

    int m = mat.size();
    int n = mat[0].size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // find column's max element's row no.
        int maxEleRow = maxEle(mat, m, n, mid);

        int leftEle = (mid - 1) < 0 ? -1 : mat[maxEleRow][mid - 1];
        int rightEle = (mid + 1) >= n ? -1 : mat[maxEleRow][mid + 1];

        // check only left and right
        if (leftEle < mat[maxEleRow][mid] && rightEle < mat[maxEleRow][mid])
        {
            return {maxEleRow, mid};
        }
        else if (leftEle > mat[maxEleRow][mid])
        {
            // upadate high
            high = mid - 1;
        }
        else
        {
            // update low
            low = mid + 1;
        }
    }

    return {-1, -1};
}