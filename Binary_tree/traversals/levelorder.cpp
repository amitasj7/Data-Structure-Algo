#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

// code with level wise
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    // take a Queue Data Structure
    queue<TreeNode *> q1;

    // push root node initially

    q1.push(root);
    while (!q1.empty())
    {

        vector<int> level;
        // cout << "size : " << q1.size() << endl;
        int size = q1.size();

        // take a for loop and run it untill hit queue size
        // it take a level node
        // cout << "i value : ";
        // q1 ka size for loop ke andar change ho raha hai jab left child and right child ko insert kiya ja raha hai isliye alag se suruaat me hi size name ke variable me queue ka size store kar liya gya hai
        for (int i = 0; i < size; i++)
        {
            // cout << i << " ";
            TreeNode *temp = q1.front();
            q1.pop();

            if (temp->left != NULL)
                q1.push(temp->left);
            if (temp->right != NULL)
                q1.push(temp->right);

            level.push_back(temp->val);
        }
        // cout << endl;

        ans.push_back(level);
    }
    return ans;
}
int main()
{
    TreeNode *root = makeTree();
    vector<vector<int>> ans = levelOrder(root);

    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}