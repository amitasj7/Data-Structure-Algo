#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
    bool detectionNodeDFS(vector<int> adj[], int node, int parentNode, vector<int> &visited)
    {

        visited[node] = 1;

        for (auto it : adj[node])
        {

            if (visited[it] && it != parentNode)
            {
                // cycle detect
                return true;
            }
            if (!visited[it] && detectionNodeDFS(adj, it, node, visited) == true)
            {
                return true;
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
            if (!visited[i] && detectionNodeDFS(adj, i, -1, visited) == true)
            {

                return true;
            }
        }

        return false;
    }
};