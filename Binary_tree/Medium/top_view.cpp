#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    // Write your code here.
    if (root == NULL)
        return ans;

    // take a queue and map

    queue<pair<TreeNode<int> *, int>> q;
    map<int, int> mp;

    // insert root in queue
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int line = it.second;

        if (it.first->left != NULL)
            q.push({it.first->left, line - 1});
        if (it.first->right != NULL)
            q.push({it.first->right, line + 1});

        // push it node into map if not exist
        
                if (mp.find(line) == mp.end())
                {
                 mp.insert({line, it.first->data});

                }
                 
        // mp[line] = it.first->data;
    }

    for (auto p : mp)
    {
        ans.push_back(p.second);
    }

    return ans;
}
