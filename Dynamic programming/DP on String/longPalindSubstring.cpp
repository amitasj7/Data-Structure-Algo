#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-substring/

// 1. Recursion

class Solution
{
public:
    bool checkPalindrome(int start, int end, string &s)
    {

        // BASE CASE
        if (end <= start)
            return true; // single character always palindrome

        // LOGIC
        if (s[start] != s[end])
            return false;

        // RETURN
        return checkPalindrome(start + 1, end - 1, s);
    }
    string longestPalindrome(string s)
    {

        int maxlen = 0;
        int si = -1;
        // try out all possible Substring

        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {

                if (checkPalindrome(i, j, s))
                {
                    int len = j - i + 1;

                    if (len > maxlen)
                    {
                        maxlen = len;

                        si = i;
                    }
                }
            }
        }

        string ans = s.substr(si, maxlen);

        return ans;
    }
};

// 2. Memoization

class Solution
{
public:
    bool checkPalindrome(int start, int end, vector<vector<int>> &dp, string &s)
    {

        // BASE CASE
        if (end <= start)
            return true; // single character always palindrome

        // pre - calculated
        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }
        // LOGIC
        if (s[start] != s[end])
            return dp[start][end] = false;

        // RETURN
        return dp[start][end] = checkPalindrome(start + 1, end - 1, dp, s);
    }
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int maxlen = 0;
        int si = -1;
        // try out all possible Substring

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {

                if (checkPalindrome(i, j, dp, s))
                {
                    int len = j - i + 1;

                    if (len > maxlen)
                    {
                        maxlen = len;

                        si = i;
                    }
                }
            }
        }

        string ans = s.substr(si, maxlen);

        return ans;
    }
};

// 3. Tabulation -
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, false));

        int maxlen = 1;
        int si = 0;

        // try out all possible Substring

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            for (int j = 0; j < i; j++)
            {

                if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1]))
                {
                    dp[j][i] = true;
                    int len = i - j + 1;

                    if (len > maxlen)
                    {
                        maxlen = len;

                        si = j;
                    }
                }
            }
        }

        string ans = s.substr(si, maxlen);

        return ans;
    }
};
