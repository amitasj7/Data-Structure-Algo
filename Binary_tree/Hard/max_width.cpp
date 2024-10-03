#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

int widthOfBinaryTree(TreeNode *root)
{
    int ans = 0;
    if (!root)
        return ans;

    // take a queue
    queue<pair<TreeNode *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {

        int size = q.size();
        // current_min every  level ka minimum index hai 
        int current_min = q.front().second;

        int first, last;

        for (int i = 0; i < size; i++)
        {
            auto temp = q.front().first;
            // every node ki current id current_min ke according change hogi 
            int current_id = q.front().second - current_min;
            q.pop();

            if (temp->left)
                q.push({temp->left, 2 * current_id + 1});
            if (temp->right)
                q.push({temp->left, 2 * current_id + 2});

            if (i == 0)
                first = current_id;
            if (i == size - 1)
                last = current_id;
        }
        ans = max(ans, last - first + 1);
    }

    return ans;
}