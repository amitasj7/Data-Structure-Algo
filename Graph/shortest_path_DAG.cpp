#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfsTopoSort(vector<vector<pair<int, int>>> &graph, vector<int> &visited, stack<int> &st, int currentNode)
    {

        visited[currentNode] = 1;

        for (auto it : graph[currentNode])
        {

            int node = it.first;
            int weight = it.second;
            if (!visited[node])
            {
                dfsTopoSort(graph, visited, st, node);
            }
        }

        st.push(currentNode);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // N - total Vertices
        // M - total Edges

        // create a adjcencylist

        // <node,weight>
        vector<vector<pair<int, int>>> adj(N);

        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            adj[u].push_back({v, weight});
        }

        vector<int> visited(N, 0);

        // take a stack
        stack<int> st;

        for (int i = 0; i < N; i++)
        {

            if (!visited[i])
            {
                dfsTopoSort(adj, visited, st, i);
            }
        }

        vector<int> dist(N, 1e9);
        int src = 0;
        dist[src] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {
                int v = it.first;
                int weight = it.second;

                int totaldistace = dist[node] + weight;

                if (totaldistace < dist[v])
                {
                    // update distance array
                    dist[v] = totaldistace;
                }
            }
        }

        for (int i = 0; i < dist.size(); i++)
        {

            if (dist[i] >= 1e9)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
