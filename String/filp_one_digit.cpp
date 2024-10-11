#include <bits/stdc++.h>
using namespace std;

// sum concept = n-1 or 1 then true otherwise false
bool flipOnePosition(string str)
{

    int sum = 0;
    int n = str.length();

    // string ke every digit ka sum lege
    for (int i = 0; i < str.length(); i++)
    {
        sum += (int)(str[i] - '0');
    }
    if (sum == n - 1 || sum == 1)
    {
        return true;
    }
    return false;
}
// count no. of 0 and 1 concept
bool flipOnePosition1(string str)
{
    // take two count
    int count0 = 0;
    int count1 = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0')
        {
            count0++;
        }
        else
        {
            count1++;
        }
    }
    // return value
    if (count0 == 1 || count1 == 1)
        return true;

    return false;
}
int main()
{
    // flipOnePosition("1111111110") ? cout << "YES" : cout << "NO";
    flipOnePosition1("0") ? cout << "YES" : cout << "NO";

    return 0;
}