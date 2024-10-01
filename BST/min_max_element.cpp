#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr){};
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
bool leafnode(Node *root)
{
    return root->left == NULL && root->right == NULL;
}
int minValue(Node *root)
{
    // Write your code here.
    if (root == NULL)
        return -1;

    while (root->left != NULL)
    {
        root = root->left
    }

    return root->data;
}