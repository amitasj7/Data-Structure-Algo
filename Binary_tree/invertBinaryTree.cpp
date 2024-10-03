#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return root;

        // take a queue
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();

            q.pop();

            TreeNode *left = NULL;
            TreeNode *right = NULL;

            if (node->right != NULL)
            {

                right = node->right;
                q.push(right);
            }
            if (node->left != NULL)
            {
                left = node->left;
                q.push(left); 
            }

            // invert left and right
            node->left = right;
            node->right = left;
        }

        return root;
    }
};