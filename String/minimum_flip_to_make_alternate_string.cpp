#include <bits/stdc++.h>
using namespace std;

/*
0001010111
0101010101
2
 */

int flipCount(string str, char expected)
{

    int count = 0;

    // traverse whole string
    for (int i = 0; i < str.length(); i++)
    {
        if (expected != str[i])
        {
            count++;
        }

        // flip expected charcter
        expected = (expected == '0') ? '1' : '0';
    }

    return count;
}
int alternateString1(string str)
{

    // count flipcount for starting 0 string and starting 1 string and return minimum value

    return min(flipCount(str, '0'), flipCount(str, '1'));
}
int alternateString(string str)
{
    int ans = 0;
    int len = str.length();

    // take two string with starting 0 and 1 and length equal to given string

    string str1;
    string str2;

    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < len; i++)
    {
        // fill str1 (starting with 0) and str2 (starting with 1)
        if (i % 2 == 0)
        {
            str1.push_back('0');
            str2.push_back('1');
        }
        else
        {
            str1.push_back('1');
            str2.push_back('0');
        }

        // for str1 different characters
        if (str[i] != str1[i])
        {
            count1++;
        }
        // for str2 different characters
        if (str[i] != str2[i])
        {
            count2++;
        }
    }

    ans = min(count1, count2);
    count1 < count2 ? cout << str1 << endl : cout << str2 << endl;

    return ans;
}
int main()
{
    cout << alternateString1("001") << endl;

    // string str1[10];
    // cout<<str1<<endl;

    return 0;
}