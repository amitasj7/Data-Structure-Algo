#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int timer = 1;

public:
    void dfs(int node, int parent, vector<int> &visited, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges)
    {

        visited[node] = 1;
        tin[node] = low[node] = timer;

        timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (visited[it] == 0)
            {
                dfs(it, node, visited, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);

                if (low[it] > tin[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        // n = edges
        // create adjcent Graph
        vector<int> adj[n];

        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n, 0);

        int tin[n], low[n];

        vector<vector<int>> bridges;

        dfs(0, -1, visited, adj, tin, low, bridges);

        return bridges;
    }
};