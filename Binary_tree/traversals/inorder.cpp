#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Morris Approch -

class Solution
{
public:
    TreeNode *findPred(TreeNode *curr)
    {

        TreeNode *pred = curr->left;

        while (pred->right != NULL && pred->right != curr) // right me chalte jaa rahe hai // agar link phle se hi attach hai to --
        {
            pred = pred->right;
        }

        return pred;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        // left root right ---> inorder

        vector<int> ans;

        TreeNode *curr = root;

        while (curr != NULL)
        {

            // if left doesn't exist
            if (curr->left == NULL)
            {

                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {

                TreeNode *predecessor = findPred(curr);

                // link attach if not already attach
                if (predecessor->right == NULL)
                {
                    predecessor->right = curr;
                    curr = curr->left;
                }

                // link remove
                else
                {
                    predecessor->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

// Iterative Approach -
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;

        while (true)
        {
            if (root == NULL)
            {
                // stack top value print
                // update root
                if (st.empty())
                    break;

                root = st.top();
                st.pop();

                ans.push_back(root->val);
                root = root->right;

                // update root
            }
            else
            {
                // push into stack that node
                st.push(root);

                // update root
                root = root->left;
            }
        }
        return ans;
    }
};

// Recursive

class Solution
{
public:
    void inorder(TreeNode *curr, vector<int> &ans)
    {
        // BASE CASE

        if (curr == NULL)
        {
            return;
        }

        // LOGIC

        inorder(curr->left, ans);

        ans.push_back(curr->val);

        inorder(curr->right, ans);

        // RETURN
    }

    vector<int> inorderTraversal(TreeNode *root)
    {

        vector<int> ans;

        inorder(root, ans);

        return ans;
    }
};
int main()
{
    vector<int> st;
    st.push_back(3);

    cout << st[0] << endl;
}