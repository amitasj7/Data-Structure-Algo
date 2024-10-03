#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

bool isSymmetric(TreeNode *root)
{

    if (root == NULL)
        return true;

    return isSymmetricHelper(root->left, root->right);
}

bool isSymmetricHelper(TreeNode *left, TreeNode *right)
{
    if (left == NULL || right == NULL)
    {
        return left == right;
    }

    return (left->val == right->val) && isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}