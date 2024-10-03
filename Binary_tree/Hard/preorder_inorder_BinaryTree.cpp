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

TreeNode *createTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp)
{

    if (preStart > preEnd || inStart > inEnd)
        return NULL;
    TreeNode *root = new TreeNode(preorder[preStart]);

    // inroot point to inorder
    int inRoot = mp[preorder[preStart]];
    // find left and right of any nodes;
    int leftNodes = inRoot - inStart;

    root->left = createTree(preorder, preStart + 1, preStart + leftNodes, inorder, inStart, inRoot - 1, mp);
    root->right = createTree(preorder, preStart + leftNodes + 1, preEnd, inorder, inRoot + 1, inEnd, mp);

    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{

    // create inorder map
    unordered_map<int, int> mp;

    int size = inorder.size();
    for (int i = 0; i < size; i++)
    {
        mp[inorder[i]] = i;
    }

    TreeNode *root = createTree(preorder, 0, size - 1, inorder, 0, size - 1, mp);

    return root;
}

