/* 
1. integer value ko dynamically kese allocate kare int * p = new int ; *p = 8; then 8 dynamically allocate hai jise p ki help se access kiya ja skta hai
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int *p = new int;
    *p = 6;

    cout << *p << endl;
    cout << p << endl;
    delete p;
    cout << p << endl;
    return 0;
}