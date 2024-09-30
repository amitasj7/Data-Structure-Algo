#include <bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
class Solution
{
public:
    bool check(string &str1, string &str2)
    {
        if (str1.size() != str2.size() + 1)
            return false;

        int n1 = str1.size();
        int n2 = str2.size();

        int i = 0, j = 0;

        while (i < n1)
        {

            // match both char
            if (str1[i] == str2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }

        if (i == n1 && j == n2)
            return true;

        return false;
    }
  static  bool comp(string &str1, string &str2)
    {
        return str1.size() < str2.size();
    }
    int longestStrChain(vector<string> &words)
    {

        sort(words.begin(), words.end(), comp);

        int n = words.size();
        vector<int> dp(n, 1);

        int ans = 0;

        for (int current = 0; current < n; current++)
        {
            // fill current element longest incresing subsequence
            for (int prev = 0; prev < current; prev++)
            {

                if (check(words[current], words[prev]) && 1 + dp[prev] > dp[current])
                {
                    // update current length
                    dp[current] = 1 + dp[prev];
                }
            }

            if (ans < dp[current])
            {
                ans = dp[current];
            }
        }

        return ans;
    }
};