#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    queue<int> q;

public:
    // stack operation push, pop and top
    void push(int x)
    {
        q.push(x);

        // now if size >1 then n-1 element again insert
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        q.pop();
    }
    int top()
    {
        return q.front();
    }
    bool empty(){  
        return q.empty(); 
    }
};
class MyStack2
{

    queue<int> q1;
    queue<int> q2;

public:
    // stack operation push, pop and top
    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop()
    {
        q1.pop();
    }
    int top()
    {
        return q1.front();
    }
};
int main()
{

    MyStack2 st;
    st.push(3);
    st.push(2);
    st.push(4);
    st.push(1);

    cout << st.top() << endl; // 1
    st.pop();
    cout << st.top() << endl; // 4
    st.pop();

    return 0;
}