#include <bits/stdc++.h>
using namespace std;

bool isPalindromeHelper1(string ans)
{
    int len = ans.length();
    // base case
    if (len == 0 || len == 1)
    {
        return true;
    }

    // calculation  : upadate string
    if (ans[0] != ans[len - 1])
    {
        return false;
    }

    ans = ans.substr(1, len - 2);

    return isPalindromeHelper(ans);
}
bool isPalindromeHelper(string ans)
{
    int len = ans.length();
    string str = ans;

    reverse(ans.begin(), ans.end());

    return str == ans;
}
bool isPalindrome(string s)
{
    // traverse all string and convert alphaNum string
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalnum(s[i]))
        {

            char ch = s[i];
            if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch - 'A' + 'a';
            }

            ans += ch;
        }
    }

    // check that string is palindrome or not ?
    return isPalindromeHelper(ans);
}