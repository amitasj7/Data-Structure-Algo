#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

void makeParentMap(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentTrack)
{
    // take a level order traversals with help of queue

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        // for left
        if (temp->left)
        {
            q.push(temp->left);
            parentTrack[temp->left] = temp;
        }

        // for right
        if (temp->right)
        {
            q.push(temp->right);
            parentTrack[temp->right] = temp;
        }
    }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<int> ans;

    unordered_map<TreeNode *, TreeNode *> parentTrack;
    makeParentMap(root, parentTrack);

    unordered_map<TreeNode *, bool> visited;

    queue<TreeNode *> q;

    // initially target ko queue me push krke visited mark kar dege
    q.push(target);
    visited[target] = true;

    int distance = 0;

    while (!q.empty())
    {
        int size = q.size();

        if (distance++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            auto temp = q.front();
            q.pop();

            // two condition = 1. null nahi hona chaiye 2. visited nahi hona chaiye

            // left child
            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
            }
            // right child
            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
            }
            // parent
            if (parentTrack[temp] && !visited[parentTrack[temp]])
            {
                q.push(parentTrack[temp]);
                visited[parentTrack[temp]] = true;
            }
        }
    }

    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }

    return ans;
}