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

set<int> countPrimes(int n)
{
    // Write your code here.
    // vector<int> ans;
    set<int> st;
    if (isPrime(n))
    {
        st.insert(n);
        return st;
    }
    
    
    for (int i = 2; i * i <= n; i++)
    {

        if (isPrime(i) && n % i == 0)
        {

            st = countPrimes(n / i);
            st.insert(i);
        }
    }
    return st;
}
// vector<int> countPrimes(int n)
// {
//     // Write your code here.
//     for (int i = 1; i * i <= n; i++)
//     {
//         // check if i divided or not ?
//         pair<int, int> p;
//         if (n % i == 0)
//         {
//             if (isPrime(i) && isPrime(n / i))
//             {
//                 return {i, n / i};
//             }

//             // check if pair element prime or not ;
//         }
//     }
//     return {};
// }
int main()
{

    set<int> vec = countPrimes(17);

    for (auto it : vec)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}