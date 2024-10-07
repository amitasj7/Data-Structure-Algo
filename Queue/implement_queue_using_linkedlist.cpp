/*
1. rear kisi node se dynamically connect hai then us node ko delete kar diya gya tab bhi rear us node ka address hi store kiye huye hoga
2. front == NULL that only one condition hai jo empty queue ko show krti hai
3.
 */

#include <bits/stdc++.h>
using namespace std;

//   Definition of linked list
class Node
{

public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

//   Definition of Queue
struct Queue
{
    Node *front;
    Node *rear;
    void push(int);
    int pop();

    Queue()
    {
        front = rear = NULL;
    }
};

void Queue::push(int x)
{
    // Write Your Code Here
    Node *newnode = new Node(x);

    // if queue is empty
    if (front == NULL)
    {
        front = rear = newnode;
    }
    // rear = new Node(x, rear->next);
    rear->next = newnode;

    rear = newnode;
}

int Queue::pop()
{
    // Write Your Code Here
    if (front == NULL)
        return -1;
    Node *temp = front;
    // update front
    // if (front != NULL)
    front = front->next;
    // if (front == NULL)
    // {
    //     rear = NULL;
    // }
    int value = temp->data;

    delete temp;

    return value;
}
int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    q.push(30);
    q.push(40);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}