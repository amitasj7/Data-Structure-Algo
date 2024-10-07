/* 1. queue ke empty ki two condition front == -1 and rear == front but in second condition , we update rear and front again -1. so it is only one condition that is front = -1

2. queue full two condition => 1. rear +1 = size  2. rear +1 = front
*/

#include <bits/stdc++.h>
using namespace std;

class Queue
{

    int front, rear;
    vector<int> arr;

public:
    Queue()
    {
        front = -1;
        rear = -1;
        arr.resize(100001);
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        // Write your code here.
        // queue is full

        if ((rear + 1 == front) || (rear + 1 == arr.size()))
        {
            // cout << "full queue" << endl;
            return;
        }
        // queue is empty
        else if (front == -1)
        {
            // cout << "empty queue" << endl;
            arr[++rear] = e;
            front++;
        }

        else
        {
            // cout << "normal queue" << endl;

            rear = (rear + 1) % arr.size();
            arr[rear] = e;
        }
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        // Write your code here.
        if ((front == -1))
        {
            // cout << "empty queue de" << endl;
            return -1;
        }
        int value = arr[front];
        if ((front == rear))
        {
            // jaise hi front and rear same huye unko turant -1 par patak diya gya hai so empty ki only one situation hai ki front == -1
            // cout << "full queue de" << endl;
            front = rear = -1;
        }
        else
        {
            // cout << "normal queue de" << endl;

            front = (front + 1) % arr.size();
        }
        return value;
    }
    bool isEmpty()
    {
        return (front == -1);
    }
    bool isFull()
    {
        return (rear + 1 == front) || (rear + 1 == arr.size());
    }
};
int main()
{

    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);

    cout << "dequeue: " << q.dequeue() << endl;
    cout << "dequeue: " << q.dequeue() << endl;
    cout << "dequeue: " << q.dequeue() << endl;
    cout << "dequeue: " << q.dequeue() << endl;

    q.enqueue(30);
    q.enqueue(40);

    cout << "dequeue: " << q.dequeue() << endl;
    cout << "dequeue: " << q.dequeue() << endl;
    cout << "dequeue: " << q.dequeue() << endl;
    cout << "dequeue: " << q.dequeue() << endl;

    return 0;
}