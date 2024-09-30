#include <bits/stdc++.h>
using namespace std;

void dfsTopoSort(vector<vector<int>> &graph, vector<int> &visited, stack<int> &st, int currentNode)
{

    visited[currentNode] = 1;

    for (auto it : graph[currentNode])
    {
        if (!visited[it])
        {
            dfsTopoSort(graph, visited, st, it);
        }
    }

    st.push(currentNode);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{

    vector<int> ans;
    // Write your code here!
    vector<int> visited(nodes, 0);

    // take a stack
    stack<int> st;

    for (int i = 0; i < nodes; i++)
    {

        if (!visited[i])
        {
            dfsTopoSort(graph, visited, st, i);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());

        st.pop();
    }

    return ans;
}
int main()
{

    // vector<vector<int>> graph = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    vector<vector<int>> graph = {{2, 4}, {2}, {}, {1}, {}};

    vector<int> topoSort = topologicalSort(graph, 4, 5);

    for (auto it : topoSort)
    {
        cout << it << " ";
    }
}