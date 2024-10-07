#include <bits/stdc++.h>
using namespace std;

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Recursion
class Solution
{
public:
    void helper(vector<int> &ds, vector<int> &visit, vector<vector<int>> &ans, vector<int> &nums, int n)
    {

        //  Base Case
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < n; i++)
        {

            if (!visit[i])
            {
                ds.push_back(nums[i]);
                visit[i] = true;
                helper(ds, visit, ans, nums, n);
                visit[i] = false;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> visit(n, 0);

        // vector<int> ansHelper;

        helper(ds, visit, ans, nums, n);

        return ans;
    }
};

class Solution
{
public:
    void helper(int index, vector<vector<int>> &ans, vector<int> &nums, int n)
    {

        //  Base Case
        if (index == n)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < n; i++)
        {

            swap(nums[index], nums[i]);

            helper(index + 1, ans, nums, n);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> ans;

        // vector<int> ansHelper;

        int n = nums.size();
        helper(0, ans, nums, n);

        return ans;
    }
};