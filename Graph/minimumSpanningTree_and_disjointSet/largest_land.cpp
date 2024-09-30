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
            size[i] = 1; // intially all nodes take size 1.
        }
    }

    int findUParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v) // ek hi component ke node hai
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
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v) // ek hi component ke node hai
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
    bool validLocation(int row, int col, int n, int m)
    {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        DisjointSet dsu(n * m);

        // 1. create DSU

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                    continue; // create only for 1

                // traverse this node's all four direction
                int delRow[] = {-1, 0, +1, 0};
                int delCol[] = {0, +1, 0, -1};

                for (int k = 0; k < 4; k++)
                {
                    int nr = i + delRow[k];
                    int nc = j + delCol[k];

                    if (validLocation(nr, nc, n, m) && grid[nr][nc])
                    {
                        int node = i * m + j;
                        int adjNode = nr * m + nc;
                        dsu.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int maxi = INT_MIN;
        // 2. 0 ---> 1

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    continue; // only take 0 so we can 0 ---> 1

                unordered_set<int> st;
                // traverse this node's all four direction
                int delRow[] = {-1, 0, +1, 0};
                int delCol[] = {0, +1, 0, -1};

                for (int k = 0; k < 4; k++)
                {
                    int nr = i + delRow[k];
                    int nc = j + delCol[k];

                    if (validLocation(nr, nc, n, m) && grid[nr][nc])
                    {
                        int node = i * m + j;
                        int adjNode = nr * m + nc;
                        st.insert(dsu.findUParent(adjNode)); // only one time store so not conflict
                    }
                }

                int size = 1;
                for (int up : st)
                {
                    size += dsu.size[up];
                }

                maxi = max(maxi, size);
            }
        }

        // for all 1 Edge case
        for (int cell = 0; cell < n * m; cell++)
        {
            maxi = max(maxi, dsu.size[dsu.findUParent(cell)]);
        }

        return maxi;
    }
};