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

class Solution {
public:
    TreeNode* findPred(TreeNode* curr) {
        TreeNode* pred = curr->left;
        // Find the rightmost node in the left subtree (predecessor)
        while (pred->right != NULL && pred->right != curr) {
            pred = pred->right;
        }
        return pred;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            // If left child doesn't exist, visit the current node and move to the right child
            if (curr->left == NULL) {
                ans.push_back(curr->val);  // Visit the current node
                curr = curr->right;
            } 
            else {
                // Find the predecessor of the current node
                TreeNode* predecessor = findPred(curr);

                // If the predecessor's right pointer is NULL, set the threaded link and move left
                if (predecessor->right == NULL) {
                    ans.push_back(curr->val);  // Visit the current node before going to the left subtree
                    predecessor->right = curr; // Create a temporary link (threading)
                    curr = curr->left;
                } 
                else {
                    // If the threaded link already exists, remove the link and move to the right subtree
                    predecessor->right = NULL; // Remove the link
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

// Iterative Approach -

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       
        vector<int> preorder;
        
        
        if(root == nullptr) {
            return preorder;
        }
        
        stack<TreeNode*> st;
      st.push(root);
        
      // Perform iterative preorder traversal
        while(!st.empty()) {
           
            root = st.top(); st.pop();
           
            preorder.push_back(root->val);
            
            if(root->right != nullptr) {
                st.push(root->right);
            }
            if(root->left != nullptr) {
                st.push(root->left);
            }
        }
        return preorder;
    }
};


// Recursive

class Solution
{
public:
    void preorder(TreeNode *curr, vector<int> &ans)
    {
        // BASE CASE

        if (curr == NULL)
        {
            return;
        }

        // LOGIC

        ans.push_back(curr->val);
        preorder(curr->left, ans);

        preorder(curr->right, ans);

        // RETURN
    }

    vector<int> preorderTraversal(TreeNode *root)
    {

        vector<int> ans;

        preorder(root, ans);

        return ans;
    }
};

int main()
{
    vector<int> st;
    st.push_back(3);

    cout << st[0] << endl;
}