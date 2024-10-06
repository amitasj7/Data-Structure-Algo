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

Node *deleteHead(Node *head)
{

    if (head == NULL || head->next == NULL)
        return NULL;

    Node *deleteNode = head;
    head = head->next;

    if (head)
        head->prev = NULL;
    delete deleteNode;

    return head;
}

Node *deleteLast(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    return head;
}

// 0 - base Indexing
Node *deleteNode(Node *head, int pos)
{
    if (head == NULL)
        return head; // If the list is empty

    // Special case: Deleting the head node (position 0)
    if (pos == 0)
    {
        Node *temp = head; // Store current head to delete
        head = head->next; // Move head to next node

        if (head != NULL) // Adjust prev pointer if head is not NULL
            head->prev = NULL;

        delete temp; // Free the old head memory
        return head;
    }

    // Traverse to the node at position 'pos'
    Node *temp = head;
    int count = 0;

    while (count < pos && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    // Check if pos is out of bounds
    if (temp == NULL)
        return head;

    // Deleting node at position 'pos'
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    // Delete the node
    delete temp;
    return head;
}

// 0 - base Indexing
Node *deleteNodeval(Node *head, int val)
{
    if (head == NULL)
        return head; // If the list is empty

    // Special case: Deleting the head node (position 0)
    if (head->data == val)
    {
        Node *temp = head; // Store current head to delete
        head = head->next; // Move head to next node

        if (head != NULL) // Adjust prev pointer if head is not NULL
            head->prev = NULL;

        delete temp; // Free the old head memory
        return head;
    }

    // Traverse to the node at position 'pos'
    Node *temp = head;

    while (temp != NULL && temp->data != val)
    {
        temp = temp->next;
    }

    // Check if pos is out of bounds
    if (temp == NULL)
        return head;

    // Deleting node at position 'pos'
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    // Delete the node
    delete temp;
    return head;
}