

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *insertIntoBST(TreeNode *root, int val)
{

    if (root == NULL)
        return new TreeNode(val);

    TreeNode *current = root;

    while (true)
    {
        if (cur->val <= val)
        {
            if ()
            {
            }
            else
            {
            }
        }
        else
        {
            if ()
            {
            }
            else
            {
            }
        }
    }
}