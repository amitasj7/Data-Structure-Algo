#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int n, int arr[])
    {
        // Code here

        int leader = arr[n - 1];
        vector<int> leaderArr;
        leaderArr.push_back(leader);

        for (int i = n - 2; i >= 0; i--)
        {

            if (arr[i] >= leader)
            {
                leader = arr[i];
                leaderArr.push_back(leader);
            }
        }

        reverse(leaderArr.begin(), leaderArr.end());
        return leaderArr;
    }
};