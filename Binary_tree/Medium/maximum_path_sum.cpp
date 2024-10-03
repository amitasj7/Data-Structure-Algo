#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

int maxPathSum(TreeNode *root)
{

    int maxSum = 0;

    int x = maxSumHelper(TreeNode * root, maxSum);

    return maxSum;
}

int maxSumHelper(TreeNode *root, int &maxSum) 
{

    if (root == NULL)
        return 0;

    int ls = max(0, maxPathSum(root->left));
    int rs = max(0, maxPathSum(root->right));

    maxSum = max(maxSum, ls + rs + root->val);

    return root->val + max(ls, rs);
}