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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {

        int k = operators.size();

        DisjointSet dsu(n * m);

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // traverse oprators and find largest land
        vector<int> ans(k, 0);
        int count = 0;

        for (int k1 = 0; k1 < operators.size(); k1++)
        {
            int row = operators[k1][0], col = operators[k1][1];

            // already visited
            if (visited[row][col])
            {

                ans[k1] = count;
                continue;
            }

            visited[row][col] = 1;
            count++;

            // correct the ans
            // traverse this node's all four direction
            int delRow[] = {-1, 0, +1, 0};
            int delCol[] = {0, +1, 0, -1};

            for (int k2 = 0; k2 < 4; k2++)
            {
                int nr = row + delRow[k2];
                int nc = col + delCol[k2];

                int node = row * m + col;
                int adjNode = nr * m + nc;
                if (validLocation(nr, nc, n, m) && visited[nr][nc] && dsu.findUParent(node) != dsu.findUParent(adjNode)) // visited --> land hona chaiye // phle se connect nahi hone chaiye
                {
                    count--;

                    dsu.unionByRank(node, adjNode);
                }
            }

            ans[k1] = count;
        }

        return ans;
    }
};