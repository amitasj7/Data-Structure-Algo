
class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

bool isParentSum(Node *root)
{
    // Write your code here.

    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;

    int childSum = 0;

    if (root->left)
        childSum += root->left->data;
    if (root->right)
        childSum += root->right->data;

    if (childSum != root->data)
        return false;

    return isParentSum(root->left) && isParentSum(root->right);
}