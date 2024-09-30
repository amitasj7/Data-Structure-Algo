#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool helper(string &s1, string &s2, string &s3, vector<vector<vector<int>>> &dp, int n1, int n2, int n3, int k, int j1, int j2)
    {
        // BASE CASE

        if (k == n3 && j1 == n1 && j2 == n2)
            return true;

        if (k == n3)
        {
            return false;
        }

        if (dp[k][j1][j2] != -1)
            return dp[k][j1][j2];

        // LOGIC
        bool result1 = false;
        bool result2 = false;
        if (s3[k] == s1[j1])
        {

            result1 = helper(s1, s2, s3, dp, n1, n2, n3, k + 1, j1 + 1, j2);
        }
        if (s3[k] == s2[j2])
        {
            result2 = helper(s1, s2, s3, dp, n1, n2, n3, k + 1, j1, j2 + 1);
        }

        // RETURN

        return dp[k][j1][j2] = result1 || result2;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        // take a 3d dp

        vector<vector<vector<int>>> dp(n3 + 1, vector<vector<int>>(n1 + 1, vector<int>(n2 + 1, -1)));

        if (n1 + n2 != n3)
            return false;

        return helper(s1, s2, s3, dp, n1, n2, n3, 0, 0, 0);
    }
};

class Solution
{
public:
    bool helper(string &s1, string &s2, string &s3, vector<vector<int>> &dp, int n1, int n2, int n3, int k, int j1, int j2)
    {
        // BASE CASE

        if (k == n3 && j1 == n1 && j2 == n2)
            return true;

        if (k == n3)
        {
            return false;
        }

        if (dp[j1][j2] != -1)
            return dp[j1][j2];

        // LOGIC
        bool result1 = false;
        // bool result2 = false;
        if (s3[k] == s1[j1])
        {

            result1 = helper(s1, s2, s3, dp, n1, n2, n3, k + 1, j1 + 1, j2);
        }
        if (result1)
        {
            return dp[j1][j2] = result1;
        }
        if (s3[k] == s2[j2])
        {
            result1 = helper(s1, s2, s3, dp, n1, n2, n3, k + 1, j1, j2 + 1);
        }

        // RETURN

        return dp[j1][j2] = result1;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        // take a 3d dp

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        if (n1 + n2 != n3)
            return false;

        return helper(s1, s2, s3, dp, n1, n2, n3, 0, 0, 0);
    }
};

// tabulation
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        if (n1 + n2 != n3)
            return false;

        // take a 3d dp

        vector<vector<vector<int>>> dp(n3 + 1, vector<vector<int>>(n1 + 1, vector<int>(n2 + 1, false)));

        dp[n3][n1][n2] = true;

        // LOGIC

        for (int k = n3 - 1; k >= 0; k--)
        {

            for (int j1 = 0; j1 <= n1; j1++)
            {
                for (int j2 = 0; j2 <= n2; j2++)
                {
                    bool result1 = false;
                    bool result2 = false;
                    if (j1 + 1 <= n1 && s3[k] == s1[j1])
                    {

                        result1 = dp[k + 1][j1 + 1][j2];
                    }
                    if (j2 + 1 <= n2 && s3[k] == s2[j2])
                    {
                        result2 = dp[k + 1][j1][j2 + 1];
                    }

                    dp[k][j1][j2] = result1 || result2;
                }
            }
        }

        // RETURN
        bool ans = dp[0][0][0];

        return ans;
    }
};