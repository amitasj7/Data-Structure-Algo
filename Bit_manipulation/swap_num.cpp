#include <bits/stdc++.h>
using namespace std;

void swapNumber(int &a, int &b)
{
    // Write your code here.
    // use of xor operation
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int main()
{
    int a = 2, b = 4;

    swapNumber(a, b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}