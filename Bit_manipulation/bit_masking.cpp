#include <bits/stdc++.h>
using namespace std;

long long Setadd(long long x, int num)
{
    x = x | (1 << num);

    cout << "add: " << x << endl;
    return x;
}

long long Setremove(long long x, int num)
{
    int mask = 1 << num;
    mask = ~(mask);

    x = (x & mask);

    cout << "remove: " << x << endl;
    return x;
}
void Setprint(long long x)
{
    // max x value is 60 then
    for (int bits = 0; bits <= 60; bits++)
    {
        // check bits set or not
        if ((x & (1 << bits)) != 0)
        {
            cout << x << endl;
            cout << bits << " ";
        }
    }
}
int main()
{
    long long x = 0;
    x = Setadd(x, 5);
    x = Setadd(x, 1);
    x = Setadd(x, 5);
    x = Setadd(x, 3);

    x = Setremove(x, 5);

    Setprint(x);

    return 0;
}