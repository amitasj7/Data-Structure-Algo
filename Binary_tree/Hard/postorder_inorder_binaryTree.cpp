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

TreeNode *createTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp)
{

    if (postStart > postEnd || inStart > inEnd)
        return NULL;
    TreeNode *root = new TreeNode(postorder[postEnd]);

    // inroot point to inorder
    int inRoot = mp[postorder[postEnd]];
    // find left and right of any nodes;
    int leftNodes = inRoot - inStart;

    root->left = createTree(postorder, postStart, postStart + leftNodes - 1, inorder, inStart, inRoot - 1, mp);
    root->right = createTree(postorder, postStart + leftNodes, postEnd - 1, inorder, inRoot + 1, inEnd, mp);

    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{

    // create inorder map
    unordered_map<int, int> mp;

    int size = inorder.size();
    for (int i = 0; i < size; i++)
    {
        mp[inorder[i]] = i;
    }

    TreeNode *root = createTree(postorder, 0, size - 1, inorder, 0, size - 1, mp);

    return root;
}