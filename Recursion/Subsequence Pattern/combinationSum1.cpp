#include <bits/stdc++.h>
using namespace std;

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

class Solution
{
public:
    void helper(int index, vector<vector<int>> &ans, vector<int> &ansHelper, vector<int> &candidates, int n, int target)
    {

        if (target == 0)
        {
            ans.push_back(ansHelper);
            return;
        }
        if (index == n || target < 0) // phle check nahi kiya hia to target negative bhi ho skta hai
        {
            return;
        }

        // pick Element
        ansHelper.push_back(candidates[index]);
        helper(index, ans, ansHelper, candidates, n, target - candidates[index]); // element ko again pick kar skte hai
        ansHelper.pop_back();
        // not Pick Element

        helper(index + 1, ans, ansHelper, candidates, n, target);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;

        vector<int> ansHelper;

        int n = candidates.size();

        helper(0, ans, ansHelper, candidates, n, target);

        return ans;
    }
};