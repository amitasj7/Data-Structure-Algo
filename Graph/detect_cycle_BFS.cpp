#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
    bool detectionNode(vector<int> adj[], int node, vector<int> &visited)
    {
        visited[node] = 1;

        // <node, parentNode>
        queue<pair<int, int>> q;
        q.push({node, -1});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            for (auto i : adj[it.first])
            {
                if (visited[i] && it.second != i)
                {
                    return true;
                }
                if (!visited[i])
                {
                    q.push({i, it.first});
                    visited[i] = 1;
                }
            }
        }

        return false;
    }
    bool detectCycle(int V, vector<int> adj[])
    {
        // Write your code here.

        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && detectionNode(adj, i, visited) == true)
            {

                return true;
            }
        }

        return false;
    }
};