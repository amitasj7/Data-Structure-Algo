#include<bits/stdc++.h>
using namespace std; 



// https://leetcode.com/problems/jump-game/
// leetcode 55

class Solution {
public:
    bool helper(int ind, vector<int>& nums, vector<int>& dp) {

        // BASE CASE
        if (ind >= nums.size() - 1)
            return true;

        if (dp[ind] != -1)
            return dp[ind];

        // LOGIC
        for (int jump = 1; jump <= nums[ind]; jump++) {

            int possible = helper(ind + jump, nums, dp);

            if (possible)
                return dp[ind] = true;
        }

        return dp[ind] = false;
    }

    bool canJump(vector<int>& nums) {
        // if(nums.size() == 1) return true;

        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return helper(0, nums, dp);
    }
};