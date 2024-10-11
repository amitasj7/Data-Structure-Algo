#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{

    if (s.length() == 1)
    {
        return false;
    }

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
            continue;
        }
        if ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '{' && st.top() == '}'))
            st.pop();
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{

    return 0;
}