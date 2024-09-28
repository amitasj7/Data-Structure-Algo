/* 1.  Stack(int capacity) constructor me object se  value pass krne ke liye object declartion method =>  Stack st(5)
2. top() function bhi hai so varialbe ko Top se declare krege
3. int * arr dynamically lege
 */

#include <bits/stdc++.h>
using namespace std;

class Stack
{
    // take variables
private:
    int capacity;
    int *arr;
    int Top;

public:
    Stack(int capacity)
    {
        // initialize variables
        Top = -1;
        this->capacity = capacity;
        arr = new int[capacity];

        // Write your code here.
    }

    void push(int num)
    {
        // Write your code here.
        if (isFull())
        {
            return;
        }
        arr[++Top] = num;
    }

    int pop()
    {
        // Write your code here.
        if (isEmpty())
        {
            return -1;
        }
        return arr[Top--];
    }

    int top()
    {
        // Write your code here.
        if (isEmpty())
        {
            return -1;
        }
        return arr[Top];
    }

    int isEmpty()
    {
        // Write your code here.
        return Top == -1;
    }

    int isFull()
    {
        // Write your code here.
        return Top == (this->capacity - 1);
    }
};
int main()
{

    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(6);
    st.push(9);
    st.push(12);
    st.push(10);

    cout << "Full: " << st.isFull() << endl;
    cout << "pop: " << st.pop() << endl;
    cout << "top: " << st.top() << endl;
    cout << "Empty: " << st.isEmpty() << endl;
    cout << "Full: " << st.isFull() << endl;

    return 0;
}