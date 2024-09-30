#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool helper(int i, int j, string &s, string &p)
    {

        // Base Case
        // dono string exhausted s="" and p=""
        if (i < 0 && j < 0)
            return true;

        // s="" and p = "xyz"
        if (i < 0 && j >= 0)
            return false;

        //      s="***" p=""
        if (i >= 0 && j < 0)
        {
            // check for all characters is star or not
            while (i >= 0)
            {
                if (s[i] != '*')
                    return false;

                i--;
            }
            // all star
            return true;
        }

        // Logic

        if (s[i] == p[j] || s[i] == '?')
        {
            return helper(i - 1, j - 1, s, p);
        }
        if (s[i] == '*')
        {
            return helper(i, j - 1, s, p) || helper(i - 1, j, s, p);
        }

        // return
        // s="xyz" and p = "abc"
        return false;
    }
    bool isMatch(string s, string p)
    {

        int n = s.size();
        int m = p.size();

        bool ans = helper(m - 1, n - 1, p, s);

        return ans;
    }
};

// memorization
class Solution
{
public:
    bool helper(int i, int j, vector<vector<int>> dp, string &s, string &p)
    {

        // Base Case
        // dono string exhausted s="" and p=""
        if (i < 0 && j < 0)
            return true;

        // s="" and p = "xyz"
        if (i < 0 && j >= 0)
            return false;

        //      s="***" p=""
        if (i >= 0 && j < 0)
        {
            // check for all characters is star or not
            while (i >= 0)
            {
                if (s[i] != '*')
                    return false;

                i--;
            }
            // all star
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Logic

        if (s[i] == p[j] || s[i] == '?')
        {
            return dp[i][j] = helper(i - 1, j - 1, dp, s, p);
        }
        if (s[i] == '*')
        {
            return dp[i][j] = helper(i, j - 1, dp, s, p) || helper(i - 1, j, dp, s, p);
        }

        // return
        // s="xyz" and p = "abc"
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p)
    {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        bool ans = helper(m - 1, n - 1, dp, p, s);

        return ans;
    }
};

// Tabulation
class Solution
{
public:
    bool isMatch(string s, string p)
    {

        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // Base Case
        // dono string exhausted s="" and p=""
        dp[0][0] = true;

        // s="" and p = "xyz"
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = false;
        }

        //      s="***" p=""
        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int j = 1; j <= i; j++)
            {

                if (p[j - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // Logic

                if (s[j - 1] == p[i - 1] || p[i - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[i - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }

                else
                {
                    // s="xyz" and p = "abc"
                    dp[i][j] = false;
                }
            }
        }
        bool ans = dp[n][m];

        return ans;
    }
};

// space optimisation

class Solution
{
public:
    bool isMatch(string s, string p)
    {

        int m = s.size();
        int n = p.size();

        vector<int> prev(m + 1, 0), current(m + 1, 0);
        // Base Case
        // dono string exhausted s="" and p=""
        prev[0] = true;

        // s="" and p = "xyz"
        for (int j = 1; j <= m; j++)
        {
            prev[j] = false;
        }

        //      s="***" p=""

        for (int i = 1; i <= n; i++)
        {
            // assign current[0]
            bool flag = true;
            for (int j = 1; j <= i; j++)
            {

                if (p[j - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            current[0] = flag;

            // now assign other
            for (int j = 1; j <= m; j++)
            {
                // Logic

                if (s[j - 1] == p[i - 1] || p[i - 1] == '?')
                {
                    current[j] = prev[j - 1];
                }
                else if (p[i - 1] == '*')
                {
                    current[j] = current[j - 1] || prev[j];
                }

                else
                {
                    // s="xyz" and p = "abc"
                    current[j] = false;
                }
            }
            prev = current;
        }
        bool ans = prev[m];

        return ans;
    }
};
