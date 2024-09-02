#include <bits/stdc++.h>
using namespace std;

/* 
Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 */
class Solution
{
public:
    int helper(int index, int amount, vector<int> &coins)
    {

        // complete divide return 1 otherwise 0;
        if (index == 0)
        {
            return (amount % coins[0] == 0);
        }

        int notTake = helper(index - 1, amount, coins);

        int take = 0;

        if (coins[index] <= amount)
        {
            take = helper(index, amount - coins[index], coins);
        }

        return notTake + take;
    }
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();

        int ans = helper(n - 1, amount, coins);

        return ans;
    }
};

// Memorization

class Solution
{
public:
    int helper(int index, int amount, vector<int> &coins, vector<vector<int>> dp)
    {
        // base case

        // complete divide return 1 otherwise 0;
        if (index == 0)
        {
            return (amount % coins[0] == 0);
        }

        if (dp[index][amount] != -1)
            return dp[index][amount];

        // Logic
        int notTake = helper(index - 1, amount, coins, dp);

        int take = 0;

        if (coins[index] <= amount)
        {
            take = helper(index, amount - coins[index], coins, dp);
        }
        // return
        return dp[index][amount] = notTake + take;
    }
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = helper(n - 1, amount, coins, dp);

        return ans;
    }
};

// Tabulation
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // index 0 fill // Base Case
        for (int i = 0; i <= amount; i++)
        {
            dp[0][i] = (i % coins[0] == 0);
        }

        for (int index = 1; index < n; index++)
        {
            for (int i = 0; i <= amount; i++)
            {
                int notTake = dp[index - 1][i];

                int take = 0;

                if (coins[index] <= i)
                {
                    take = dp[index][i - coins[index]];
                }
                dp[index][i] = notTake + take;
            }
        }

        int ans = dp[n - 1][amount];

        return ans;
    }
};

// Space optimization

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();

        vector<int> prev(amount + 1, 0), current(amount + 1, 0);

        // index 0 fill // Base Case
        for (int i = 0; i <= amount; i++)
        {
            prev[i] = (i % coins[0] == 0);
        }

        for (int index = 1; index < n; index++)
        {
            for (int i = 0; i <= amount; i++)
            {
                int notTake = prev[i];

                int take = 0;

                if (coins[index] <= i)
                {
                    take = current[i - coins[index]];
                }
                current[i] = notTake + take;
            }

            prev = current;
        }

        int ans = prev[amount];

        return ans;
    }
};
