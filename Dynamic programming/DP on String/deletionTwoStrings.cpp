#include <bits/stdc++.h>
using namespace std;

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
    int minDistance(string word1, string word2)
    {
        int lcs = longestCommonSubsequence(word1, word2);

        int n1 = word1.size();
        int n2 = word2.size();

        // deletions = n1 - lcs
        // insertion  = n2 -lcs

        // return deletions + insertion
        return (n1 + n2 - 2 * lcs);
    }
};