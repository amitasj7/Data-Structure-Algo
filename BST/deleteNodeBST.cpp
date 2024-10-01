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
    // 1. node ko delete karo
    // 2. left child ke sabsa bda element pkdo jo left child ke right most part me hoga
    // 3. node ke right child ko is element ke saath jod do
    // 4. now left child node ko node ke parent se connect kar do
    TreeNode *deleteNode(TreeNode *root, int key)
    {

        if (root == NULL)
            return NULL;

        if (root->val == key)
            return helper(root);

        TreeNode *dummy = root;
        while (dummy != NULL)
        {
            if (dummy->val > key)
            {
                if (dummy->left != NULL && dummy->left->val == key)
                {
                    dummy->left = helper(dummy->left);
                    break;
                }
                else
                {
                    dummy = dummy->left;
                }
            }
            else
            {

                if (dummy->right != NULL && dummy->right->val == key)
                {
                    dummy->right = helper(dummy->right);
                    break;
                }
                else
                {
                    dummy = dummy->right;
                }
            }
        }

        return root;
    }

    TreeNode *helper(TreeNode *root)
    {
        if (root->left == NULL)
            return root->right;

        if (root->right == NULL)
            return root->left;

        auto rightChild = root->right;

        auto lastRight = findlast(root->left);

        lastRight->right = rightChild;

        return root->left;
    }

    TreeNode *findlast(TreeNode *node)
    {
        if (node->right == NULL)
            return node;

        return findlast(node->right);
    }
};