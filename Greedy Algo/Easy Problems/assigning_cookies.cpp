#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    int i = 0;
    int j = 0;

    int gSize = g.size();
    int sSize = s.size();

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    while (i < gSize && j < sSize)
    {

        // assign cookie
        if (s[j] >= g[i])
        {
            i++;
        }
        j++;
    }

    // max children
    return i;
}