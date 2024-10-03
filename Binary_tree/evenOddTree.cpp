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
    bool isEvenOddTree(TreeNode *root)
    {

        if (root->val % 2 == 0)
        {
            return false;
        }

        queue<TreeNode *> q;

        int flag = 1; // 1 ---> odd value and 0 --> even value

        q.push(root);

        while (!q.empty())
        {

            int size = q.size(); // level wise traverse
            flag = !flag;
            int inc = INT_MIN, dec = INT_MAX;
            while (size--)
            {
                if (flag == 0)
                {
                    TreeNode *node = q.front();
                    q.pop();

                    if (node->left)
                    {
                        if (node->left->val % 2 == 0 && node->left->val < dec)
                        {
                            q.push(node->left);
                            dec = node->left->val;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    if (node->right)
                    {
                        if (node->right->val % 2 == 0 && node->right->val < dec)
                        {
                            q.push(node->right);
                            dec = node->right->val;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else
                {

                    TreeNode *node = q.front();
                    q.pop();

                    if (node->left)
                    {
                        if (node->left->val % 2 != 0 && node->left->val > inc)
                        {
                            q.push(node->left);
                            inc = node->left->val;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    if (node->right)
                    {
                        if (node->right->val % 2 != 0 && node->right->val > inc)
                        {
                            q.push(node->right);
                            inc = node->right->val;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};