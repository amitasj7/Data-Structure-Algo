#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;

        int ten = 0;

        // check all custumers
        for (int i = 0; i < bills.size(); i++)
        {

            if (bills[i] == 5)
            {
                // add 5 rupees
                five++;
            }
            else if (bills[i] == 10)
            {
                // add 10 and return 5
                ten++;
                five--;
            }
            else
            {
                // for twenty = add 5 and return 10 + 5 or 5 + 5 + 5
                if (ten > 0)
                {
                    five--;
                    ten--;
                }
                else
                {
                    five -= 3;
                }
            }

            if (five < 0 || ten < 0)
            {
                return false;
            }
        }

        return true;
    }
};
