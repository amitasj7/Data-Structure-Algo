#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

int countLeftHeight(TreeNode *root)
{

    int height = 0;
    while (root)
    {
        height++;
        // update root
        root = root->left;
    }
    return height;
}
int countRightHeight(TreeNode *root)
{

    int height = 0;
    while (root)
    {
        height++;
        // update root
        root = root->right;
    }
    return height;
}

int countHeight(TreeNode *root)
{

    if (root == NULL)
        return 0;
    return 1 + max(countHeight(root->left), countHeight(root->right));
}
int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = countLeftHeight(root);
    int rh = countRightHeight(root);

    if (lh == rh)
        // 2 ki power lh - 1 ;
        return (1 << lh) - 1;

    return 1 + (countNodes(root->left)) + (countNodes(root->right));
}