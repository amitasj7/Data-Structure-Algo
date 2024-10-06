#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {

        int jump = 0;
        int maxReach = 0;
        int size = nums.size();
        int i = 0;

        while (i < size)
        {

            int reach = i + nums[i];
            if (maxReach < reach && reach < size )
            {
                // upadate maxReach
                maxReach = reach;
                jump++;
            }

            i++;
        }

        return jump;
    }
    bool canJump(vector<int> &nums)
    {

        int maxReach = 0;
        int size = nums.size();
        int i = 0;

        while (i < size)
        {

            if (i > maxReach)
            {
                return false;
            }
            int reach = i + nums[i];
            if (maxReach < reach)
            {
                // upadate maxReach
                maxReach = reach;
            }

            i++;
        }
        return true;
    }
};