#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ds;
    // if root null hai to
    if (root == NULL)
        return ds;

    queue<TreeNode *> q;
    q.push(root);

    bool flag = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);

            v.push_back(temp->val);

        } // flag = 1 --> left to right
        // flag = 0 --> right to left
        if (flag == 0)
            reverse(v.begin(), v.end());
        ds.push_back(v);

        flag = !flag;
    }

    return ds;
}