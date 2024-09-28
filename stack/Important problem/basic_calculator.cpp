#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {

        int result = 0;
        int number = 0;
        int sign = 1;
        stack<int> st;
        int n = s.size();

        // traverse whole string
        for (char ch : s)
        {

            if (isdigit(ch))
            {
                // update number
                number = (number * 10) + (ch - '0');
            }
            else if (ch == '-')
            {
                result = result + number * sign;

                sign = -1;
                number = 0;
            }
            else if (ch == '+')
            {
                result = result + number * sign;

                sign = 1;
                number = 0;
            }
            else if (ch == '(')
            {
                // push into stack result , sign
                st.push(result);
                st.push(sign);
                // update number, result, sign
                number = 0;
                result = 0;
                sign = 1;
            }
            else if (ch == ')')
            {
                result = result + (number * sign);
                number = 0;
                sign = 1;

                result = result * st.top();
                st.pop();
                result = result + st.top();
                st.pop();
            }
        }

        result = result + number * sign;

        return result;
    }
};