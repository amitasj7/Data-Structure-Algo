#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool valid(string &s)
    {

        stack<char> st;

        for (char ch : s)
        {
            // '('  then push into stack
            if (ch == '(')
            {
                st.push(ch);
            }
            // ')' then two case
            else
            {
                if (st.empty())

                    return false;
                else
                    st.pop();
            }
        }

        return st.empty();
    }
    void helper(int ls, string &s, vector<string> &ans)
    {
        // BASE CASE
        if (ls == 0)
        {
            if (valid(s))
            {
                ans.push_back(s);
                return;
            }
            else
            {
                return;
            }
        }

        // LOGIC
        // take open bracket
        s += "(";
        helper(ls - 1, s, ans);

        s.pop_back();

        // take close bracket
        s += ")";
        helper(ls - 1, s, ans);

        s.pop_back();

        // RETURN
    }
    vector<string> generateParenthesis(int n)
    {

        vector<string> ans;
        string s = "";
        int ls = 2 * n; // length of string

        helper(ls, s, ans);

        return ans;
    }
};