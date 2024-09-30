#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {

        // take indegree Vector
        vector<int> indeg(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indeg[it]++;
            }
        }

        // indegree vector complete

        // take a queue and push 0 indegree node
        queue<int> q;

        for (int i = 0; i < V; i++)
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

        return ans;
    }
    string findOrder(string dict[], int N, int K)
    {
        // create a directed graph adj
        vector<vector<int>> adj(K);

        for (int i = 0; i < N - 1; i++)
        {

            string s1 = dict[i];
            string s2 = dict[i + 1];

            // run loop only min size string
            int len = min(s1.size(), s2.size());

            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {

                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';

                    adj[u].push_back(v);
                    break;
                }
            }
        }

        vector<int> ans = topoSort(K, adj);

        string order = "";
        for (int i = 0; i < ans.size(); i++)
        {
            order = order + char('a' + ans[i]);
        }

        return order;
    }
};