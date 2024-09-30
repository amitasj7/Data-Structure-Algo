#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent, size;

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
class Solution
{
public:
    int connectedComponent(int n, DisjointSet &ds)
    {

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (ds.findParent(i) == i)
            {
                count++;
            }
        }
        return count;
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {

        // find Connected Components

        DisjointSet ds(n);

        int availableCables = 0;

        // find availables calbles
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];

            if (ds.findParent(u) == ds.findParent(v))
            {
                availableCables++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }

        // find requiredCables

        int requiredCables = connectedComponent(n, ds)-1;

        if (availableCables >= requiredCables)
            return requiredCables;

        return -1;
    }
};