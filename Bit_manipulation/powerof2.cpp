#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "00000";

    int one = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int ele = int(s[i]);

        if (ele & 1 == 1)
        {
            one++;
        }
    }
    if (one == 1 || one  == 0)
    {
        cout<<"true";
    }
    else{  
        cout<<"false";
    }
    return 0; 

   
}