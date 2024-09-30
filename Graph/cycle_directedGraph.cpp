#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited, int node)
{

    visited[node] = 1;
    pathVisited[node] = 1;

    for (auto it : adj[node])
    {

        if (visited[it] && pathVisited[it])
        {
            return true;
        }

        // not visited that node
        if (!visited[it] && dfsCycle(adj, visited, pathVisited, it))
        {
            return true;
        }

        // again not visited path marked
    }

    pathVisited[node] = 0;

    return false;
}

bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    //  adjeceny list is created
    vector<vector<int>> adj(e);

    for (int i = 0; i < e; i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> visited(v, 0);
    vector<int> pathVisited(v, 0);

    for (int i = 0; i < v; i++)
    {

        if (!visited[i] && dfsCycle(adj, visited, pathVisited, i))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {2, 6}, {3, 4}, {4, 5}, {6, 4}, {7, 0}, {7, 8}, {8, 9}, {7, 9}};

    if (isCyclic(edges, 10, 11))
        cout << "true";
    else
    {
        cout << "false";
    }
}