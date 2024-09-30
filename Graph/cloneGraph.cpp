#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *dfs(Node *node, vector<Node *> &visited)
    {

        // checking for visited or not
        if (visited[node->val] != NULL)
        {

            return visited[node->val];
        }

        Node *clone = new Node(node->val);
        // visite mark
        visited[node->val] = clone;

        for (auto it : node->neighbors)
        {
            // fill neighbours vector of clone
            clone->neighbors.push_back(dfs(it, visited));
        }

        return clone;
    }
    Node *cloneGraph(Node *node)
    {

        if (node == NULL)
            return node;

        // take a unorderedSet
        vector<Node *> visited(101, NULL);

        return dfs(node, visited);
    }
};