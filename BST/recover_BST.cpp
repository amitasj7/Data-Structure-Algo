
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

class Solution
{
private:
    TreeNode *first;
    TreeNode *middle;
    TreeNode *prev;
    TreeNode *last;

    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);

        if (prev != NULL && (root->val < prev->val))
        {

            // first violation mark = first and middle node
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }

            // second violation mark = last node
            else
            {
                last = root;
            }
        }

        // Mark this node as previous
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {

        // initially all point to NULL
        first = middle = last = NULL;

        prev = new TreeNode(INT_MIN);
        inorder(root);

        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};