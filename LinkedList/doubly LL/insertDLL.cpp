#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *insertHead(int k, int val, Node *head)
{

    Node *newNode = new Node(val);

    if (head == NULL)
        return newNode;

    newNode->next = head;
    head->prev = newNode;

    return newNode;
}

Node *insertLast(int k, int val, Node *head)
{

    Node *newNode = new Node(val);

    if (head == NULL)
        return newNode;

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    newNode->prev = temp;

    return head;
}

// 0 - base indexing
Node *insert(int k, int val, Node *head)
{

    Node *newNode = new Node(val);

    if (head == NULL)
        return newNode;

    if (k == 0)
    {
        newNode->next = head;
        head->prev = newNode;

        return newNode;
    }

    Node *temp = head;
    int count = 0;

    while (temp != NULL && count < k - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) // out of bound
        return head;

    newNode->next = temp->next;

    if (temp->next)
        temp->next->prev = newNode;

    newNode->prev = temp;
    temp->next = newNode;

    return head;
}

// dataLL ke baad val ko insert krna hai
Node *insert(int dataLL, int val, Node *head)
{

    Node *newNode = new Node(val);

    if (head == NULL)
        return newNode;

    if (head->data == dataLL)
    {
        newNode->next = head;
        head->prev = newNode;

        return newNode;
    }

    Node *temp = head;

    while (temp != NULL && temp->data != dataLL)
    {
        temp = temp->next;
    }

    if (temp == NULL) // value not found
        return head;

    newNode->next = temp->next;

    if (temp->next)
        temp->next->prev = newNode;

    newNode->prev = temp;
    temp->next = newNode;

    return head;
}