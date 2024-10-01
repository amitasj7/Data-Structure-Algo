class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ceilValue = -1;
    while (node)
    {

        if (node->data == x)
        {
            ceilValue = node->data;
            return ceilValue;
        }

        if (node->data < x)
        {
            // move right side
            node = node->right;
        }
        else
        {
            // fill ceil value and update move left side
            ceilValue = node->data;
            node = node->left;
        }
    }
    return ceilValue;
}

int Floor(BinaryTreeNode<int> *node, int input)
{
    int ceil = -1;

    while (node)
    {

        if (node->data == input)
        {
            ceil = input;
            return ceil;
        }
        if (node->data > x)
        {
            node = node->left;
        }
        else
        {
            // ceil value ban skta hai
            ceil = node->data;

            // iske upar wale bhi ho skti hai
            node = node->right;
        }
    }

    return ceil;
}
