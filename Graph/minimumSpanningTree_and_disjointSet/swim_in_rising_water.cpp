#include <bits/stdc++.h>
using namespace std;

// m-2: DSU
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
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        DisjointSet dsu(n * m);

        vector<tuple<int, int, int>> vec; // <elevation,row,col>

        // store in tuple
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vec.push_back({grid[i][j], i, j});
            }
        }

        sort(vec.begin(),vec.end()); 

        for (auto it : vec)
        {
            int elevation = get<0>(it);
            int row = get<1>(it);
            int col = get<2>(it);
            int node = row * m + col;

            // traverse this node's all four direction
            int delRow[] = {-1, 0, +1, 0};
            int delCol[] = {0, +1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int nr = row + delRow[i];
                int nc = col + delCol[i];
                int adjNode = nr * m + nc;
                if (validLocation(nr, nc, n, m) && grid[nr][nc] <= elevation)
                    dsu.unionByRank(node, adjNode);
            }

            if (dsu.findUParent(0) == dsu.findUParent(n * m - 1))
            {
                return elevation;
            }
        }

        return -1;
    }
};

// m-1: DFS
class Solution
{
public:
    bool validLocation(int row, int col, int n, int m)
    {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    bool possible(int time, vector<vector<int>> &visited, vector<vector<int>> &grid, int row, int col, int n, int m)
    {

        // BASE CASE
        if (row == n - 1 && col == m - 1)
            return true;

        visited[row][col] = 1;
        // traverse all foue direction
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nr = row + delRow[i];
            int nc = col + delCol[i];

            if (validLocation(nr, nc, n, m) && !visited[nr][nc] && grid[row][col] <= time && grid[nr][nc] <= time && possible(time, visited, grid, nr, nc, n, m))
            {

                return true;
            }
        }

        return false;
    }
    int swimInWater(vector<vector<int>> &grid)
    {

        // Binary search on ans using dfs

        int n = grid.size();
        int m = grid[0].size();

        int low = 0, high = (n * m) - 1;

        while (low <= high)
        {

            // find mid
            int mid = low + ((high - low) >> 1);
            vector<vector<int>> visited(n, vector<int>(m, 0));

            if (possible(mid, visited, grid, 0, 0, n, m))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};