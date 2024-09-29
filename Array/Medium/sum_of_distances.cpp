#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> distance(vector<int> &nums)
    {
        int n = nums.size();

        vector<long long> ans(n, 0);

        // take left to right
        // <element, indexSumPrefix, freq>
        map<int, pair<long long, int>> mp;

        for (int i = 0; i < n; i++)
        {
            int element = nums[i];
            long long prefixSum = mp[element].first;
            int fre = mp[element].second;

            ans[i] += (long long)(i * (long long)fre) - (prefixSum);

            // update mp
            mp[element].first += i;
            mp[element].second++;
        }

        mp.clear();

        // take right to left SuffixSum
        for (int i = n - 1; i >= 0; i--)
        {
            int element = nums[i];
            long long SuffixSum = mp[element].first;
            int fre = mp[element].second;

            // phle wala ans + new wala right to left
            ans[i] += SuffixSum - (long long)((long long)fre * i);

            // update mp
            mp[element].first += i;
            mp[element].second++;
        }

        return ans;
    }
};
// Input: nums = [1,3,1,1,2]
// Output: [5,0,3,4,0]
class Solution
{
public:
    vector<long long> distance(vector<int> &nums)
    {

        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mp;

        // store all index value in vector
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        for (auto it : mp)
        {
            int n2 = it.second.size();
            if (n2 == 1)
            {
                continue;
            }

            for (int i = 0; i < n2; i++)
            {
                int index = it.second[i];

                long long sum = 0;
                for (int j = 0; j < n2; j++)
                {
                    sum += (long long)(abs(index - it.second[j]));
                }
                ans[index] = sum;
            }
        }
        return ans;
    }
};