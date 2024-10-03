#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int comp(int val, int level)
    {
        return (3 * (2 << level) - val - 1);
    }
    vector<int> pathInZigZagTree(int label)
    {

        vector<int> ans;

        // find level of that node

        int base = 2;
        int exponent = 0;

        while (label >= (base << exponent))
        {

            exponent++;
        }

        int level = exponent - 1;

        // find path

        ans.push_back(label);
        int val = label;

        while (val != 1)
        {
            // find val complement's parent

            int compval = comp(val, level--);

            int parent = compval / 2;

            ans.push_back(parent);

            val = parent;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};