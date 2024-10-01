#include <bits/stdc++.h>
using namespace std;

TreeNode *searchBST(TreeNode *root, int val)
{

    while (root != NULL && root->val != val)
    {

        if (root->val < val)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return root;
}