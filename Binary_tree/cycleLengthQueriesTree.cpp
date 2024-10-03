#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lca(int p, int q)
    {

        // divide every step greater value
        while (p != q)
        {
            if (p > q)
            {
                p = p / 2;
            }
            else
            {
                q = q / 2;
            }
        }

        return p;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {

        vector<int> ansHelper;

        for (auto &it : queries)
        {
            int p = it[0];
            int q = it[1];

            int lcaVal = lca(p, q);

            int ans = 1;

            while (p != lcaVal)
            {
                ans++;
                p = p / 2;
            }

            while (q != lcaVal)
            {
                ans++;
                q = q / 2;
            }

            ansHelper.push_back(ans);
        }

        return ansHelper;
    }
};
