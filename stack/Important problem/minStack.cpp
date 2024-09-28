#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    // using pair method
    stack<long long> st;
    long long mini = INT16_MAX;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        // if element < mini then modified value insert 
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else if (val < mini)
        {

            long long modified_value = 2 * val * 1ll - mini;
            st.push(modified_value);
            mini = val;
        }
        else
        {
            st.push(val);
        }
    }

    void pop()
    {
        // cout << "pop: " << st.top() << endl;
        if (st.top() < mini)
        {
            // update mini

            mini = (2 * mini) - st.top();
        }
        st.pop();
        return;
    }

    int top()
    {
        if (st.top() < mini)
        {
            return mini;
        }
        return st.top();
    }

    int getMin()
    {
        return mini;
    }
};
class MinStack2
{
    // using pair method
    stack<pair<int, int>> st;

public:
    MinStack2()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {

            st.push({val, min(val, st.top().second)});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};
int main()
{
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);

    cout << "min: " << st.getMin() << endl;
    cout << "top: " << st.top() << endl;
    st.pop();
    cout << "min: " << st.getMin() << endl;
    cout << "top: " << st.top() << endl;
    st.pop();
    cout << "min: " << st.getMin() << endl;
    return 0;
}