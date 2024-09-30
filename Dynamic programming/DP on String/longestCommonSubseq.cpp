#include <bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/

// 1. Recursion
class Solution
{
public:
    int helper(int index1, int index2, string text1, string text2)
    {
        // Base Case

        if (index1 < 0 || index2 < 0)
            return 0;

        // logic

        if (text1[index1] == text2[index2])
        {
            return 1 + helper(index1 - 1, index2 - 1, text1, text2);
        }

        else
        {
            return 0 + max(helper(index1 - 1, index2, text1, text2), helper(index1, index2 - 1, text1, text2));
        }

        // return
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();

        int ans = helper(n1 - 1, n2 - 1, text1, text2);
        return ans;
    }
};

// 2. Memorization
class Solution
{
public:
    int helper(int index1, int index2, vector<vector<int>> dp, string text1, string text2)
    {
        // Base Case

        if (index1 < 0 || index2 < 0)
            return 0;

        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        // logic

        if (text1[index1] == text2[index2])
        {
            return dp[index1][index2] = 1 + helper(index1 - 1, index2 - 1, dp, text1, text2);
        }

        else
        {
            return dp[index1][index2] = 0 + max(helper(index1 - 1, index2, dp, text1, text2), helper(index1, index2 - 1, dp, text1, text2));
        }

        // return
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        int ans = helper(n1 - 1, n2 - 1, dp, text1, text2);
        return ans;
    }
};

// 1.2 Recursion update -1 0 1 2  ---> 0 1 2 3
class Solution
{
public:
    int helper(int index1, int index2, string text1, string text2)
    {
        // Base Case

        if (index1 == 0 || index2 == 0)
            return 0;

        // logic

        if (text1[index1 - 1] == text2[index2 - 1])
        {
            return 1 + helper(index1 - 1, index2 - 1, text1, text2);
        }

        else
        {
            return 0 + max(helper(index1 - 1, index2, text1, text2), helper(index1, index2 - 1, text1, text2));
        }

        // return
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();

        int ans = helper(n1, n2, text1, text2);
        return ans;
    }
};

// 3. Tabulation
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();

        // shifting index
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Base Case fill index by 0
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = 0;
        }

        // logic
        for (int index1 = 1; index1 <= n1; index1++)
        {
            for (int index2 = 1; index2 <= n2; index2++)
            {
                // string ko access krte time index ko shift krna hoga
                if (text1[index1 - 1] == text2[index2 - 1])
                {
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                }

                else
                {
                    dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                }
            }
        }

        int ans = dp[n1][n2];
        return ans;
    }
};

// 4. Space Optimized

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();

        // shifting index
        vector<int> prev(n2 + 1, 0), current(n2 + 1, 0);

        // Base Case fill index by 0

        // it is alreadt fill by 0

        // logic
        for (int index1 = 1; index1 <= n1; index1++)
        {
            for (int index2 = 1; index2 <= n2; index2++)
            {
                // string ko access krte time index ko shift krna hoga
                if (text1[index1 - 1] == text2[index2 - 1])
                {
                    current[index2] = 1 + prev[index2 - 1];
                }

                else
                {
                    current[index2] = max(prev[index2], current[index2 - 1]);
                }
            }
            prev = current;
        }

        int ans = prev[n2];
        return ans;
    }
};


// print LCS 
/*
Input: ‘s1’  = “abcab”, ‘s2’ = “cbab”

Output: “bab”
*/
class Solution
{
public:
    string findLCS(int n, int m, string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();

        // shifting index
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Base Case fill index by 0
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = 0;
        }

        // logic
        for (int index1 = 1; index1 <= n1; index1++)
        {
            for (int index2 = 1; index2 <= n2; index2++)
            {
                // string ko access krte time index ko shift krna hoga
                if (s1[index1 - 1] == s2[index2 - 1])
                {
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                }

                else
                {
                    dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                }
            }
        }

        int ans = dp[n1][n2];

        // Write your code here.
        int len = ans;

        string lcs(len, '$');

        int index = len - 1;

        // traverse the dp from last cell --
        int i = n1, j = n2;

        while (i >= 1 && j >= 1)
        {
            // diagonal case
            if (s1[i - 1] == s2[j - 1])
            {
                char ch = s1[i - 1];
                lcs[index] = ch;
                index--;

                i--;
                j--;
            }
            // up and left case
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }

        return lcs;
    }
};
