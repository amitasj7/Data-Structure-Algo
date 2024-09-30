#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};


class Solution
{
public:
    int helper(TreeNode *root)
    {
        // BASE CASE
        if (root == NULL)
            return 0;

        // LOGIC

        int notPick = helper(root->left) + helper(root->right);

        int pick = root->val +
                   ((root->left == NULL)
                        ? 0
                        : helper(root->left->left) + helper(root->left->right)) +
                   ((root->right == NULL)
                        ? 0
                        : helper(root->right->left) + helper(root->right->right));

        // RETURN
        return max(pick, notPick);
    }
    int rob(TreeNode *root)
    {

        int ans = helper(root);

        return ans;
    }
};
// memo

class Solution
{
public:
    int helper(TreeNode *root, map<TreeNode *, int> &mp)
    {
        // BASE CASE
        if (root == NULL)
            return mp[root] = 0;

        // LOGIC
        if (mp.find(root) != mp.end())
            return mp[root];
        int notPick = helper(root->left, mp) + helper(root->right, mp);

        int pick = root->val +
                   ((root->left == NULL)
                        ? 0
                        : helper(root->left->left, mp) + helper(root->left->right, mp)) +
                   ((root->right == NULL)
                        ? 0
                        : helper(root->right->left, mp) + helper(root->right->right, mp));

        // RETURN
        return mp[root] = max(pick, notPick);
    }
    int rob(TreeNode *root)
    {

        map<TreeNode *, int> dp;

        int ans = helper(root, dp);

        return ans;
    }
};
