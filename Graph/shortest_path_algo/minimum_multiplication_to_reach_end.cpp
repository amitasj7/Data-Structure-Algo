
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 100000;
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {

        if(start == end) return 0; 

        queue<vector<int>> q;
        vector<int> operation(mod, 1e9);

        q.push({0, start}); // <mini operatoin, value>
        operation[start] = 0;

        while (!q.empty())
        {

            int ope = q.front()[0];
            int value = q.front()[1];
            q.pop();

            for (int it : arr)
            {
                int next = (value * it) % mod;

                if (1 + ope < operation[next])
                {

                    if (next == end)
                        return ope + 1;

                    operation[next] = 1 + ope;
                    q.push({ope + 1, next});
                }
            }
        }

        return -1;
    }
};