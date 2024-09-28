
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string postToInfix(string exp)
    {
        // Write your code here

        stack<string> st;

        for (int i = 0; i < exp.size(); i++)

        {
            string ch = "";
            ch = ch + exp[i];

            // if operand push stack
            if ((ch >= "a" && ch <= "z") || (ch >= "A" && ch <= "Z") || (ch >= "0" && ch <= "9"))
            {
                st.push(ch);
            }

            // if operator
            else
            {
                // t2+t1
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                st.push("(" + t2 + ch + t1 + ")");
            }
        }

        string result = st.top();
        return result;
    }
};