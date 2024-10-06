#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {

        stack<int> open;
        stack<int> star;

        // balance ')' brackets using traverse
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (ch == '(')
            {
                open.push(i);
            }
            else if (ch == '*')
            {
                star.push(i);
            }
            else
            {
                if (!open.empty())
                {
                    open.pop();
                }
                else if (!star.empty())
                {
                    star.pop();
                }
                else
                    return false;
            }
        }

        // balance '(' brackets
        while (!open.empty())
        {

            if (star.empty() || open.top() > star.top())
            {
                return false;
            }
            open.pop();
            star.pop();
        }

        return true;
    }
    bool checkValidString(string s)
    {

        int star = 0;

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == '*')
            {
                star++;
            }
            else
            {
                if (!st.empty())
                    st.pop();
                else
                {
                    star--;
                }
            }

            if (star < 0)
            {
                return false;
            }
        }

        if (star >= st.size())
        {
            return true;
        }
        return false;
    }
    bool checkValidString(string s)
    {
        if (s.size() == 1)
        {
            if (s[0] == '*')
                return true;

            return false;
        }

        // take a stack
        stack<char> st;

        // traverse whole string
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == ')')
            {
                if (st.empty())
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
            else
            {
                st.push(ch);
            }
        }

        if (st.empty() || (st.size() == 1 && (st.top() == '(' || st.top() == '*')))
        {
            return true;
        }

        return false;
    }
};