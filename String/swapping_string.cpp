#include <bits/stdc++.h>
using namespace std;

/*
1 : BACDE
2 : BCADE
3 : BCDAE
4 : BCDEA
5 : ACDEB
6 : CADEB
7 : CDAEB
8 : CDEAB
9 : CDEBA
10 : ADEBC
ADEBC
 */
string swapchars(string &str, int b, int c)
{

    // if c str.length se jyada hai to
    int l = str.length();

    c = c % l;

    for (int i = 0; i < b; i++)
    {
        swap(str[i % l], str[(i + c) % l]);
        cout << i + 1 << " : " << str << endl;
    }

    return str;
}
int main()
{
    string str = "ABCDE";
    int b = 10;
    int c = 6;

    cout << swapchars(str, b, c) << endl;

    return 0;
}