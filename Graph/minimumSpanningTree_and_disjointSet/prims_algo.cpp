#include <bits/stdc++.h>
using namespace std;

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.
    No need to print anything.
    Taking input and printing output is handled automatically.
  */

  // take adjcency list

  vector<vector<pair<int, int>>> adj(n);

  for (auto it : edges)
  {
    int u = it[0];
    int v = it[1];
    int weight = it[2];

    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
  }

  // take a visited vector
  vector<int> visited(n, 0);

  vector<pair<int, int>> mst;

  // <edgeweight,node ,parent>
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

  minHeap.push({0, 0, -1});
  int sum = 0;

  while (!minHeap.empty())
  {
    int edgeweight = minHeap.top()[0];
    int node = minHeap.top()[1];
    int parent = minHeap.top()[2];
    minHeap.pop();

    if (visited[node])
      continue;

    // visite that node
    visited[node] = 1;

    sum += edgeweight;

    // add edge in mst
    // mst.push_back({parent, node});

    // visite adjacency nodes
    for (auto it : adj[node])
    {
      int adjnode = it.first;
      int adjedgeweight = it.second;

      if (!visited[adjnode])
      {
        // push into minHeap
        minHeap.push({adjedgeweight, adjnode, node});
      }
    }
  }

  return sum;
}