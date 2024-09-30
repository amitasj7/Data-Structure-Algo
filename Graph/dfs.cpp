#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int node, vector<int> &visited, vector<int> &ans, vector<vector<int>> &edgeslist)
{
    visited[node] = 1;
    ans.push_back(node);

    for (auto it : edgeslist[node])
    {

        if (!visited[it])
        {

            dfsHelper(it, visited, ans, edgeslist);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{

    vector<vector<int>> edgeslist(V);

    for (int i = 0; i < E; i++)
    {

        int firstVertex = edges[i][0];
        int secondVertex = edges[i][1];

        edgeslist[firstVertex].push_back(secondVertex);
        edgeslist[secondVertex].push_back(firstVertex);
    }
    vector<vector<int>> ans;
    vector<int> visited(V, 0);

    int count = 0;

    ans.push_back({0});

    for (int i = 0; i < V; i++)
    {

        if (!visited[i])
        {

            vector<int> component;
            dfsHelper(i, visited, component, edgeslist);
            ans.push_back(component);
            count++;
        }
    }

    ans[0][0] = count;

    return ans;
}

int main()
{
    // int V, E;
    // cout << "Enter the number of vertices (V): ";
    // cin >> V;

    // cout << "Enter the number of edges (E): ";
    // cin >> E;

    // vector<vector<int>> edges(E, vector<int>(2));

    // cout << "Enter the edges (format: u v):" << endl;
    // for (int i = 0; i < E; i++)
    // {
    //     cin >> edges[i][0] >> edges[i][1];
    // }

    vector<vector<int>> edges = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}};
    vector<vector<int>> ans = depthFirstSearch(10, 9, edges);

    cout << "Connected Components:" << endl;
    for (auto v : ans)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
