#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int num)
    {

        int count = 0;

        while (num != 0)
        {

            num = num & (num - 1);
            count++;
        }
        return count;
    }
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {

        int count = 0;

        for (int i = n; i >= 0; i--)
        {

            count += helper(i);
        }

        return count;
    }
};