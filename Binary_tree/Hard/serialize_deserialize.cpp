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

string serialize(TreeNode *root)
{

    string str = "";
    if (root == NULL)
        return str;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {

        auto temp = q.front();
        q.pop();

        if (temp == NULL)
            str += "#,";
        else
        {
            str += to_string(temp->val) + ",";
            // push into queue chahe left or right child null value contain krte ho
            q.push(temp->left);
            q.push(temp->right);
        }
    }

    return str;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data.length() == 0)
        return NULL;

    stringstream s(data);
    string str;

    // , ke basis par separation kar rahe hai
    getline(s, str, ',');

    TreeNode *root = new TreeNode(stoi(str));

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
            node->left = NULL;

        else
        {
            node->left = new TreeNode(stoi(str));
            q.push(node->left);
        }

        getline(s, str, ',');
        if (str == "#")
        {
            node->right = NULL;
        }
        else
        {
            node->right = new TreeNode(stoi(str));
            q.push(node->right);
        }
    }
    return root;
}