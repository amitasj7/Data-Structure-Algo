#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num)
{

    int i = num.length() - 1;
    //    cout<<num[i]<<endl;
    //     return "hello";

    while (i != -1)
    {

        int value = num[i];
        if (value % 2 != 0)
        {
            return num.substr(0, i + 1);
        }
        i--;
    }

    return "";
}
int main()
{
    cout << largestOddNumber("3462") << endl;
    // string str = "hello";

    // cout << str.substr(0, 4) << endl;

    return 0;
}