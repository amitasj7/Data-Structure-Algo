#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size();    // total row
        int n = points[0].size(); // total col

        vector<long long> prev(n, 0);

        // fill first row --> prev
        for (int col = 0; col < n; col++)
        {
            prev[col] = points[0][col];
        }

        for (int row = 1; row < m; row++)
        {

            // take left and right
            vector<long long> left(n, 0), right(n, 0);

            left[0] = prev[0], right[n - 1] = prev[n - 1];

            for (int col = 1; col < n; col++)
            {

                left[col] = max(prev[col], left[col - 1] - 1);
                right[n - 1 - col] = max(prev[n - 1 - col], right[n - 1 - col + 1] - 1);
            }

            // fill prev values
            for (int col = 0; col < n; col++)
            {
                prev[col] = points[row][col] + max(left[col], right[col]);
            }
        }
        int index = max_element(prev.begin(), prev.end()) - prev.begin();

        

        long long ans = prev[index];


// *max_element(prev.begin(), prev.end())     // it directly provide prev[index] value 
        return ans;
    }
};