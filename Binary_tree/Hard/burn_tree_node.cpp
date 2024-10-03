#include <bits/stdc++.h>
using namespace std;

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

BinaryTreeNode<int> *createParentMap(map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parentMap, BinaryTreeNode<int> *root, int start)
{
    BinaryTreeNode<int> *targetNode;

    // using queue
    queue<BinaryTreeNode<int> *> q;

    q.push(root);

    while (!q.empty())
    {

        auto temp = q.front();
        q.pop();

        // target node ko find krne ke liye
        if (temp->data == start)
        {
            targetNode = temp;
        }
        if (temp->left)
        {
            q.push(temp->left);
            parentMap[temp->left] = temp;
        }
        if (temp->right)
        {
            q.push(temp->right);
            parentMap[temp->right] = temp;
        }
    }

    return targetNode;
}

int burnTimefun(map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parentMap, BinaryTreeNode<int> *targetNode)
{
    int burnTime = 0;

    map<BinaryTreeNode<int> *, int> visitedBurnMap;

    queue<BinaryTreeNode<int> *> q;
    q.push(targetNode);
    visitedBurnMap[targetNode] = 1;

    while (!q.empty())
    {
        int flag = 0;

        int size = q.size();

        for (int i = 0; i < size; i++)
        {

            auto temp = q.front();
            q.pop();

            // for left
            if (temp->left && !visitedBurnMap[temp->left])
            {
                q.push(temp->left);
                visitedBurnMap[temp->left] = 1;
                flag = 1;
            }

            // for right
            if (temp->right && !visitedBurnMap[temp->right])
            {
                q.push(temp->right);
                visitedBurnMap[temp->right] = 1;
                flag = 1;
            }

            // for parent
            if (parentMap[temp] && !visitedBurnMap[parentMap[temp]])
            {
                q.push(parentMap[temp]);
                visitedBurnMap[parentMap[temp]] = 1;
                flag = 1;
            }
        }

        if (flag == 1)
        {
            burnTime++;
        }
    }

    return burnTime;
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    // Write your code here
    if (root->left == NULL && root->right == NULL)
        return 0;

    map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parentMap;

    BinaryTreeNode<int> *targetNode = createParentMap(parentMap, root, start);

    int burnTime = burnTimefun(parentMap, targetNode);

    return burnTime;
}