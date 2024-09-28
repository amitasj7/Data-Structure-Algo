#include <bits/stdc++.h>
using namespace std;

class Stack
{
    // Write your code here
    int size;
    Node *Top;

public:
    Stack()
    {
        Top = NULL;
        size = 0;
        // Write your code here
    }

    int getSize()
    {
        return size;
        // Write your code here
    }

    bool isEmpty()
    {
        // Write your code here
        return Top == NULL;
    }

    void push(int data)
    {
        // Write your code here
        Node *newnode = new Node(data);
        // if stack is empty
        if (isEmpty())
        {
            Top = newnode;
            return;
        }

        // connect newnode to Top
        newnode->next = Top;
        // update Top
        Top = newnode;
    }

    void pop()
    {
        // Write your code here
        if (isEmpty())
        {
            return;
        }
        Node *temp = Top;
        // update Top
        Top = Top->next;

        // disconnect temp
        temp->next = NULL;
        delete temp;
    }

    int getTop()
    {
        // Write your code here
        return Top->data;
    }
};
int main()
{

    return 0;
}