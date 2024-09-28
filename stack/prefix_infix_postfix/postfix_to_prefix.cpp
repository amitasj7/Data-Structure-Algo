#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string postToPre(string post_exp)
    {

        stack<string> st;

        for (int i = 0; i < post_exp.size(); i++)

        {
            string ch = "";
            ch = ch + post_exp[i];

            // if operand push stack
            if ((ch >= "a" && ch <= "z") || (ch >= "A" && ch <= "Z") || (ch >= "0" && ch <= "9"))
            {
                st.push(ch);
            }

            // if operator
            else
            {
                // +t2t1
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                st.push(ch + t2 + t1);
            }
        }

        string result = st.top();
        return result;
    }
};