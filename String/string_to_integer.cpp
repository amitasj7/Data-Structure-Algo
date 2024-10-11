#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    int ansInt = 0;
    bool negative = false;

    // traverse whole string
    for (char c : s)
    {
        if (isdigit(c))
        {
            int value = (c - '0');
            // update ans
            ansInt = ansInt * 10 + value;
        }
        if (c == '-')
        {
            negative = true;
        }
    }

    if (negative)
        return -1 * ansInt;

    return ansInt;
}