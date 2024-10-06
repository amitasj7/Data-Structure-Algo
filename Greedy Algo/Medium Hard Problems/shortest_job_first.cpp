#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        long long time = 0;
        long long wt = 0;
        long long n = bt.size();

        // sort the bt
        sort(bt.begin(), bt.end());

        for (long long i = 0; i < bt.size(); i++)
        {

            wt += time;

            time += bt[i];
        }
        long long avgWT = wt / n;

        return avgWT;
    }
};
