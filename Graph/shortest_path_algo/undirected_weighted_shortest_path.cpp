#include <bits/stdc++.h>
using namespace std;

// using dijkstra's Algo
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // n - vertices , m - Edges

    // create a adjacency list
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // step-1 follow and find parent, distance

    vector<int> parent(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        parent[i] = i;
    }
    vector<int> distance(n + 1, 1e9);

    int source = 0;
    int last = n;

    distance[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    minHeap.push({0, source});

    while (!minHeap.empty())
    {
        int currentdistance = minHeap.top().first;
        int parentNode = minHeap.top().second;
        minHeap.pop();

        for (auto it : adj[parentNode])
        {

            int child = it.first;
            int newdistance = currentdistance + it.second;

            if (newdistance < distance[child])
            {

                // update distance
                distance[child] = newdistance;
                // push the node in the heap so
                minHeap.push({newdistance, child});

                // update parent path
                parent[child] = parentNode;
            }
        }
    }

    if (distance[last] >= 1e9)
    {
        return {-1};
    }

    vector<int> ans;
    int minDistanceSourcetoLast = distance[last];

    // step-2 return list of shortest path
    while (last != source)
    {
        ans.push_back(last); // 1 to 5 node ke liye last+1

        last = parent[last];
    }

    ans.push_back(minDistanceSourcetoLast);

    reverse(ans.begin(), ans.end());

    return ans;
}