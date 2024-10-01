
#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator
{

    stack<TreeNode *> myStack;

    // reverse  ---> before point from last
    bool reverse;

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext()
    {
        return !myStack.empty();
    }

    // next value find
    int next()
    {
        auto current = myStack.top();
        myStack.pop();

        if (!reverse)
        {
            pushAll(current->right);
        }
        else
        {
            pushAll(current->left);
        }

        return current->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            // push node in stack
            myStack.push(node);
            if (reverse)
                node = node->right;
            else
            {
                node = node->left;
            }
        }
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {

        if (root == NULL)
            return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j)
        {
            if (i + j == k)
                return true;

            if ((i + j) < k)
                i = l.next();
            else
            {
                j = r.next();
            }
        }
        return false;
    }
};