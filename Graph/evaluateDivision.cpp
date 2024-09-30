#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    auto buildGraph(vector<vector<string>> &equations, vector<double> &values)
    {
        unordered_map<string, unordered_map<string, double>> graph;

        // traverse all equations
        int n = equations.size();

        for (int i = 0; i < n; i++)
        {
            string dividend = equations[i][0];
            string divisor = equations[i][1];

            double value = values[i];

            // map divdend to
            graph[dividend][divisor] = value;
            graph[divisor][dividend] = 1.0 / value;
        }

        return graph;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        unordered_map<string, unordered_map<string, double>> graph = buildGraph(equations, values);

        vector<double> ans;

        for (auto &it : queries)
        {
            string dividend = it[0];
            string divisor = it[1];

            // if dividend or divisor not found
            if (graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end())
                ans.push_back(-1.0);

            else
            {

                unordered_set<string> visited;
                double cal = -1.0, tempCal = 1.0;
                dfs(dividend, divisor, graph, cal, tempCal, visited);

                ans.push_back(cal);
            }
        }

        return ans;
    }
    void dfs(string start, string end, auto &graph, double &cal, double tempCal, auto &visited)
    {
        if (visited.find(start) != visited.end())
            return;

        // mark visited
        visited.insert(start);

        // if find last value divisor
        if (start == end)
        {
            cal = tempCal;
            return;
        }
        // traverse all neighbours

        for (auto it : graph[start])
        {

                        dfs(it.first, end, graph, cal, tempCal * it.second, visited);
        }
    }
};