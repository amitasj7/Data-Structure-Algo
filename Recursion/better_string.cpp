#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<string> ans;

    void helper(int ind, string temp, string &str)
    {
        // BASE CASE
        if (ind == str.size())
        {
            ans.insert(temp);
            return;
        }

        // LOGIC
        // 1. take
        helper(ind + 1, temp + str[ind], str);
        // 2. not take
        helper(ind + 1, temp, str);

        // RETURN
    }
    string betterString(string str1, string str2)
    {
        // code here

        helper(0, "", str1);
        int s1 = ans.size();

        ans.clear();
        helper(0, "", str2);
        int s2 = ans.size();

        if (s1 >= s2)
            return str1;

        return str2;
    }
};