#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\DSA_STRIVER_COPY\Binary_tree\basic_data.cpp"

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    /*
    index 0 ==> inorder
    index 1 ==> preorder
    index 2 ==> postorder
     */
    // Write your code here.
    vector<int> inorder, preorder, postorder;
    if (root == NULL)
        return ans;

    stack<pair<TreeNode *, int>> st;

    st.push({root, 1});

    while (!st.empty())
    {
        pair<TreeNode *, int> temp = st.top();
        st.pop();

        // check all three conditions
        if (temp.second == 1)
        {
            // preorder condition
            preorder.push_back(temp.first->val);
            temp.second++;
            // push again into stack
            st.push(temp);

            // if exist left then push it into stack
            if (temp.first->left != NULL)
            {
                st.push({temp.first->left, 1});
            }
        }
        else if (temp.second == 2)
        {
            // inorder condition
            inorder.push_back(temp.first->val);
            temp.second++;

            st.push(temp);

            // if exist left then push it into stack
            if (temp.first->right != NULL)
            {
                st.push({temp.first->right, 1});
            }
        }
        else
        {
            // postorder condition
            postorder.push_back(temp.first->val);
        }
    }

    ans = {inorder, preorder, postorder};

    return ans;
}
int main()
{
    vector<int> ans;
    ans = {9, 8};

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}