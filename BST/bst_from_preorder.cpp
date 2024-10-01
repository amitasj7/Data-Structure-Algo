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
TreeNode *buildBST(vector<int> &preorder, int &i, int bound)
{

    if (i == preorder.size() || preorder[i] > bound)
        return NULL;

    TreeNode *root = new TreeNode(preorder[i++]);
    cout << "value of i : " << i << endl;
    root->left = buildBST(preorder, i, root->val);
    root->right = buildBST(preorder, i, bound);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;

    return buildBST(preorder, i, INT_MAX);
}

int main()
{

    vector<int> v = {8, 5, 1, 7, 10, 12};
    auto root = bstFromPreorder(v);
}