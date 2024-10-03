#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

vector<vector<int>> verticalTraversal(TreeNode *root)
{

    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    // take a Queue => (node, vertical, level)
    queue<pair<TreeNode *, pair<int, int>>> q;

    // take a map = (vetical, level, all nodes)
    map<int, map<int, multiset<int>>> nodes;

    // insert root node in queue
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        int size = q.size();

        // level order traversal krte jaye
        for (int i = 0; i < size; i++)
        {
            auto p = q.front();
            q.pop();

            int x = p.second.first, y = p.second.second;
            if (p.first->left != NULL)
                q.push({p.first->left, {x - 1, y + 1}});
            if (p.first->right != NULL)
                q.push({p.first->right, {x + 1, y + 1}});

            // push p into map nodes at position [x][y] and it given a sort position verticals and then level
            nodes[x][y].insert(p.first->val);
        }
    }

    for (auto p : nodes)
    {
        vector<int> vec;
        for (auto q : p.second)
        {
            vec.insert(vec.end(), q.second.begin(), q.second.end());
        }

        ans.push_back(vec);
    }

    return ans;
}