#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto f : times)
        {
            int u = f[0];
            int v = f[1];
            int time = f[2];

            adj[u].push_back({v, time});
            // <city,time>
        }

        vector<int> timeVec(n + 1, INT16_MAX);

        // take a minHeap
        // <time, city>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        timeVec[k] = 0;

        while (!pq.empty())
        {
            int time = pq.top().first;
            int city = pq.top().second;
            pq.pop();

            for (auto it : adj[city])
            {
                int newCity = it.first;
                int takenTime = it.second;

                int totalTime = time + takenTime;

                if (totalTime < timeVec[newCity])
                {
                    timeVec[newCity] = totalTime;
                    // push into minHeap
                    pq.push({totalTime, newCity});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i < timeVec.size(); i++)
        {
            if (timeVec[i] >= INT16_MAX)
            {
                return -1;
            }
            maxTime = max(maxTime, timeVec[i]);
        }

        return maxTime;
    }
};