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

Node *deleteHeadNode(Node *head)
{

    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;

    head = head->next;
    delete temp;
    return head;
}

Node *deleteLastNode(Node *head)
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

// 0-base indexing
Node *deleteNodePos(Node *head, int pos) {
    // If the list is empty or if position is invalid, return the list unchanged
    if (head == NULL) return head;

    // Case when we are deleting the head (position 0)
    if (pos == 0) {
        Node *temp = head;  // Store the current head
        head = head->next;  // Move the head to the next node
        delete temp;        // Delete the old head
        return head;
    }

    // Traverse the list to find the node just before the one to be deleted
    Node *temp = head;
    int count = 0;

    // Traverse until the node just before the node to be deleted or end of list
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    // If temp is NULL or temp->next is NULL, the position is out of bounds
    if (temp == NULL || temp->next == NULL) {
        return head;  // Return the unchanged list
    }

    // Delete the node at position 'pos'
    Node *deleteNode = temp->next;  // The node to be deleted
    temp->next = temp->next->next;  // Bypass the node to be deleted
    delete deleteNode;              // Free memory of the deleted node

    return head;
}


// 0-base indexing
Node *deleteNodeVal(Node *head, int val) {
   
    if (head == NULL) return head;

    
    if (val == head->data) {
        Node *temp = head;  
        head = head->next;  
        delete temp;        
        return head;
    }

    // Traverse the list to find the node just before the one to be deleted
    Node *temp = head;
 

    // Traverse until the node just before the node to be deleted or end of list
    while (temp->next != NULL && temp->next->data !=  val) {
        temp = temp->next;
        
    }

    // If temp is NULL or temp->next is NULL, the position is out of bounds
    if (temp->next == NULL ) {
        return head;  // Return the unchanged list
    }

    // Delete the node at position 'pos'
    Node *deleteNode = temp->next;  // The node to be deleted
    temp->next = temp->next->next;  // Bypass the node to be deleted
    delete deleteNode;              // Free memory of the deleted node

    return head;
}
