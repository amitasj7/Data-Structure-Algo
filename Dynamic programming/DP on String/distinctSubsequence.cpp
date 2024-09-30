#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
class Solution
{
public:
    int helper(int i, int j, string &s, string &t)
    {
        // Base Case
        if (j < 0)
            return 1; // t string complete match ho chuki hai
        if (i < 0)
            return 0; // match krne ke liye kuch nahi bacha hai

        // logic

        // match i and j element
        int notTake = 0;
        int take = 0;
        if (s[i] == t[j])
        {
            take = helper(i - 1, j - 1, s, t);
            notTake = helper(i - 1, j, s, t);
            return take + notTake;
        }

        // not match
        return helper(i - 1, j, s, t);

        // return
    }
    int numDistinct(string s, string t)
    {
        int n1 = s.size();

        int n2 = t.size();

        int ans = helper(n1 - 1, n2 - 1, s, t);

        return ans;
    }
};

// 2. Memorization
class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &dp, string &s, string &t)
    {
        // Base Case
        if (j < 0)
            return 1; // t string complete match ho chuki hai
        if (i < 0)
            return 0; // match krne ke liye kuch nahi bacha hai

        if (dp[i][j] != -1)
            return dp[i][j];
        // logic

        // match i and j element
        int notTake = 0;
        int take = 0;
        if (s[i] == t[j])
        {
            take = helper(i - 1, j - 1, dp, s, t);
            notTake = helper(i - 1, j, dp, s, t);
            return dp[i][j] = take + notTake;
        }

        // not match
        return dp[i][j] = helper(i - 1, j, dp, s, t);

        // return
    }
    int numDistinct(string s, string t)
    {
        int n1 = s.size();

        int n2 = t.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        int ans = helper(n1 - 1, n2 - 1, dp, s, t);

        return ans;
    }
};

// 3. Tabulation

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n1 = s.size();

        int n2 = t.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Base Case
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = 1;
        }

        // already fill by zero
        // if (i < 0)
        //     return 0; // match krne ke liye kuch nahi bacha hai

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {

                // match i and j element
                int notTake = 0;
                int take = 0;
                if (s[i - 1] == t[j - 1])
                {
                    take = dp[i - 1][j - 1];
                    notTake = dp[i - 1][j];
                    dp[i][j] = take + notTake;
                }

                // not match
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int ans = dp[n1][n2];

        return ans;
    }
};


