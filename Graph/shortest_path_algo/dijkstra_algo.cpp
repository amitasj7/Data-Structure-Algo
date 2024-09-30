#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, INT_MAX); // Initialize all distances as infinity

    // take min heap = <distance,node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    dist[S] = 0;
    minHeap.push({0, S});

    while (!minHeap.empty())
    {

        int node = minHeap.top().second;
        int distance = minHeap.top().first;

        minHeap.pop();

        for (auto it : adj[node])
        {
            int newNode = it[0];
            int edgeWt = it[1];

            int totaldistance = distance + edgeWt;

            if (totaldistance < dist[newNode])
            {

                // update distance
                dist[newNode] = totaldistance;
                minHeap.push({totaldistance, newNode});
            }
        }
    }
    return dist;
}