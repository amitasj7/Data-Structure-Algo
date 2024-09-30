#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int helper(int i, int j, string &word1, string &word2)
    {
        // Base Case
        if (i < 0)
            return j + 1; // word1 me all char insert krne hoge
        if (j < 0)
            return i + 1; // word1 se all char delete krne hoge

        // logic
        // match character
        if (word1[i] == word2[j])
        {
            return 0 + helper(i - 1, j - 1, word1, word2);
        }

        // not match

        return 1 + min(
                       helper(i, j - 1, word1, word2),
                       min(helper(i - 1, j, word1, word2), helper(i - 1, j - 1, word1, word2)));

        // reutrn
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        int ans = helper(n - 1, m - 1, word1, word2);

        return ans;
    }
};

// Memorization
class Solution2
{
public:
    int helper(int i, int j, vector<vector<int>> &dp, string &word1, string &word2)
    {
        // Base Case
        if (i < 0)
            return j + 1; // word1 me all char insert krne hoge
        if (j < 0)
            return i + 1; // word1 se all char delete krne hoge

        if (dp[i][j] != -1)
            return dp[i][j];
        // logic
        // match character
        if (word1[i] == word2[j])
        {
            return dp[i][j] = 0 + helper(i - 1, j - 1, dp, word1, word2);
        }

        // not match

        return dp[i][j] = 1 + min(
                                  helper(i, j - 1, dp, word1, word2),
                                  min(helper(i - 1, j, dp, word1, word2), helper(i - 1, j - 1, dp, word1, word2)));

        // reutrn
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = helper(n - 1, m - 1, dp, word1, word2);

        return ans;
    }
};

// Tabulation
class Solution3
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // Base Case
        // dp[0][0] = 0; // kuch nahi krna dono string finish 
        // word1 me all char insert krne hoge
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }

        // word1 se all char delete krne hoge
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                // match character
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = 0 + dp[i - 1][j - 1];
                }

                // not match
                else
                {
                    dp[i][j] = 1 + min(
                                       dp[i][j - 1],
                                       min(dp[i - 1][j], dp[i - 1][j - 1]));

                    // reutrn
                }
            }
        }

        int ans = dp[n][m];

        return ans;
    }
};