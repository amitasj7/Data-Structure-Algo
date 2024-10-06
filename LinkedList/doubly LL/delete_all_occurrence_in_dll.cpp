#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node *deleteAllOccurrences(Node *head, int k)
{

    if (head == NULL || (head->next == NULL && head->data == k))
        return NULL;

    Node *back;
    Node *temp = head;

    Node *dummy = new Node(-1);
    dummy->next = head;
    head->prev = dummy;

    while (temp != NULL)
    {

        if (temp->data == k)
        {

            back = temp->prev;

            while (temp != NULL && temp->data == k)
            {
                temp = temp->next;
            }
            // now temp us node par hai jo k ke equal nahi hai
            if (temp)
                temp->prev = back;
            if (back)
                back->next = temp;
        }

        if (temp)
            temp = temp->next;
    }

    head = dummy->next;
    return head;
}