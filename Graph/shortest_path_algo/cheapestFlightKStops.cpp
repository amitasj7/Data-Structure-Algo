
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {

        vector<int> costVec(n, INT16_MAX);

        // create a adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto f : flights)
        {
            int u = f[0];
            int v = f[1];
            int cost = f[2];

            adj[u].push_back({v, cost});
        }

        // take a queue
        // <stops,city,cost>
        queue<vector<int>> q;
        q.push({0, src, 0});

        costVec[src] = 0;

        while (!q.empty())
        {
            int stops = q.front()[0];
            int city = q.front()[1];
            int cost = q.front()[2];
            q.pop();

            // take adject cities
            for (auto it : adj[city])
            {
                int newCity = it.first;
                int newCost = it.second;

                int totalCost = cost + newCost;

                if (totalCost < costVec[newCity] && stops + 1 <= k + 1)
                {
                    // update costVec
                    costVec[newCity] = totalCost;
                    // push into queue
                    q.push({stops + 1, newCity, totalCost});
                }
            }
        }

        // No Path available
        if (costVec[dst] >= INT16_MAX)
        {
            costVec[dst] = -1;
        }

        return costVec[dst];
    }
};