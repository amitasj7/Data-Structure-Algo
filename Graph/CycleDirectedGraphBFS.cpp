#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int> adj[])
{

    // take indegree Vector
    vector<int> indeg(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it]++;
        }
    }

    // indegree vector complete

    // take a queue and push 0 indegree node
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty())
    {

        int value = q.front();
        q.pop();

        ans.push_back(value);

        for (auto it : adj[value])
        {

            indeg[it]--;
            if (indeg[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return ans.size() == V;
}