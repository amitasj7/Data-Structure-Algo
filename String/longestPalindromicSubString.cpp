#include <bits/stdc++.h>
using namespace std;

// Minimum Size SubArray Sum --->
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int ans = INT_MAX;

        int window = 0;
        int n = nums.size();

        int left = 0;
        for (int right = 0; right < n; right++)
        {
            window += nums[right];

            while (window >= target)
            {
                ans = min(ans, right - left + 1);
                window -= nums[left];
                left++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
class Solution
{
public:
    string longestPalindrome(string s)
    {

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        string ans;

        int maxlength = 0;

        for (int diff = 0; diff < n; diff++)
        {

            for (int i = 0, j = i + diff; j < n; i++, j++)
            {
                if (i == j)
                    dp[i][j] = 1;

                else if (diff == 1)
                    dp[i][j] = (s[i] == s[j]) ? 2 : 0;

                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1])
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }

                if (dp[i][j])
                {
                    if (j - i + 1 > maxlength)
                    {
                        maxlength = j - i + 1;
                        ans = s.substr(i, maxlength);
                    }
                }
            }
        }

        return ans;
    }
};

class Solution
{
public:
    bool isPalindrome(string check)
    {

        int i = 0;
        int j = check.length() - 1;

        while (i < j)
        {

            if (check[i] != check[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
    string longestPalindrome(string s)
    {

        string ans = "";

        int n = s.size();

        // find each substring
        for (int i = 0; i < n; i++)
        {
            string check = "";
            for (int j = i; j < n; j++)
            {

                check += s[j];

                if (check.length() > ans.length() && isPalindrome(check))
                {
                    ans = check;
                }
            }
        }

        return ans;
    }
};