
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs1(vector<vector<int>> &adj, vector<int> &count, int &node0, int currentNode, int parent, int currentDepth)
    {
        // all child of that node including node
        int totalCount = 1;

        node0 += currentDepth;

        // tarverse all neighbours
        for (auto &child : adj[currentNode])
        {

            if (child == parent)
                continue;

            totalCount += dfs1(adj, count, node0, child, currentNode, currentDepth + 1);
        }

        count[currentNode] = totalCount;
        return totalCount;
    }

    void dfs2(auto &adj, vector<int> &ans, vector<int> &count, int totalNodes, int currentNode, int parent)
    {
        for (auto &child : adj[currentNode])
        {
            if (child == parent)
            {
                continue;
            }

            ans[child] = ans[currentNode] - count[child] + (totalNodes - count[child]);

            dfs2(adj, ans, count, totalNodes, child, currentNode);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(n);

        // create a graph
        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n, 0);

        vector<int> count(n, 0);

        // call dfs and fill count

        int node0 = 0;
        int totalNodes = dfs1(adj, count, node0, 0, -1, 0);

        ans[0] = node0;

        // call dfs and fill result

        dfs2(adj, ans, count, totalNodes, 0, -1);

        return ans;
    }
};