#include <bits/stdc++.h>
using namespace std;

long long findncr(int n, int r)
{

    long long res = 1;

    for (int i = 1; i <= r; i++)
    {

        res = res * (n - i + 1);
        res = res / (i);
    }

    return res;
}

vector<long long int> kthRow(int k)
{
    vector<long long> ans;
    int row = k;

    long long val = 1;
    ans.push_back(val); // first value always 1

    for (int col = 2; col <= row; col++) // find other value
    {

        val = val * (row - col + 1);
        val = val / (col - 1);

        ans.push_back(val);
    }
    return ans;
}

vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> ans;
    for (int row = 1; row <= n; row++)
    {

        vector<long long int> rowno = kthRow(row);

        ans.push_back(rowno);
    }

    return ans;
}
