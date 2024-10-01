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
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (root == NULL)
        return NULL;

    TreeNode *current = root;

// dono nodes right me hai 
    if (current->val < p->val && current->val < q->val)
    {
        lowestCommonAncestor(current->right, p, q);
    }
    // they exist on left side
    if (current->val > p->val && current->val > q->val)
    {
        lowestCommonAncestor(current->left, p, q);
    }

    return current;
}