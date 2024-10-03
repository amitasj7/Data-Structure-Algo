#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

bool isSameTree(TreeNode *p, TreeNode *q)
{

    if (p == NULL || q == NULL)
        return p == q;

    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}