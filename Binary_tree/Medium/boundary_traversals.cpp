#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

bool isLeafNode(TreeNode *root)
{
    return (root->left == NULL && root->right == NULL);
}

void checkLeft(TreeNode *root, vector<int> &ans)
{
    TreeNode *current = root->left;

    while (current != NULL)
    {
        if (!isLeafNode(current))
            ans.push_back(current->data);

        // phle left ki taraf jaige then left ke null hone par right ko access karege
        if (current->left)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
}
void checkLeaf(TreeNode *root, vector<int> &ans)
{
    if (isLeafNode(root))
    {
        ans.push_back(root->data)
    }

    if (root->left)
        checkLeaf(root->left, ans);
    if (root->right)
        checkLeaf(root->right, ans);
}
void checkRight(TreeNode *root, vector<int> &ans)
{
    TreeNode *current = root->right;

    // take a vector to reverse right nodes
    vector<int> vec;
    while (current)
    {
        if (!isLeafNode(current))
            vec.push_back(current->data);

        if (current->right)
            current = current->right;
        else
        {
            current = current->left;
        }
    }

    // vec ko reverse krke ans me push kare
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        ans.push_back(vec[i]);
    }
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;

    // 1. if root is NULL
    if (root == NULL)
        return ans;

    if (!isLeafNode(root))
        ans.push_back(root->data);

    checkLeft(root, ans);
    checkLeaf(root, ans);
    checkRight(root, ans);
}