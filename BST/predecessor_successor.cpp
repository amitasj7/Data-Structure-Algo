#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

int predecessorHelper(TreeNode *current, int key, int &predecessor)
{
    if (current == NULL)
        return predecessor;

    if (current->data < key)
    {
        // assign predecessor value
        predecessor = current->data;
        // move right
        return predecessorHelper(current->right, key, predecessor);
    }
    else
    {
        // move left
        return predecessorHelper(current->left, key, predecessor);
    }
}
int SuccessorHelper(TreeNode *current, int key, int &successor)
{
    if (current == NULL)
        return successor;

    if (current->data > key)
    {
        // assign successor value
        successor = current->data;
        // move right
        return SuccessorHelper(current->left, key, successor);
    }
    else
    {
        // move left
        return SuccessorHelper(current->right, key, successor);
    }
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int predecessor = -1, successor = -1;

    return {predecessorHelper(root, key, predecessor), SuccessorHelper(root, key, successor)};
}
