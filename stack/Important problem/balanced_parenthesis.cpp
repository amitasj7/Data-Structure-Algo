#include <bits/stdc++.h>
using namespace std;

bool balancedParenthesis2(string s)
{
    // take i that contain open bracket position
    int i = -1;
    // traverse string
    for (auto &ch : s)
    {

        // if opening bracket coming
        if (ch == '(' || ch == '[' || ch == '{')
        {
            // increase i value
            i++;
            // ith position par ch character replace kar dege
            s[i] = ch;
        }
        // for closing brackets
        else
        {
            // closing brackets brother exist
            if ((i >= 0) && ((ch == ')' && s[i] == '(') || (ch == ']' && s[i] == '[') || (ch == '}' && s[i] == '{')))
            {
                i--;
            }
            // closing brackets brother not exist
            else
            {
                return false;
            }
        }
    }

    if (i != -1)
    {
        return false;
    }
    return true;
}
bool balancedParenthesis(string s)
{

    stack<char> st;

    // traverse the string
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            // opening brackets
            st.push(s[i]);
        }
        else if (!st.empty() && s[i] == ')' && st.top() == '(')

        {
            st.pop();
        }
        else if (!st.empty() && s[i] == ']' && st.top() == '[')

        {
            st.pop();
        }
        else if (!st.empty() && s[i] == '}' && st.top() == '{')

        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
    // if stack empty then return true;
    if (!st.empty())
    {
        return false;
    }

    return true;
}
int main()
{
    string str = "]()";

    (balancedParenthesis2(str)) ? cout << "True" << endl : cout << "False" << endl;

    return 0;
}