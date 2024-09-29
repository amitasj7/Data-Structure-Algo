#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        // take set data structure
        unordered_set<int> s;

        for (auto &it : nums)
        {
            s.insert(it);
        }

        // traverse set
        int longest = 1;

        for (auto &it : s)
        {

            // it = 100 then find 99 and 99 nahi  mila then yahi 100 hi sequence ka starting element hai
            if (s.find(it - 1) == s.end())
            {

                int ele = it;
                int count = 1;

                while (s.find(ele + 1) != s.end())
                {
                    count += 1;
                    ele += 1;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};