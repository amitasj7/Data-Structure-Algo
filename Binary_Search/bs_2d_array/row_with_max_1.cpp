#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.

    // n = row
    // m = column ;

    int max_one = 0;
    int row_no = -1;
    for (int i = 0; i < n; i++)
    {
        int ones_rowwise = 0;

        auto it = lower_bound(matrix[i].begin(), matrix[i].end(), 1);
        int lower_bound_index = it - matrix[i].begin();
        
        ones_rowwise = m - lower_bound_index;
        ;
        if (max_one < ones_rowwise)
        {
            // update max_one
            max_one = ones_rowwise;
            row_no = i;
        }
    }

    return row_no;
}
int main()
{

    return 0;
}