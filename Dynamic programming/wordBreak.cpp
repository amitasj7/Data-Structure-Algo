#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_set<string> st;
    int n;

public:
    bool helper(int index, vector<int> &dp, string &s)
    {

        // BASE CASE
        if (index == n)
            return true;

        // LOGIC
        if (dp[index] != -1)
            return dp[index];

        for (int len = 1; len <= n; len++)
        {

            string temp = s.substr(index, len);

            if (st.find(temp) != st.end() && helper(index + len, dp, s))
                return dp[index] = true;
        }

        // RETURN
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {

        st.insert(wordDict.begin(), wordDict.end());
        n = s.size();
        
        vector<int> dp(n, -1);

        return helper(0, dp, s);
    }
};