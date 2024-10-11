#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int len = strs.size();

    // sort vector of string
    sort(strs.begin(), strs.end());

    string ans = "";
    int i = 0;

    // check first and last string
    while (strs[0].size() >= 1 && strs[len - 1].size() >= 1 && (strs[0][i] == strs[len - 1][i]))
    {

        ans += strs[0][i];
        i++;
        if (i == strs[0].size() || i == strs[len - 1].size())
        {
            break;
        }
    }

    return ans;
}