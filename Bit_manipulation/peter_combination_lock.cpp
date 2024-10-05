#include <bits/stdc++.h>
using namespace std;

void peterCombnationLock(vector<int> vec)
{

    vector<char> sign;
    int size = vec.size();

    int numberOfSubets = 1 << size;
    for (int i = 0; i < (numberOfSubets); i++)
    {
        int sum = 0;
        for (int bits = 0; bits < size; bits++)
        {
            // chech bits set or not
            if (i & (1 << bits))
            {
                sum += vec[bits];
                sign.push_back('+');
            }
            else
            {
                sum -= vec[bits];
                sign.push_back('-');
            }
        }
        // for 90, 90, 90, 90 | we can assume sum % 360
        if (sum % 360 == 0)
        {
            cout << "TRUE: ";
            // print sign vector
            for (auto it : sign)
            {
                cout << it << ",";
            }
            cout << endl;
        }
        // vector reset
        sign.clear();
    }
}
int main()
{
    vector<int> v = {40, 50, 10};
    /*
        TRUE: -,+,-,
        TRUE: +,-,+,
     */
    peterCombnationLock(v);

    return 0;
}