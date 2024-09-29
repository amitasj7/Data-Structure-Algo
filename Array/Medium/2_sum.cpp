#include <bits/stdc++.h>
using namespace std;

// Hashmap
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> map; // <element,ind>

        for (int i = 0; i < nums.size(); i++)
        {

            int ele = nums[i];

            if (map.find(target - ele) != map.end())
            {
                return {map[target- ele], i};
            }

            map.insert({ele, i});
        }

        return {-1, -1};
    }
};