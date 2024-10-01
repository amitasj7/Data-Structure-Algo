#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution
{
public:
    void findMini(Node *curr, int &mini)
    {

        // BASE CASE
        if (curr == NULL)
            return;

        // LOGIC
        if (curr->data < mini)
            mini = curr->data;

        findMini(curr->left, mini);

        // RETURN
    }

    int minValue(Node *root)
    {
        int mini = INT_MAX;
        findMini(root, mini);
        return mini;
    }
};