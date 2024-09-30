#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // create a adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto f : roads)
        {
            int u = f[0];
            int v = f[1];
            int time = f[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        vector<long long> timeVec(n, INT64_MAX);
        vector<long long> ways(n, 0);
        int mod = (int)(pow(10, 9) + 7);

        // take a minHeap
        // <time,node>
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

        pq.push({0, 0});
        timeVec[0] = 0;
        ways[0] = 1;

        while (!pq.empty())
        {
            long long time = pq.top().first;
            long long city = pq.top().second;
            pq.pop(); // it's important

            for (auto it : adj[city])
            {
                int newCity = it.first;
                int takenTime = it.second;

                long long totalTime = (long long)(time + (long long)takenTime);

                if (totalTime < timeVec[newCity])
                {
                    // update time list
                    timeVec[newCity] = totalTime;

                    // update ways
                    ways[newCity] = ways[city] % mod;

                    // push into minHeap
                    pq.push({totalTime, newCity});
                }
                else if (totalTime == timeVec[newCity])
                {
                    // update ways
                    ways[newCity] = (ways[newCity] + ways[city]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};