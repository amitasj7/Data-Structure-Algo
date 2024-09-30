#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> safeNode;

        // reverse all edges
        int totalNodes = graph.size();

        vector<vector<int>> adjRev(totalNodes);

        for (int i = 0; i < totalNodes; i++)
        {
            for (auto j : graph[i])
            {
                adjRev[j].push_back(i);
            }
        }

            // for (int i = 0; i < totalNodes; i++)
            // {
            //     for (auto j : graph[i])
            //     {
            //         // add a reverse edges
            //         graph[j].push_back(i);

            //         // remove previous edge
                    // auto it = find(graph[i].begin(), graph[i].end(), j);
                    // if(it != graph[i].end)
                    // graph[i].erase(it);
            //     }
            // }

            // take indegree Vector
            vector<int> indeg(totalNodes, 0);

            for (int i = 0; i < totalNodes; i++)
            {
                for (auto it : adjRev[i])
                {
                    indeg[it]++;
                }
            }

            // indegree vector complete

            queue<int> q;

            for (int i = 0; i < totalNodes; i++)
            {
                if (indeg[i] == 0)
                {
                    q.push(i);
                }
            }

            while (!q.empty())
            {

                int node = q.front();
                q.pop();

                // put into safeNode ;
                safeNode.push_back(node);

                for (auto it : adjRev[node])
                {
                    indeg[it]--;
                    if (indeg[it] == 0)
                    {
                        // push into queue
                        q.push(it);
                    }
                }
            }

            sort(safeNode.begin() , safeNode.end());

            return safeNode;
        }
    };