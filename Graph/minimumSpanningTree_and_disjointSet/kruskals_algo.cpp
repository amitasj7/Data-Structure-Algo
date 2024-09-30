#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0); // 0 or 1 in dono se node start ho skta hai isliye n+1
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int kruskalMST(int n, vector<vector<int>> &edges)
{
    // create a Adjacency list
    vector<vector<int>> adj;

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int edgeWeight = it[2];

        adj.push_back({edgeWeight, u, v});
    }

    sort(adj.begin(), adj.end());

    // for(auto it : adj){  
    //     cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl; 
    // }

    DisjointSet ds(n);
    int mstSum = 0;
    // traverse all of Edges
    for (auto it : adj)
    {
        int u = it[1];
        int v = it[2];

        int edgeWeight = it[0];

        if (ds.findParent(u) != ds.findParent(v))
        {
            mstSum += edgeWeight;

            ds.unionBySize(u, v);
        }
    }

    return mstSum;
}
