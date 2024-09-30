#include <bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
 */
class Solution
{

    // vector<unordered_set<int>> vec;
    int ans = 0;
    vector<int> store;

public:
    void helper(int index, vector<int> &nums, int k)
    {

        // BASE CASE
        if (index == nums.size())
        {
            if (!store.empty())
                ans++;
            // vec.push_back(store);
            return;
        }

        // LOGIC
        //  take element
        int element = nums[index];

        if (find(store.begin(), store.end(), element + k) == store.end() && find(store.begin(), store.end(), element - k) == store.end())
        { // not find then take it
            store.push_back(element);
            helper(index + 1, nums, k);

            // remove element
            store.pop_back();
        }

        // not take element
        helper(index + 1, nums, k);

        // RETURN
    }
    int beautifulSubsets(vector<int> &nums, int k)
    {

        helper(0, nums, k);
        // only  vec ko fill krna hai
        return ans;
    }
};