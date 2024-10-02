#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(vector<vector<int>> &matrix, int ele)
    {

        int count = 0;

        for (int i = 0; i < matrix.size(); i++)
        {
            // take a single row and find smaller and equal ele

            count += upper_bound(matrix[i].begin(), matrix[i].end(), ele) - matrix[i].begin();
        }

        return count;
    }
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // code here

        // find search space area [min(matrix), max(matrix)]

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < R; i++)
        {

            mini = min(mini, matrix[i][0]);
            maxi = max(maxi, matrix[i][C - 1]);
        }

        int low = mini, high = maxi;

        int req = (R * C) / 2;

        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);

            // find smaller and equal element with mid

            int smallerEqual = find(matrix, mid);

            if (smallerEqual <= req)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
};