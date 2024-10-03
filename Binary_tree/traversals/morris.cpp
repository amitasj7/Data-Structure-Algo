#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;

    TreeNode *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // visit that node
            ans.push_back(current->val);
            current = current->right;
        }
        else
        {
            // find predecessor
            TreeNode *pred = current->left;
            while (pred->right != NULL && pred->right != current)
            {
                pred = pred->right;
            }

            // link attach
            if (pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }

            // link remove
            else
            {
                pred->right = NULL;
                // visit current node
                ans.push_back(current->val);
                current = current->right;
            }
        }
    }

    return ans;
}