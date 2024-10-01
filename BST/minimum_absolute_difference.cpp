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
public:
    vector<int> vec;

    void inorder(TreeNode *node)
    {

        // BASE CASE

        if (node == NULL)
            return;

        // LOGIC
        inorder(node->left);

        int value = node->val;
        vec.push_back(value);

        inorder(node->right);

        // RETURN
    }
    int minDiffInBST(TreeNode *root)
    {

        inorder(root);

        int n = vec.size();

        int mini = INT_MAX;

        for (int i = 1; i < n; i++)
        {

            int diff = vec[i] - vec[i - 1];

            mini = min(mini, diff);
        }

        return mini;
    }
};