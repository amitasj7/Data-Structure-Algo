#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

bool isBalanced(TreeNode *root)
{
    return (maxDepth(root) != -1);
}

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = maxDepth(root->left);

    // check left subtree nodes
    if (lh == -1)
        return -1;

    int rh = maxDepth(root->right);
    // check right subtree nodes
    if (rh == -1)
        return -1;

    // check that node is balanced or not ?
    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}
