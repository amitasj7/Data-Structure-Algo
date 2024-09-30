#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int index, int n, vector<int> &arr, int k)
    {
        // Base Case
        if (index == n)
            return 0;

        // Logic
        int len = 0;
        int maxEle = -1;
        int maxiSum = -1;
        for (int j = index; j < min(n, index + k); j++)
        {
            len++;

            maxEle = max(maxEle, arr[j]);

            // find sum
            int sum = (len * maxEle) + helper(j + 1, n, arr, k);

            // find max sum
            maxiSum = max(maxiSum, sum);
        }

        // return
        return maxiSum;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {

        int n = arr.size();

        int ans = helper(0, n, arr, k);
        return ans;
    }
};

// Memo
class Solution
{
public:
    int helper(int index, vector<int> &dp, int n, vector<int> &arr, int k)
    {
        // Base Case
        if (index == n)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        // Logic
        int len = 0;
        int maxEle = -1;
        int maxiSum = -1;
        for (int j = index; j < min(n, index + k); j++)
        {
            len++;

            maxEle = max(maxEle, arr[j]);

            // find sum
            int sum = (len * maxEle) + helper(j + 1, dp, n, arr, k);

            // find max sum
            maxiSum = max(maxiSum, sum);
        }

        // return
        return dp[index] = maxiSum;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {

        int n = arr.size();

        vector<int> dp(n, -1);

        int ans = helper(0, dp, n, arr, k);
        return ans;
    }
};

// tabulation


class Solution
{
public:
   
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {

        int n = arr.size();

        vector<int> dp(n + 1, 0);

        // Base Case Already fill with 0
        // if (index == n)
        //     return 0;

        for (int index = n - 1; index >= 0; index--)
        {

            // Logic
            int len = 0;
            int maxEle = -1;
            int maxiSum = -1;
            for (int j = index; j < min(n, index + k); j++)
            {
                len++;

                maxEle = max(maxEle, arr[j]);

                // find sum
                int sum = (len * maxEle) + dp[j + 1];

                // find max sum
                maxiSum = max(maxiSum, sum);
            }

            // return
            dp[index] = maxiSum;
        }

        int ans = dp[0];
        return ans;
    }
};