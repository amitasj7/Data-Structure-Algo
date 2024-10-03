#include <bits/stdc++.h>
using namespace std;

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
    void dfs(TreeNode *root, int val, int depth, int currdepth)
    {
        // BASE CASE
        if (root == NULL)
        {
            return;
        }

        // LOGIC
        if (currdepth == depth - 1)
        {
            TreeNode *newLeftChild = new TreeNode(val);
            TreeNode *newRightChild = new TreeNode(val);

            // connect all newnode
            newLeftChild->left = root->left;
            root->left = newLeftChild;

            newRightChild->right = root->right;
            root->right = newRightChild;
        }
        else
        {
            dfs(root->left, val, depth, currdepth + 1);
            dfs(root->right, val, depth, currdepth + 1);
        }

        // RETURN
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {

        if (depth == 1)
        {
            TreeNode *newNode = new TreeNode(val);

            newNode->left = root;

            return newNode;
        }

        dfs(root, val, depth, 1);

        return root;
    }
};