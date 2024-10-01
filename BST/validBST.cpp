#include <bits/stdc++.h>
using namespace std;

bool isValidBST(vector<int> &order)
{
    // Write your code here.
    int i = 0;
    while (i < order.size())
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (order[i] < order[left] || order[i] > order[right])
        {
            return false;
        }

        i++;
    }

    return true;
}
