#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());  // step - 1

        int n = nums.size();
        vector<int> dp(n, 1);

        int ans = 0;
        int lastIndex = 0;
        vector<int> hash(n, 0);
        for (int i = 0; i < ans; i++)
        {
            hash[i] = i;
        }

        for (int current = 0; current < n; current++)
        {
            // fill current element longest incresing subsequence
            for (int prev = 0; prev < current; prev++)
            {

                if (nums[current] % nums[prev] == 0 && 1 + dp[prev] > dp[current]) // step - 2
                {
                    // update current length
                    dp[current] = 1 + dp[prev];
                    hash[current] = prev;
                }
            }

            if (ans < dp[current])
            {
                ans = dp[current];
                lastIndex = current;
            }
        }
        vector<int> ansVec;
        ansVec.push_back(nums[lastIndex]);

        // fill ans Vec
        while (hash[lastIndex] != lastIndex)
        {
            // update lastindex
            lastIndex = hash[lastIndex];

            // fill ansvec
            ansVec.push_back(nums[lastIndex]);
        }

        reverse(ansVec.begin(), ansVec.end());

        return ansVec;
    }
};