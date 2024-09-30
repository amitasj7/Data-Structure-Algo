#include <bits/stdc++.h>
using namespace std;

/*
input :
5 5
1 0
0 2
2 1
0 3
3 4
 */
class Solution
{
public:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj)
    {
        visited[node] = 1;

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, visited, adj);
            }
        }
    }
    void dfs1(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st)
    {

        visited[node] = 1;

        // traverse all adjcent node
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs1(it, adj, visited, st);
            }
        }

        st.push(node);
    }
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        
        int scc = 0; // strongly connected components

        // 1. create a directed Graph
        // already created

        // sort by their time of visit
        stack<int> st;
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs1(i, adj, visited, st);
        }

        // 2.  reverse all edges
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++)
        {
            // again use of visited
            visited[i] = 0;

            for (auto it : adj[i])
            {
                // i --> it
                // it --> i

                adjT[it].push_back(i);
            }
        }

        // 3. find connected components
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!visited[node])
            {
                scc += 1;
                dfs(node, visited, adjT);
            }
        }

        return scc;
    }
};