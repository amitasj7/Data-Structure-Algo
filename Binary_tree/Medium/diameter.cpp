#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

int diameterOfBinaryTree(TreeNode *root)
{

    int diameter = 0;

    int x = maxDepth(root, diameter);
    return diameter;
}

int maxDepth(TreeNode *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int lh = maxDepth(root->left);

    int rh = maxDepth(root->right);

    diameter = max(diameter, lh + rh);

    // return that node height
    return 1 + max(lh, rh);
}