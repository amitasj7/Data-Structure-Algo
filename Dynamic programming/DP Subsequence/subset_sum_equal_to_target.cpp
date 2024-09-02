#include <bits/stdc++.h>
using namespace std;

// 1. Recursion (include 0)
class Solution
{
public:
    bool helper1(int index, int target, vector<int> &nums)
    {
        // BASE CASE
        if (target == 0)
            return true;
        if (index == 0)
            return nums[index] == target;

        // LOGIC
        bool notPick = helper1(index - 1, target, nums);
        if (notPick)
            return true; // aage ke tree par checking nahi krni hai

        bool pick = false; // abhi possible nahi hai isliye false de diya hia
        if (nums[index] <= target)
        {

            pick = helper1(index - 1, target - nums[index], nums);
        }
        if (pick)
            return true; // aage ki checking nahi krni hai

        // RETURN

        return pick || notPick;
    }
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();

        return helper1(n - 1, sum, arr);
    }
};

// 2. Memoization (include 0)
class Solution
{
public:
    bool helper1(int index, int target, vector<vector<int>> &dp, vector<int> &nums)
    {
        // BASE CASE
        if (target == 0)
            return true;
        if (index == 0)
            return nums[index] == target;

        // Pre - calculated
        if (dp[index][target] != -1)
            return dp[index][target];

        // LOGIC
        bool notPick = helper1(index - 1, target, dp, nums);
        if (notPick)
            return dp[index][target] = true; // aage ke tree par checking nahi krni hai

        bool pick = false; // abhi possible nahi hai isliye false de diya hia
        if (nums[index] <= target)
        {

            pick = helper1(index - 1, target - nums[index], dp, nums);
        }
        if (pick)
            return dp[index][target] = true; // aage ki checking nahi krni hai

        // RETURN

        return dp[index][target] = pick || notPick;
    }
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return helper1(n - 1, sum, dp, arr);
    }
};

// 3. Tabulation(include 0)
class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        // BASE CASE
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if (arr[0] <= sum) // agar 0th element sum se bda nikal gya to dp me cell nahi milegi
            dp[0][arr[0]] = true;

        for (int index = 1; index < n; index++)
        {
            for (int target = 1; target <= sum; target++)
            {
                // LOGIC
                bool notPick = dp[index - 1][target];

                bool pick = false; // abhi possible nahi hai isliye false de diya hia
                if (arr[index] <= target)
                {

                    pick = dp[index - 1][target - arr[index]];
                }

                // RETURN

                dp[index][target] = pick || notPick;
            }
        }

        bool ans = dp[n - 1][sum];

        return ans;
    }
};

// 4. Space Optimization (include 0)

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<int> prev(sum + 1, 0);

        prev[0] = true;
        if (arr[0] <= sum) // agar 0th element sum se bda nikal gya to dp me cell nahi milegi
            prev[arr[0]] = true;

        for (int index = 1; index < n; index++)
        {
            vector<int> curr(sum + 1, 0);
            curr[0] = true;

            for (int target = 1; target <= sum; target++)
            {
                // LOGIC
                bool notPick = prev[target];

                bool pick = false; // abhi possible nahi hai isliye false de diya hia
                if (arr[index] <= target)
                {

                    pick = prev[target - arr[index]];
                }

                // RETURN

                curr[target] = pick || notPick;
            }
            prev = curr;
        }

        bool ans = prev[sum];

        return ans;
    }
};


class Solution
{
public:
    // 1. Recursion
    bool helper1(int index, int target, vector<int> &nums)
    {

        // Base Case

        if (target == 0)
            return true;

        if (index == 0)
            return nums[0] == target;

        bool notPick = helper1(index - 1, target, nums);

        // agar Element target se bda hua to pick nahi krna hai so initially hi pick me false de dege
        bool pick = false;

        if (nums[index] <= target)
        {
            pick = helper1(index - 1, target - nums[index], nums);
        }
        return pick || notPick;
    }

    // 2. Memoization
    bool helper(int index, int target, vector<vector<int>> &dp, vector<int> &nums)
    {

        // Base Case

        if (target == 0)
            return true;

        if (index == 0)
            return nums[0] == target;

        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        bool notPick = helper(index - 1, target, dp, nums);

        // agar Element target se bda hua to pick nahi krna hai so initially hi pick me false de dege
        bool pick = false;

        if (nums[index] <= target)
        {
            pick = helper(index - 1, target - nums[index], dp, nums);
        }
        return dp[index][target] = pick || notPick;
    }
    bool canPartition(vector<int> &nums)
    {

        // find total Sum

        int totalSum = 0;

        for (auto it : nums)
        {
            totalSum += it;
        }

        // Even - > check for taget =  totalSum/2 ;
        if (totalSum % 2 == 0)
        {
            int target = totalSum / 2;
            int n = nums.size();

            // take a 2D DP
            vector<vector<int>> dp(n, vector<int>(target + 1, -1));

            return helper(n - 1, target, dp, nums);
        }
        return false;
    }
};