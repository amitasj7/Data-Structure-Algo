#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insertBottom(int top, stack<int> &st)
    {
        // BASE CASE
        if (st.empty())
        {
            st.push(top);
            return;
        }

        // LOGIC
        int ele = st.top();
        st.pop();

        insertBottom(top, st);
        st.push(ele);

        // RETURN
    }
    void Reverse(stack<int> &st)
    {

        // BASE CASE

        if (st.empty())
            return;

        // LOGIC
        int top = st.top();
        st.pop();

        Reverse(st);

        insertBottom(top, st);

        // RETURN
    }
};