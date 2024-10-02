#include <bits/stdc++.h>
using namespace std;


// whole matrix is sort 
bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0;
    int high = (m * n) - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int row = mid / n;
        int column = mid % n;
        if (matrix[row][column] == target)
        {
            return true;
        }
        else if (matrix[row][column] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}
// every indiviual row is sort and every indiviual column is sort
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    // cout << "m: " << m << endl;
    // cout << "n: " << n << endl;

    int Row = 0;
    int Column = n - 1;

    // row maximum m-1 tak hi jaa skta hai
    // column >=0 tak jaiga na ki >0;
    while (Row < m && Column >= 0)
    {
        //    cout<<"ele: "<< matrix[Row][Column]<<endl;
        if (matrix[Row][Column] == target)
        {
            return true;
        }

        else if (matrix[Row][Column] > target)
        {
            Column--;
            // cout<<"col"<<endl;
        }
        else
        {
            Row++;
            // cout<<"row"<<endl;
        }
    }
    return false;
}
int main()

{

    vector<vector<int>> matrix = {{1, 2}, {3, 4}, {5, 6}};

    cout << searchMatrix(matrix, 5) << endl;

    return 0;
}