#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(int index, vector<int> &nums, int n, vector<vector<int>> &ans, vector<int> &ansHelper)
    {

        // Base Case

        if (index == n)
        {
            ans.push_back(ansHelper);
            return;
        }

        // pickElement
        ansHelper.push_back(nums[index]);
        helper(index + 1, nums, n, ans, ansHelper);

        // notPickElement
        ansHelper.pop_back();
        helper(index + 1, nums, n, ans, ansHelper);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> ans;
        int n = nums.size();

        vector<int> ansHelper;
        helper(0, nums, n, ans, ansHelper);

                return ans;
    }
};