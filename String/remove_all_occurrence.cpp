#include <bits/stdc++.h>
using namespace std;


/* 
geeksforgeeks 
gksforgks
 */
string removeOccurrence(string &str, char c)
{

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == c)
        {
            // erase this
            str.erase(str.begin() + i);
            // i ki value na bade ;
            i--;
        }
    }
    return str;
}
int main()
{
    string str = "geeksforgeeks";

    cout << removeOccurrence(str, 'e') << endl;

    return 0;
}