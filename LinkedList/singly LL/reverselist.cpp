#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseLinkedList(ListNode *head)
    {
        // Base case:
        // If the linked list is empty or has only one node,
        // return the head as it is already reversed.
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Recursive step:
        // Reverse the linked list starting
        // from the second node (head->next).
        ListNode *newHead = reverseLinkedList(head->next);

        // Save a reference to the node following
        // the current 'head' node.
        ListNode *front = head->next;

        // Make the 'front' node point to the current
        // 'head' node in the reversed order.
        front->next = head;

        // Break the link from the current 'head' node
        // to the 'front' node to avoid cycles.
        head->next = NULL;

        // Return the 'newHead,' which is the new
        // head of the reversed linked list.
        return newHead;
    }

    ListNode *findKnode(ListNode *point, int k)
    {

        k = k - 1;
        while (k != 0)
        {
            point = point->next;

            if (point == NULL)
            {
                return NULL;
            }
            k--;
        }

        return point;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head->next == NULL)
            return head;

        ListNode *temp = head;

        ListNode *preNode = NULL;

        while (temp != NULL)
        {

            ListNode *kthNode = findKnode(temp, k);

            if (kthNode == NULL)
            {

                if (preNode != NULL)
                    preNode->next = temp;

                break;
            }

            ListNode *newNode = kthNode->next;
            kthNode->next = NULL;

            kthNode = reverseLinkedList(temp);
            // first part then head
            if (temp == head)
            {
                head = kthNode;
            }
            else
            {
                preNode->next = kthNode;
            }
            preNode = temp;
            temp = newNode;
        }
        return head;
    }
};