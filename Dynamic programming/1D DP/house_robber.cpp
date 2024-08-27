#include <bits/stdc++.h>
using namespace std;

// Recursion
class Solution
{
public:
    int robHelper(vector<int> &nums, int index)
    {

        if (index == 0)
            return nums[0];

        if (index < 0)
            return 0;

        int pickHome = nums[index] + robHelper(nums, index - 2);
        int notPickHome = robHelper(nums, index - 1);

        return max(pickHome, notPickHome);
    }
    int rob(vector<int> &nums)
    {
        int size = nums.size();

        return robHelper(nums, size - 1);
    }
};

// Memorization
class Solution
{
public:
    int robHelper(vector<int> &nums, vector<int> &dp, int index)
    {
        // 2. return directly, not call Recursion
        if (dp[index] != -1)
        {
            return dp[index];
        }

        // 1. base case
        if (index == 0)
            return dp[0] = nums[0];
        if (index == 1)
        {
            return dp[1] = max(nums[0], nums[1]);
        }

        // if (index < 0)
        //     return 0;

        int pickHome = nums[index] + robHelper(nums, dp, index - 2);
        int notPickHome = robHelper(nums, dp, index - 1);

        // 3. if value first time calculate, store in dp;
        return dp[index] = max(pickHome, notPickHome);
    }

    int rob(vector<int> &nums)
    {
        int size = nums.size();

        vector<int> dp(size, -1);

        return robHelper(nums, dp, size - 1);
    }
};

// tabulation
class Solution
{
public:
    int robHelper(vector<int> &nums, vector<int> &dp)
    {
        int size = dp.size();

        // 1. Base case
        dp[0] = nums[0];
        if (size >= 2)
            dp[1] = max(nums[0], nums[1]);

        // 2. fill dp array
        for (int i = 2; i < size; i++)
        {
            int pickHome = nums[i] + dp[i - 2];
            int notPickHome = dp[i - 1];

            dp[i] = max(pickHome, notPickHome);
        }
        // 3. return last index value
        return dp[size - 1];
    }

    int rob(vector<int> &nums)
    {
        int size = nums.size();

        vector<int> dp(size, -1);

        return robHelper(nums, dp);
    }
};

// memory sort Technique
class Solution
{
public:
    int robHelper(vector<int> &nums)
    {
        int size = nums.size();

        if (size == 1)
            return nums[0];
        // 1. Base case
        int pre2 = nums[0];
        int pre1 = max(nums[0], nums[1]);

        // 2. fill dp array
        int curri;
        for (int i = 2; i < size; i++)
        {
            int pickHome = nums[i] + pre2;
            int notPickHome = pre1;

            curri = max(pickHome, notPickHome);

            // update pre2 , pre1
            pre2 = pre1;
            pre1 = curri;
        }
        // 3. return last index value
        return pre1;
    }

    int rob(vector<int> &nums)
    {

        return robHelper(nums);
    }
};

// memory sort Technique
class Solution
{
public:
    int robHelper(vector<int> &nums)
    {
        int size = nums.size();

        if (size == 1)
            return nums[0];
        // 1. Base case
        int pre2 = nums[0];
        int pre1 = max(nums[0], nums[1]);

        // 2. fill dp array
        int curri;
        for (int i = 2; i < size; i++)
        {
            int pickHome = nums[i] + pre2;
            int notPickHome = pre1;

            curri = max(pickHome, notPickHome);

            // update pre2 , pre1
            pre2 = pre1;
            pre1 = curri;
        }
        // 3. return last index value
        return pre1;
    }

    int rob(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> first;
        vector<int> last;

        // first.insert(first.end(), nums.begin(), nums.end() - 1);
        // last.insert(last.end(), nums.begin() + 1, nums.end());

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {

                last.push_back(nums[i]);
            }
            if (i != n - 1)
            {
                first.push_back(nums[i]);
            }
        }

        return max(robHelper(first), robHelper(last));
    }
};