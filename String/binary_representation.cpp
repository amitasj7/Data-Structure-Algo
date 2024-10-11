#include <bits/stdc++.h>
using namespace std;

string BinaryRepresentation(long long num)
{

    string str;

    while (num > 0)
    {
        (num % 2 == 0) ? str.push_back('0') : str.push_back('1');

        num /= 2;
    }
    // reverse this string

    reverse(str.begin(), str.end());

    return str;
}

string HexaDecimalRepresentation(int num)
{

    string str;

    while (num > 0)
    {
        int remainder = num % 16;
        if (remainder >= 0 && remainder <= 9)
        {

            char c = remainder + '0';
            str.push_back(c);
        }

        else
        {
            // remainder ke across 'A', 'B', ... representation
            char c = 'A' + (remainder - 10);
            str.push_back(c);
        }

        // update num
        num /= 16;
    }

    reverse(str.begin(), str.end());

    return str;
}
int main()
{
    // cout << BinaryRepresentation(90) << endl;
    cout << HexaDecimalRepresentation(100000000) << endl;

    // int x = 9;

    // char c = x + '0';

    // cout << "char: " << c << endl;

    return 0;
}