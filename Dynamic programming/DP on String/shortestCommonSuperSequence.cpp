#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n1 = str1.size();
        int n2 = str2.size();

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
                if (str1[index1 - 1] == str2[index2 - 1])
                {
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                }

                else
                {
                    dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                }
            }
        }

        // now we traverse dp

        int i = n1, j = n2;
        string ans = "";

        while (i > 0 && j > 0)
        {

            // Match character
            if (str1[i - 1] == str2[j - 1])
            {

                char ch = str1[i - 1];

                ans += ch;

                i--;
                j--;
            }

            // Not match character
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                char ch = str1[i - 1];

                ans += ch;

                i--;
            }

            else
            {
                char ch = str2[j - 1];

                ans += ch;

                j--;
            }
        }

        // now remaining character add in ans
        while (i > 0)
        {
            ans += str1[i - 1];
            i--;
        }

        while (j > 0)
        {

            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};