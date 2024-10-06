#include <bits/stdc++.h>
using namespace std;

vector<int> MinimumCoins(int n)
{
    // Write your code here

    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans;
    /*
        for (auto it : coins)
        {
            cout << it << " ";
        }
     */
    int i = coins.size() - 1;

    // run loop till n !=0
    while (n != 0)
    {
        if (coins[i] <= n)
        {
            ans.push_back(coins[i]);

            // update n rupees value
            n -= coins[i];
        }
        else
        {
            i--;
        }
    }

    return ans;
}

int main()
{
    /*
     vector<int> vec = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    for (auto it : vec)
    {
        cout << it << " ";
    } 
    */

   MinimumCoins()
}