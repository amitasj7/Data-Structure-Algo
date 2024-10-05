#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal)
{
    int count = 0;

    while (start != 0 || goal != 0)
    {
        // if last bits is not matching then increase count
        if ((start & 1) != (goal & 1))
        {
            count++;
        }

        // right shift of both numbers
        start = start >> 1;
        goal = goal >> 1;
    }

    return count;
}
int main()
{

    int start = 16;
    int goal = 7;

    cout << minBitFlips(start, goal) << endl;
    return 0;
}