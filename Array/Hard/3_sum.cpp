#include <bits/stdc++.h>
using namespace std;

// Hashing
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> ans;
        set<vector<int>> unique;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> findThird;

            if (i >= 1 && nums[i] == nums[i - 1]) // unique hone chaiye
                continue;

            for (int j = i + 1; j < n; j++)
            {

                int third = -(nums[i] + nums[j]);

                if (findThird.find(third) != findThird.end()) // third element mil gya
                {

                    unique.insert({nums[i], nums[j], third});
                }

                findThird.insert(nums[j]);
            }
        }
        ans.insert(ans.end(), unique.begin(), unique.end());

        return ans;
    }
};

// 3 pointer approach
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> ans;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {

            if (i >= 1 && nums[i] == nums[i - 1]) // unique element
                continue;

            int j = i + 1, k = n - 1;

            while (j < k)
            {

                long long sum = nums[i] + nums[j] + nums[k];

                if (sum < 0)
                    j++;

                else if (sum > 0)
                    k--;

                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1]) // unique element
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};