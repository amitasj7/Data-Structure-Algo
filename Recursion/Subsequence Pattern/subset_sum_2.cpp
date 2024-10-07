#include <bits/stdc++.h>
using namespace std;

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
class Solution
{
public:
    void helper(int index, vector<vector<int>> &ans, vector<int> &ansHelper, vector<int> &nums, int n)
    {

        // every size anshelper ko ans me push kiya jaiga 1size , 2size, 3size etc...
        ans.push_back(ansHelper);

        for (int i = index; i < n; i++)
        {

            // first time element already aa chuka hai ye second or third time hai so isko nahi lege
            if (i != index && nums[i] == nums[i - 1])
                continue;
            ansHelper.push_back(nums[i]);
            helper(i + 1, ans, ansHelper, nums, n);

            ansHelper.pop_back();
        }
        }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();

        vector<int> ansHelper;

        sort(nums.begin(), nums.end());
        helper(0, ans, ansHelper, nums, n);

        return ans;
    }
};