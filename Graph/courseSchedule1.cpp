#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        // create a adjList
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        // take indegree Vector
        vector<int> indeg(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            for (auto it : adj[i])
            {
                indeg[it]++;
            }
        }

        // indegree vector complete

        // take a queue and push 0 indegree node
        queue<int> q;

        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty())
        {

            int value = q.front();
            q.pop();

            ans.push_back(value);

            for (auto it : adj[value])
            {

                indeg[it]--;
                if (indeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return ans.size() == numCourses;
    }
};