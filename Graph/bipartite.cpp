#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfsColor(vector<vector<int>> &graph, int currentNode, vector<int> &color, int parentColor)
    {

        color[currentNode] = !parentColor;

        // check adjacent vertex
        for (auto it : graph[currentNode])
        {

            if (color[currentNode] == color[it])
            {
                return false;
            }
            if (color[it] == -1 && dfsColor(graph, it, color, !parentColor) == false)
            {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {

        int nodes = graph.size();

        // take a color vector -- 0/1
        vector<int> color(nodes, -1);

        for (int i = 0; i < nodes; i++)
        {

            if (color[i] == -1 && dfsColor(graph, i, color, 1) == false)
            {
                return false;
            }
        }

        return true;
    }
};