#include <bits/stdc++.h>
using namespace std;

string nextBinaryNumber(string str)
{

    // traversing start from end
    int len = str.length();

    int carry = 1;

    for (int i = len - 1; i >= 0; i--)
    {

        int digits = str[i] - '0';
        digits += carry;

        if (digits == 2)
        {
            str[i] = '0';
            carry = 1;
            digits = 0;
        }
        else
        {
            str[i] = '1';
            // carry not store
            carry = 0;

            break;
        }
    }
    // if all digits 1 then carry store 1 ;
    if (carry == 1)
    {
        str.insert(str.begin(), '1');
    }

    return str;
}
int main()
{
    cout << nextBinaryNumber("111") << endl;

    return 0;
}