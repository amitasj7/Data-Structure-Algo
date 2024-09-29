#include <bits/stdc++.h>
using namespace std;


// Xor
class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr)
    {
        int n = arr.size();

        int xr = 0;

        for (int i = 0; i < n; i++)
        {

            xr = xr ^ arr[i];
            xr = xr ^ (i + 1);
        }

        // xr = 4  --> 100
        // find 1 bit place that different in repeating and missing number

        int bitno = -1;

        for (int i = 0; i <= 32; i++)
        {

            if ((xr & (1 << i)) != 0)
            {
                bitno = i;
                break;
            }
        }

        int xor1 = 0, xor0 = 0;

        // find that no which contain bitno 0 and 1
        for (int i = 0; i < n; i++)
        {

            if ((arr[i] & (1 << bitno)) == 0)
            {
                xor0 = xor0 ^ arr[i];
            }
            else
            {
                xor1 = xor1 ^ arr[i];
            }
        }

        // now 1 to N
        for (int i = 1; i <= n; i++)
        {

            if ((i & (1 << bitno) )== 0)
            {
                xor0 = xor0 ^ i;
            }
            else
            {
                xor1 = xor1 ^ i;
            }
        }

        int repeat = xor1; // count in  arr that equal >= 2
        int missing = xor0;

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (repeat == arr[i])
                count++;
        }

        // {repeat ele , missing ele}
        if (count >= 2) // hamne jo socha tha vo sahi hai
            return {repeat, missing};

        return {missing, repeat}; // hamne jo socha vo galat hai
    }
};