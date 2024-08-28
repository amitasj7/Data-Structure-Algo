#include <bits/stdc++.h>
using namespace std;



// https://leetcode.com/problems/jump-game-ii/description/
// Leetcode 45

class Solution
{
public:
    int helper(int ind, vector<int> &nums, vector<int> &dp)
    {

        // BASE CASE
        if (ind >= nums.size() - 1)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int minJump = INT_MAX-5;  // if for loop nahi chala tab 1 +  minJump Int me store nahi hoga . 
        // LOGIC
        for (int jump = 1; jump <= nums[ind]; jump++)
        {

            int j = helper(ind + jump, nums, dp);

            minJump = min(minJump, j);
        }

        return dp[ind] = 1 + minJump;
    }
    int jump(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return helper(0, nums, dp);
    }
};