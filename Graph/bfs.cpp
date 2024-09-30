#include <bits/stdc++.h>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    // Write your code here.

    vector<vector<int>> edgeslist(n);
    int E = adj.size();

    for (int i = 0; i < E; i++)
    {

        int firstVertex = adj[i][0];
        int secondVertex = adj[i][1];

        edgeslist[firstVertex].push_back(secondVertex);
        edgeslist[secondVertex].push_back(firstVertex);
    }
    vector<int> ans;
    vector<int> visited(n, 0);

    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while (!q.empty())
    {

        int node = q.front();
        q.pop();

        // put node into ans
        ans.push_back(node);

        for (auto it : edgeslist[node])
        {
            if (!visited[it])
            {

                q.push(it);
                visited[it] = 1;
            }
        }
    }
    return ans;
}