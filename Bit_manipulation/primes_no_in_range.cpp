#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
int countPrimes(int n)
{
    int count = 0;
    int a = 1;

    if (n >= 1000000)
    {
        a = 1000000;
        count = 78498;
    }

    for (int i = a + 1; i < n; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
    }
    return count;
}
int main()
{

    cout << countPrimes(5000000) << endl;

    return 0;
}