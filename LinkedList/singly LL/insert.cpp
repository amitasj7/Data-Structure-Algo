#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *insertHead(Node *head, int val)
{

    Node *newNode = new Node(val);
    newNode->next = head;

    return newNode;
}

Node *insertEnd(Node *head, int val)
{

    Node *newNode = new Node(val);

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

// 0 base-indexing
Node *insert(Node *head, int n, int pos, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
        return newNode;

    if (pos == 0)
    {

        newNode->next = head;

        return newNode;
    }

    Node *temp = head;
    int count = 0;

    while (count < pos - 1 && temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (temp == NULL)
        return head; // out of bound position

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// dataLL ke baad  val node insert krna hai

Node *insert(Node *head, int n, int dataLL, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
        return newNode;

    if (head->data == val)
    {

        newNode->next = head;

        return newNode;
    }

    Node *temp = head;
    int count = 0;

    while (temp != NULL && temp->data != dataLL)
    {

        temp = temp->next;
    }

    if (temp == NULL)
        return head; // not found dataLL

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}