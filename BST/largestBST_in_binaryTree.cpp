#include <bits/stdc++.h>
using namespace std;

// Following is Binary Tree Node structure:
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class info
{

public:
    int max;
    int min;
    bool isBST;
    int size;
};

info solve(TreeNode *root, int &ans)
{

    if (root == NULL)
        return {INT_MAX, INT_MIN, true, 0};

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info current;

    current.max = max(root->data, right.max);
    current.min = min(root->data, left.min);

    current.size = left.size + right.size + 1;

    if (left.isBST && right.isBST && (root->data > left.max && root->data < right.min))
    {
        current.isBST = true;
    }
    else
    {
        current.isBST = false;
    }

    // ans update
    if (current.isBST)
    {
        ans = max(ans, current.size);
    }
    return current;
}
int largestBST(TreeNode *root)
{
    // Write your code here.

    int maxValue = 0;

    auto temp = solve(root, maxValue);

    return maxValue;
}