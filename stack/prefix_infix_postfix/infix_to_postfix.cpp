/*
1. if open bracket ( hai to aapko precedence check nahi krni , directly push krna hai
2. if close bracket hai to aapko jab tak nikalne  hai ki open bracket mil nahi jata
 */

#include <bits/stdc++.h>
using namespace std;

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
string infixToPostfix(string exp)
{
    // Write your code here
    stack<char> st;
    string postfix;
    for (auto &c : exp)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix = postfix + c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            // if expression character agar closing bracket hai to stack ke andar open bracket jaroor milega
            while ((st.top() != '('))
            {
                postfix = postfix + st.top();
                st.pop();
            }
            // now open bracket '(' ko pop kare
            st.pop();
        }

        else
        {

            // push operators and open brackets

            // but st.top ki precedence jyada hai ya equal hai , to pop up krte jaige jab tak chhoti precedence ka top nahi mil jata  and then push krege
            while ((!st.empty()) && (precedence(st.top()) >= precedence(c)))
            {
                postfix = postfix + st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    // pop remaining element
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}
int main()
{
    // string exp = "(a+b)/(c-d)-(e*f)";
    // string exp = "a*b/c+e/f*g+k-x*y";
    string exp = "K+L-M*N+(O^P)*W/U/V*T+Q";

    cout << "Postfix: " << infixToPostfix(exp) << endl;

    return 0;
}