#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s)
{

    // take maxDepth and count variable
    int count = 0, maxDepth = 0;

    // traverse whole string
    for (char c : s)
    {

        // if ( then count increase
        if (c == '(')
        {
            count++;
            maxDepth = max(maxDepth, count);
        }
        if (c == ')')
        {
            count--;
        }

        // if ) then count decrease
    }

    // return maxDepth
    return maxDepth;
}