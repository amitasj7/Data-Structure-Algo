#include <bits/stdc++.h>
using namespace std;

int findXorComplete(int num)
{
    // find xor of 1 to num . if num = 5 then (1 ^ 2 ^ 3 ^ 4 ^ 5) = 1
    int remainder = num % 4;

    switch (remainder)
    {
    case 0:
        cout << "XOR: " << num << endl;
        return num;
        break;
    case 1:
        cout << "XOR: 1" << endl;
        return 1;
        break;
    case 2:
        cout << "XOR: " << num + 1 << endl;
        return num+1;
        break;
    case 3:
        cout << "XOR: 0" << endl;
        return 0;
        break;

    default:
        break;
    }
}
void findXorinRange(int left, int right)
{
    // add 1 to left -1 number for 2 times and manage them . 

    int ans = (findXorComplete(right)) ^ (findXorComplete(left - 1));

    cout << "XOR OF " << left << " To " << right << " : " << ans << endl;
}
int main()
{
    // findXorComplete(40);

    findXorinRange(6, 10);

    return 0;
}