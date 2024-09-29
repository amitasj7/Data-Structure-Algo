#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kadane(vector<int> &nums)
    {
        int n = nums.size();

        int smaxi = INT_MIN; // array containg negative value
        int sSum = 0;

        for (int i = 0; i < n; i++)
        {

            sSum += nums[i];

            // check for maxi update
            if (sSum > smaxi)
            {
                smaxi = sSum;
            }

            // check for sSum update to 0
            if (sSum < 0)
            {
                sSum = 0;
            }
        }

        return smaxi;
    }
    int maxSubarraySumCircular(vector<int> &nums)
    {

        int n = nums.size();

        // for contigious part of array
        int smaxi = INT_MIN; // array containg negative value

        int smaxi = kadane(nums);
        int totalSum = 0;
        // for calculate circular direction

        for (int i = 0; i < n; i++)
        {
            totalSum += nums[i];
            nums[i] *= -1;
        }

        int cmaxi = kadane(nums);

        if (totalSum + cmaxi == 0) // sabhi elements negative case me one element permanantly store
            return smaxi;
        int ans = max(smaxi, totalSum + cmaxi);

        return ans;
    }
};