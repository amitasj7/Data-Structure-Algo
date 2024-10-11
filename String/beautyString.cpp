#include <bits/stdc++.h>
using namespace std;

int beautySum(string s)
{
    // find substrings

    int sum = 0;

    for (int i = 0; i < s.length(); i++)
    {
        unordered_map<char, int> mp;
        for (int j = i; j < s.length(); j++)
        {
            mp[s[j]]++;

            // find min and max frequency
            vector<int> vec;
            for (auto p : mp)
            {
                vec.push_back(p.second);
            }

            // sort vector with key according
            sort(vec.begin(), vec.end());

            sum += vec.back() - vec[0];
        }
    }

    return sum;
}
