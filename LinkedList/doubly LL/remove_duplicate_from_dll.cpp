
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

Node *removeDuplicates(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = head->next; // head ke next me lege
    Node *back = NULL;

    while (temp != NULL)
    {

        if (temp->data == temp->prev->data)
        {

            back = temp->prev;
            while (temp != NULL && temp->data == temp->prev->data) // jab tak same hai aage bdte jao
            {
                temp = temp->next;
            }

            if (temp)
                temp->prev = back;
            back->next = temp;

            back = temp;
        }

        if (temp)
            temp = temp->next;
    }

    return head;
}