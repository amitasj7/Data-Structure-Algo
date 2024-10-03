#include <bits/stdc++.h>
using namespace std;

template <typename T>
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
};

// Function to check if a node is a leaf node.
bool isLeafNode(BinaryTreeNode<int> *root)
{
    return (root->left == NULL) && (root->right == NULL);
}

// Helper function to find all root-to-leaf paths.

void rootToLeafHelper(BinaryTreeNode<int> *root, vector<string> &paths,
                      string currentPath)
{
    if (root == NULL)
        return;

    // Add the current node to the path
    currentPath += to_string(root->data);

    // If it's a leaf node, add the path to the result
    if (isLeafNode(root))
    {
        paths.push_back(currentPath);
        return;
    }

    // Recursively traverse left and right subtrees
    rootToLeafHelper(root->left, paths, currentPath + " ");

    rootToLeafHelper(root->right, paths, currentPath + " ");
}

vector<string> allRootToLeaf(BinaryTreeNode<int> *root)
{
    vector<string> paths;
    string currentPath = "";
    rootToLeafHelper(root, paths, currentPath);
    return paths;
}

int main()
{
    // Sample Input
    // Create the binary tree: 1 - 2 - 4, 1 - 2 - 5, 1 - 3
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);

    // Get all root-to-leaf paths
    vector<string> paths = allRootToLeaf(root);

    // Sample Output
    for (auto path : paths)
    {
        cout << path << endl;
    }

    return 0;
}

/*
int main()
{

    string str;
    int a = 2;
    str += to_string(a);
    str.push_back('4');

    str.pop_back();

    cout << str << endl;
}
 */