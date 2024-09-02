#include <bits/stdc++.h>
using namespace std;

/*
problem link -
https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

Given an array arr of size n of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7.

Examples:

Input:
n = 6, arr = [5, 2, 3, 10, 6, 8], sum = 10
Output:
3
Explanation:
{5, 2, 3}, {2, 8}, {10} are possible subsets.
Input:
n = 5, arr = [2, 5, 1, 4, 3], sum = 10
Output:
3
Explanation:
{2, 1, 4, 3}, {5, 1, 4}, {2, 5, 3} are possible subsets.

Expected Time Complexity: O(n*sum)
Expected Auxiliary Space: O(n*sum)

Constraints:
1 ≤ n*sum ≤ 106
0 ≤ arr[i] ≤ 106  // Note - Including with 0

*/

// 1. Recursion include 0
class Solution
{

public:
    const int MOD = 1e9 + 7;
    int helper(int ind, int target, int arr[])
    {
        // BASE CASE

        if (ind == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            else if (target == 0 || target == arr[0])
                return 1;
            else
                return 0;
        }

        // LOGIC

        int not_Pick = helper(ind - 1, target, arr);

        int pick = 0;
        if (arr[ind] <= target)
        {
            pick = helper(ind - 1, target - arr[ind], arr);
        }

        // RETURN
        return not_Pick + pick;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        return helper(n - 1, sum, arr);
    }
};

// 2. Memoization include 0
class Solution
{

public:
    const int MOD = 1e9 + 7;
    int helper(int ind, int target,
               vector<vector<int>> &dp, int arr[])
    {
        // BASE CASE

        if (ind == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            else if (target == 0 || target == arr[0])
                return 1;
            else
                return 0;
        }

        // pre - calculated
        if (dp[ind][target] != -1)
            return dp[ind][target];
        // LOGIC

        int not_Pick = helper(ind - 1, target, dp, arr);

        int pick = 0;
        if (arr[ind] <= target)
        {
            pick = helper(ind - 1, target - arr[ind], dp, arr);
        }

        // RETURN
        return dp[ind][target] = (not_Pick + pick) % MOD;
    }
    int perfectSum(int arr[], int n, int sum)
    {

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helper(n - 1, sum, dp, arr);
    }
};

// 3. Tabulation include 0
class Solution
{

public:
    const int MOD = 1e9 + 7;

    int perfectSum(int arr[], int n, int sum)
    {

        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        // BASE CASE

        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (arr[0] != 0 && arr[0] <= sum) // 0th element 1 to sum ke beech me hona chaiye to vo take kiya jaiga
            dp[0][arr[0]] = 1;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= sum; target++)
            {
                // LOGIC

                int not_Pick = dp[ind - 1][target];

                int pick = 0;
                if (arr[ind] <= target)
                {
                    pick = dp[ind - 1][target - arr[ind]];
                }

                // RETURN
                dp[ind][target] = (not_Pick + pick) % MOD;
            }
        }

        int ans = dp[n - 1][sum];
        return ans;
    }
};

// 4. Space optimization include 0
class Solution
{

public:
    const int MOD = 1e9 + 7;

    int perfectSum(int arr[], int n, int sum)
    {

        vector<int> prev(sum + 1, 0);

        // BASE CASE

        if (arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (arr[0] != 0 && arr[0] <= sum) // 0th element 1 to sum ke beech me hona chaiye to vo take kiya jaiga
            prev[arr[0]] = 1;

        for (int ind = 1; ind < n; ind++)
        {
            vector<int> curr(sum + 1, 0);
            for (int target = 0; target <= sum; target++)
            {
                // LOGIC

                int not_Pick = prev[target];

                int pick = 0;
                if (arr[ind] <= target)
                {
                    pick = prev[target - arr[ind]];
                }

                // RETURN
                curr[target] = (not_Pick + pick) % MOD;
            }
            prev = curr;
        }

        int ans = prev[sum];
        return ans;
    }
};