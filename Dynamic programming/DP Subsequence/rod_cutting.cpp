#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
class Solution
{
public:
    int helper(int ind, int totalrodLen, vector<int> &price)
    {
        // BASE CASE
        if (ind == 0)
        {
            // index == 0 mtlb rod ko 1 , 1 ke piece me katna hai. totalpieces = totalrodLen/1;
            return price[0] * totalrodLen;
        }

        // LOGIC
        int not_cut = helper(ind - 1, totalrodLen, price);

        int cutPiece = ind + 1; // index 0 se start hai jabki rod ko minimum 1 piece me katna hi hai
        int cut = 0;
        if (cutPiece <= totalrodLen)
        {
            cut = price[ind] + helper(ind, totalrodLen - cutPiece, price); // if cut krege to price leni hogi
        }

        // RETURN

        return max(not_cut, cut);
    }
    int cutRod(vector<int> &price, int n)
    {
        // Write your code here.

        return helper(n - 1, n, price);
    }
};

// 2. Memoization
class Solution
{
public:
    int helper(int ind, int totalrodLen, vector<vector<int>> &dp, vector<int> &price)
    {
        // BASE CASE
        if (ind == 0)
        {
            // index == 0 mtlb rod ko 1 , 1 ke piece me katna hai. totalpieces = totalrodLen/1;
            return price[0] * totalrodLen;
        }

        // pre - calculated
        if (dp[ind][totalrodLen] != -1)
        {
            return dp[ind][totalrodLen];
        }
        // LOGIC
        int not_cut = helper(ind - 1, totalrodLen, dp, price);

        int cutPiece = ind + 1; // index 0 se start hai jabki rod ko minimum 1 piece me katna hi hai
        int cut = 0;
        if (cutPiece <= totalrodLen)
        {
            cut = price[ind] + helper(ind, totalrodLen - cutPiece, dp, price); // if cut krege to price leni hogi
        }

        // RETURN

        return dp[ind][totalrodLen] = max(not_cut, cut);
    }
    int cutRod(vector<int> &price, int n)
    {
        // Write your code here.

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(n - 1, n, dp, price);
    }
};

// 3. Tabulation
class Solution
{
public:
    int cutRod(vector<int> &price, int n)
    {
        // Write your code here.
        int rodlen = n;
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        // BASE CASE

        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = price[0] * i; // piece har ith value par cahnge ho rahe hai
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int totalrodLen = 0; totalrodLen <= n; totalrodLen++)
            {
                // LOGIC
                int not_cut = dp[ind - 1][totalrodLen];

                int cutPiece = ind + 1; // index 0 se start hai jabki rod ko minimum 1 piece me katna hi hai
                int cut = 0;
                if (cutPiece <= totalrodLen)
                {
                    cut = price[ind] + dp[ind][totalrodLen - cutPiece]; // if cut krege to price leni hogi
                }

                // RETURN

                dp[ind][totalrodLen] = max(not_cut, cut);
            }
        }

        int ans = dp[n - 1][n];
        return ans;
    }
};

// 4. Space optimization
class Solution
{
public:
    int cutRod(vector<int> &price, int n)
    {
        // Write your code here.

        vector<int> prev(n + 1, 0);
        // BASE CASE

        for (int i = 0; i <= n; i++)
        {
            prev[i] = price[0] * i; // piece har ith value par cahnge ho rahe hai
        }

        for (int ind = 1; ind < n; ind++)
        {
            vector<int> curr(n + 1, 0);
            for (int totalrodLen = 0; totalrodLen <= n; totalrodLen++)
            {
                // LOGIC
                int not_cut = prev[totalrodLen];

                int cutPiece = ind + 1; // index 0 se start hai jabki rod ko minimum 1 piece me katna hi hai
                int cut = 0;
                if (cutPiece <= totalrodLen)
                {
                    cut = price[ind] + curr[totalrodLen - cutPiece]; // if cut krege to price leni hogi
                }

                // RETURN

                curr[totalrodLen] = max(not_cut, cut);
            }
            prev = curr;
        }

        int ans = prev[n];
        return ans;
    }
};

// 4. Space optimization 1-D Array
class Solution
{
public:
    int cutRod(vector<int> &price, int n)
    {
        // Write your code here.

        vector<int> prev(n + 1, 0);
        // BASE CASE

        for (int i = 0; i <= n; i++)
        {
            prev[i] = price[0] * i; // piece har ith value par cahnge ho rahe hai
        }

        for (int ind = 1; ind < n; ind++)
        {

            for (int totalrodLen = 0; totalrodLen <= n; totalrodLen++)
            {
                // LOGIC
                int not_cut = prev[totalrodLen];

                int cutPiece = ind + 1; // index 0 se start hai jabki rod ko minimum 1 piece me katna hi hai
                int cut = 0;
                if (cutPiece <= totalrodLen)
                {
                    cut = price[ind] + prev[totalrodLen - cutPiece]; // if cut krege to price leni hogi
                }

                // RETURN

                prev[totalrodLen] = max(not_cut, cut);
            }
        }

        int ans = prev[n];
        return ans;
    }
};
