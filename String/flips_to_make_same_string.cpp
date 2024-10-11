#include <bits/stdc++.h>
using namespace std;

/*
00011110001110 ans : 2
010101100011 ans : 4
 */
int filpCount(string str, char c)
{

    int count = 0;

    for (int i = 0; i < str.length(); i++)
    {

        if ((str[i] != c && i == 0) || (str[i] != c && str[i] != str[i - 1]))
        {
            count++;
        }
    }

    return count;
}
int findFlips(string str)
{

    return min(filpCount(str, '0'), filpCount(str, '1'));
}
int main()
{
    cout << findFlips("00011110001110") << endl;
    cout << findFlips("010101100011") << endl;

    return 0;
}