#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string preToInfix(string pre_exp)
    {
        // Write your code here

        reverse(pre_exp.begin(), pre_exp.end());

        stack<string> st;

        for (int i = 0; i < pre_exp.size(); i++)

        {
            string ch = "";
            ch = ch + pre_exp[i];

            // if operand push stack
            if ((ch >= "a" && ch <= "z") || (ch >= "A" && ch <= "Z") || (ch >= "0" && ch <= "9"))
            {
                st.push(ch);
            }

            // if operator
            else
            {
                // t1+t2
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                st.push("(" + t1 + ch + t2 + ")");
            }
        }

         reverse(pre_exp.begin(), pre_exp.end());

        string result = st.top();
        return result;
    }
};