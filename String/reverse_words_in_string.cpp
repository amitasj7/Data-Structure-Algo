#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    // take two pointer i and  j
    int i;
    int j = i;

    string ans;
    string helper = "";
    // traverse whole string from backside
    for (i = s.length() - 1; i >= 0; i--)
    {
        // if it is not space then add it to ans
        if (s[i] != ' ')
        {
            helper += s[i];
        }
        else
        {
            reverse(helper.begin(), helper.end());
            if (helper != "")
                ans += helper + " ";
            helper = "";
        }
    }

    // for last word
    reverse(helper.begin(), helper.end());
    ans += helper;

    // remove ending space
    i = ans.length() - 1;
    while (ans[i] == ' ')
    {
        i--;
    }

    ans = ans.substr(0, i + 1);

    return ans;
}
int main()
{
    cout << reverseWords("  heol w dhi   ");

    return 0;
}