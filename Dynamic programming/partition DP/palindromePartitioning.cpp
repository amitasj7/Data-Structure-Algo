#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ispalindrome(string &temp)
    {
        string temp2 = temp;
        reverse(temp2.begin(), temp2.end());
        return temp2 == temp;
    }
    int helper(int i, int n, string &s)
    {
        // Base Case
        if (i == n)
            return 0;

        // Logic
        int mini = INT32_MAX;
        string temp = "";
        for (int j = i; j < n; j++)
        {
            temp += s[j];

            if (ispalindrome(temp))
            {
                int cuts = 1 + helper(j + 1, n, s);
                mini = min(mini, cuts);
            }
        }

        // return
        return mini;
    }
    int minCut(string s)
    {
        int n = s.size();

        int ans = helper(0, n, s);

        return ans;
    }
};

// memo

class Solution
{
public:
    bool ispalindrome(string &temp)
    {
        string temp2 = temp;
        reverse(temp2.begin(), temp2.end());
        return temp2 == temp;
    }
    int helper(int i, vector<int> &dp, int n, string &s)
    {
        // Base Case
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        // Logic
        int mini = INT32_MAX;
        string temp = "";
        for (int j = i; j < n; j++)
        {
            temp += s[j];

            if (ispalindrome(temp))
            {
                int cuts = 1 + helper(j + 1, dp, n, s);
                mini = min(mini, cuts);
            }
        }

        // return
        return dp[i] = mini;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);

        int ans = helper(0, dp, n, s) - 1;

        return ans;
    }
};

// Tabulation

class Solution
{
public:
    bool ispalindrome(string &temp)
    {
        string temp2 = temp;
        reverse(temp2.begin(), temp2.end());
        return temp2 == temp;
    }
   
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        //   // Base Case Already fill with 0
        // if (i == n)
        //     return 0;

        for (int i = n - 1; i >= 0; i--)
        {
            // Logic
            int mini = INT32_MAX;
            string temp = "";
            for (int j = i; j < n; j++)
            {
                temp += s[j];

                if (ispalindrome(temp))
                {
                    int cuts = 1 + dp[j + 1];
                    mini = min(mini, cuts);
                }
            }

            // return
            dp[i] = mini;
        }

        int ans = dp[0] - 1;

        return ans;
    }
};