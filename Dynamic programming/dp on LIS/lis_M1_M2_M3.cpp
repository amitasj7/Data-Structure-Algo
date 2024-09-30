#include <bits/stdc++.h>
using namespace std;

/*
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

// M-1 :
// 1. Recursion

class Solution1
{
public:
    int helper(int ind, int prev_ind, vector<int> &nums, int n)
    {
        // BASE CASE

        if (ind == n) // element nahi hoga to take and notTake koi bhi possible nahi hoga
            return 0;

        // LOGIC
        int not_take = 0 + helper(ind + 1, prev_ind, nums, n);
        int take = 0;

        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) // 0th element ke liye prev == -1 // strictly greater than
        {
            take = 1 + helper(ind + 1, ind, nums, n);
        }

        // RETURN
        return max(not_take, take);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return helper(0, -1, nums, n);
    }
};

// 2. Memoization

class Solution2
{
public:
    int helper(int ind, int prev_ind, vector<vector<int>> &dp, vector<int> &nums, int n)
    {
        // BASE CASE

        if (ind == n) // element nahi hoga to take and notTake koi bhi possible nahi hoga
            return 0;

        // pre - calculate
        if (dp[ind][prev_ind + 1] != -1)
        {
            return dp[ind][prev_ind + 1];
        }
        // LOGIC
        int not_take = 0 + helper(ind + 1, prev_ind, dp, nums, n);
        int take = 0;

        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) // 0th element ke liye prev == -1 // strictly greater than
        {
            take = 1 + helper(ind + 1, ind, dp, nums, n);
        }

        // RETURN
        return dp[ind][prev_ind + 1] = max(not_take, take);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(0, -1, dp, nums, n);
    }
};

// 3. Tabulation

class Solution3
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // BASE CASE

        // already fill with 0

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
            {
                // LOGIC
                int not_take = 0 + dp[ind + 1][prev_ind + 1];
                int take = 0;

                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) // 0th element ke liye prev == -1 // strictly greater than
                {
                    take = 1 + dp[ind + 1][ind + 1]; // dp me se call krte time durse box me ek increase kar dege
                }

                // RETURN
                dp[ind][prev_ind + 1] = max(not_take, take);
            }
        }

        int ans = dp[0][0];
        return ans;
    }
};

// 3.2 Tabulation type 2:

class Solution4
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // BASE CASE

        // already fill with 0

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind; prev_ind >= 0; prev_ind--)
            {
                // LOGIC
                int not_take = 0 + dp[ind + 1][prev_ind];
                int take = 0;

                if (prev_ind == 0 || nums[ind] > nums[prev_ind - 1]) // 0th element ke liye prev == -1 // strictly greater than
                {
                    take = 1 + dp[ind + 1][ind + 1]; // dp me se call krte time durse box me ek increase kar dege
                }

                // RETURN
                dp[ind][prev_ind] = max(not_take, take);
            }
        }

        int ans = dp[0][0];
        return ans;
    }
};

// 4. Space optimization

class Solution5
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        // BASE CASE

        // already fill with 0

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind; prev_ind >= 0; prev_ind--)
            {
                // LOGIC
                int not_take = 0 + prev[prev_ind];
                int take = 0;

                if (prev_ind == 0 || nums[ind] > nums[prev_ind - 1]) // 0th element ke liye prev == -1 // strictly greater than
                {
                    take = 1 + prev[ind + 1]; // dp me se call krte time durse box me ek increase kar dege
                }

                // RETURN
                curr[prev_ind] = max(not_take, take);
            }

            prev = curr;
        }

        int ans = prev[0];
        return ans;
    }
};

// M-2: print lis and calculate lis len
class Solution6
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n, 1);

        vector<int> hash(n, 0);

        int lislen = 0;
        int lisLastInd = 0;

        for (int current = 0; current < n; current++)
        {
            // fill current element longest incresing subsequence
            for (int prev = 0; prev < current; prev++)
            {

                if (nums[prev] < nums[current] && 1 + dp[prev] > dp[current])
                {
                    // update current length
                    dp[current] = 1 + dp[prev];
                    hash[current] = prev;
                }
            }

            if (lislen < dp[current])
            {
                lislen = dp[current];
                lisLastInd = current;
            }
        }

        // now lislen complete
        vector<int> temp;
        temp.push_back(nums[lisLastInd]);

        while (lisLastInd != hash[lisLastInd])
        {

            lisLastInd = hash[lisLastInd];
            temp.push_back(nums[lisLastInd]);
        }

        reverse(temp.begin(), temp.end());
        // print lis
        for (int val : temp)
        {
            cout << val << " ";
        }
        cout << endl;

        return lislen;
    }
};

// M-3:  lislen only

class Solution7
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);

        int lislen = 1;

        for (int current = 1; current < n; current++)
        {
            // fill current element longest incresing subsequence

            if (temp.back() < nums[current])
            {
                // push into temp
                temp.push_back(nums[current]);
                lislen++;
            }
            else
            {
                // replace element
                int index = lower_bound(temp.begin(), temp.end(), nums[current]) - temp.begin();
                temp[index] = nums[current];
            }
        }

        return lislen;
    }
};


/*
 Example 1:

Input: nums = [4,2,1,4,3,4,5,8,15], k = 3
Output: 5
Explanation:
The longest subsequence that meets the requirements is [1,3,4,5,8].
The subsequence has a length of 5, so we return 5.
Note that the subsequence [1,3,4,5,8,15] does not meet the requirements because 15 - 8 = 7 is larger than 3.
 */
class Solution8
{
public:
    int lengthOfLIS(vector<int> &nums, int k)
    {

        int n = nums.size();
        vector<int> dp(n, 1);

        int ans = 0;

        for (int current = 0; current < n; current++)
        {
            // fill current element longest incresing subsequence
            for (int prev = 0; prev < current; prev++)
            {

                if (nums[prev] < nums[current] && nums[current] - nums[prev] <= k && 1 + dp[prev] > dp[current])
                {
                    // update current length
                    dp[current] = 1 + dp[prev];
                }
            }

            if (ans < dp[current])
            {
                ans = dp[current];
            }
        }

        return ans;
    }
};

int main()
{

    Solution6 lis;
    vector<int> nums = {4, 6, 2, 8};
    cout << lis.lengthOfLIS(nums) << endl;
}