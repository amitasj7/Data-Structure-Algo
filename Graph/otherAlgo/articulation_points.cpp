#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timer = 0;

    void dfs(int node, int parent, vector<int> &visited, vector<int> &mark, vector<int> &insertTime, vector<int> &low, vector<int> adj[])
    {

        visited[node] = 1;

        insertTime[node] = low[node] = timer++;

        int child = 0;

        // traverse all adjecent node
        for (auto it : adj[node])
        {

            if (it == parent)
                continue;

            if (!visited[it])
            {
                dfs(it, node, visited, mark, insertTime, low, adj);
                low[node] = min(low[node], low[it]); // take low value from your child

                if (insertTime[node] <= low[it] && parent != -1) // are you a articulton point
                {
                    mark[node]++;
                }

                child++;  // only for not visited
            }
            else
            {
                low[node] = min(low[node], insertTime[it]); // cross value take
            }
        }

        // for first node
        if (parent == -1 && child > 1)
        {
            mark[node]++;
        }
    }
    vector<int> articulationPoints(int V, vector<int> adj[])
    {

        vector<int> inserTime(V, 0);
        vector<int> low(V, 0);

        vector<int> visited(V, 0);
        vector<int> mark(V, 0);

        // for all connected components

        for (int i = 0; i < V; i++)
        {

            if (!visited[i])
                dfs(i, -1, visited, mark, inserTime, low, adj);
        }

        // take node from mark if value not zero
        vector<int> ans;
        for (int i = 0; i < mark.size(); i++)
        {
            if (mark[i])
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};