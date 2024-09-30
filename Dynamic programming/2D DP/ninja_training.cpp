#include <bits/stdc++.h>
using namespace std;

// 1. Recursion

class Solution
{
public:
    int helper(int day, int last, vector<vector<int>> &arr)
    {

        // BASE CASE
        if (day == 0)
        {

            int maxi = 0;
            for (int i = 0; i <= 2; i++)
            {
                if (i == last)
                    continue;

                maxi = max(maxi, arr[0][i]);
            }

            return maxi;
        }

        // LOGIC
        int maxi = 0;
        for (int i = 0; i <= 2; i++)
        {

            if (i == last)
                continue;

            int points = arr[day][i] + helper(day - 1, i, arr);

            maxi = max(maxi, points);
        }

        // RETURN
        return maxi;
    }
    int maximumPoints(vector<vector<int>> &arr, int n)
    {

        return helper(n - 1, 3, arr);
    }
};

// 2. memoization

class Solution
{
public:
    int helper(int day, int last, vector<vector<int>> &dp, vector<vector<int>> &arr)
    {

        // BASE CASE
        if (day == 0)
        {

            int maxi = 0;
            for (int i = 0; i <= 2; i++)
            {
                if (i == last)
                    continue;

                maxi = max(maxi, arr[0][i]);
            }

            return maxi;
        }

        // pre - calculated
        if (dp[day][last] != -1)
        {
            return dp[day][last];
        }
        // LOGIC
        int maxi = 0;
        for (int i = 0; i <= 2; i++)
        {

            if (i == last)
                continue;

            int points = arr[day][i] + helper(day - 1, i, dp, arr);

            maxi = max(maxi, points);
        }

        // RETURN
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>> &arr, int n)
    {

        vector<vector<int>> dp(n, vector<int>(4, -1));
        return helper(n - 1, 3, dp, arr);
    }
};

// 3. Tabulation

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr, int n)
    {

        vector<vector<int>> dp(n, vector<int>(4, 0));

        // BASE CASE
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][1], arr[0][2], arr[0][0]});

        for (int day = 1; day <= n - 1; day++)
        {
            for (int last = 0; last <= 3; last++)
            {

                // LOGIC
                int maxi = 0;
                for (int i = 0; i <= 2; i++)
                {

                    if (i == last)
                        continue;

                    int points = arr[day][i] + dp[day - 1][i];

                    maxi = max(maxi, points);
                }

                // RETURN
                dp[day][last] = maxi;
            }
        }
        int ans = dp[n - 1][3];

        return ans;
    }
};

// 4. memory optimization

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr, int n)
    {

        vector<int> prev(4, 0);

        // BASE CASE
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max({arr[0][1], arr[0][2], arr[0][0]});

        for (int day = 1; day <= n - 1; day++)
        {
            vector<int> curr(4, 0);
            for (int last = 0; last <= 3; last++)
            {

                // LOGIC
                int maxi = 0;
                for (int i = 0; i <= 2; i++)
                {

                    if (i == last)
                        continue;

                    int points = arr[day][i] + prev[i];

                    maxi = max(maxi, points);
                }

                // RETURN
                curr[last] = maxi;
            }

            prev = curr;
        }
        int ans = prev[3];

        return ans;
    }
};