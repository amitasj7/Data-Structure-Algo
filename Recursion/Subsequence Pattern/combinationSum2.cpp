#include <bits/stdc++.h>
using namespace std;

// Input: candidates = [2,5,2,1,2], target = 5
// Output:
// [
// [1,2,2],
// [5]
// ]

class Solution
{
public:
    void helper(int index, vector<int> &ansHelper, vector<vector<int>> &ans, vector<int> &candidates, int target, int n)
    {

        // Base case
        if (target == 0)
        {
            ans.push_back(ansHelper);
            return;
        }

        for (int i = index; i < n; i++)
        {
            // second time or third time element consider nahi krna hai
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // aage check krne ki jaroorat nahi hai
            if (candidates[i] > target)
                break;

            ansHelper.push_back(candidates[i]);
            helper(i + 1, ansHelper, ans, candidates, target - candidates[i], n);
            // Remove the last element of current
            ansHelper.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        vector<vector<int>> ans;

        vector<int> ansHelper;
        int n = candidates.size();

        sort(candidates.begin(), candidates.end());

        helper(0, ansHelper, ans, candidates, target, n);

        return ans;
    }
};
class Solution
{
public:
    void helper(int index, set<vector<int>> &s, vector<int> &setHelper, vector<int> &candidates, int target, int n)
    {
        if (target == 0)
        {
            s.insert(setHelper);
            return;
        }
        if (index == n || target < 0)
        {
            return;
        }

        // pick Element
        setHelper.push_back(candidates[index]);
        helper(index + 1, s, setHelper, candidates, target - candidates[index], n);

        // not Pick Element
        setHelper.pop_back();

        helper(index + 1, s, setHelper, candidates, target, n);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        // combination repeat nahi hone chaiye so Set data structure
        set<vector<int>> s;

        vector<int> setHelper;

        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        helper(0, s, setHelper, candidates, target, n);

        vector<vector<int>> ans(s.begin(), s.end());

        return ans;
    }
};