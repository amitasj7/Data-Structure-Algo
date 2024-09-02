#include <bits/stdc++.h>
using namespace std;

// 4. Space optimization include 0
class Solution
{

public:
    const int MOD = 1e9 + 7;

    int countPartitions(int n, int d, vector<int> &arr)
    {

        int totalSum = 0;
        // find total sum
        for (int val : arr)
        {
            totalSum += val;
        }

        // find total set with sum s1 = (totalSum - d) / 2;
        if (totalSum - d < 0 || (totalSum - d) & 1)
            return 0;

        int s1 = (totalSum - d) / 2;

        int ans = perfectSum(arr, n, s1);
        return ans;
    }

    int perfectSum(vector<int> &arr, int n, int sum)
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