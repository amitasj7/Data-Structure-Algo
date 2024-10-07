#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(int ind, int sum, vector<int> &ans, vector<int> &arr, int n)
    {

        // BASE CASE
        if (ind == n)
        {
            ans.push_back(sum);
            return;
        }

        // LOGIC

        // take element
        helper(ind + 1, sum + arr[ind], ans, arr, n);
        // sum = sum - arr[ind];  // sum not update becase it's a fuction varibale

        // not take
        helper(ind + 1, sum, ans, arr, n);

        // RETURN
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here

        vector<int> ans;

         helper(0, 0, ans, arr, n);

         return ans; 
    }
};