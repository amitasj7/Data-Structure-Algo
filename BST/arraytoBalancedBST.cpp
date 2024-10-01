

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
    TreeNode *helper(int left, int right, vector<int> &nums)
    {
        // BASE CASE
        if (left > right)
        {
            return NULL;
        }

        // LOGIC
        int mid = left + (right - left) / 2;

        TreeNode *node = new TreeNode(nums[mid]);

        node->left = helper(left, mid - 1, nums);
        node->right = helper(mid + 1, right, nums);

        // RETURN
        return node;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();

        return helper(0, n - 1, nums);
    }
};