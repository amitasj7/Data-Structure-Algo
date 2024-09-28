#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // define Precedence rules
    int precedence(char c)
    {
        if (c == '^')
        {
            return 3;
        }
        else if (c == '/' || c == '*')
        {
            return 2;
        }
        else if (c == '+' || c == '-')
        {
            return 1;
        }

        return -1;
    }
    string infixToPrefix(string inf_exp)
    {
        // 1. reverse inf_exp
        // 2. convert into postfix
        // 3. reverse again

        reverse(inf_exp.begin(), inf_exp.end());

        int i = 0;
        stack<char> st;
        string result = "";

        while (i < inf_exp.size())
        {

            // operand
            if ((inf_exp[i] >= 'a' && inf_exp[i] <= 'z') || (inf_exp[i] >= 'A' && inf_exp[i] <= 'Z') || (inf_exp[i] >= '0' && inf_exp[i] <= '9'))
            {

                result += inf_exp[i];
            }
            else if (inf_exp[i] == ')') // actually me '('
            {
                st.push('(');
            }
            else if (inf_exp[i] == '(') // acually me ')'
            {

                while (!st.empty() && st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }

                st.pop(); // pop out '('
            }
            else if (inf_exp[i] == '^') // >=
            {

                while (!st.empty() && precedence(st.top()) >= precedence('^'))
                {

                    result += st.top();
                    st.pop();
                }
                // now kam precedence ka point aa chuka hai
            }
            else
            {
                while (!st.empty() && precedence(st.top()) > precedence(inf_exp[i]))
                {

                    result += st.top();
                    st.pop();
                }
                st.push(inf_exp[i]);
            }

            i++;
        }

        reverse(result.begin(), result.end());
        // cout<<"prefix: "<<result<<endl; 

        reverse(inf_exp.begin(), inf_exp.end()); 
        //  cout<<"infix: "<<inf_exp<<endl; 

        

        return result;
    }
};

int main()
{

    Solution help;
    string inf = "((A-(B/C))*((A/K)-L))";

    cout << "prefix : " << help.infixToPrefix(inf) << endl;
}