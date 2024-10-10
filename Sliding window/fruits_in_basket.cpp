#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruits(vector<int> &arr)
    {

        int n = arr.size();
        int start = 0, end = 0;

        unordered_map<int, int> mp; // <element , freq>
        int maxfruit = 0;
        for (end = 0; end < n; end++)
        {

            mp[arr[end]]++;

            while (mp.size() > 2)
            {

                mp[arr[start]]--;

                if (mp[arr[start]] == 0)
                    mp.erase(arr[start]);

                start++;
            }

            maxfruit = max(maxfruit, end - start + 1);
        }
        return maxfruit;
    }
};

// optimal - 2
class Solution
{
public:
    int totalFruits(vector<int> &arr)
    {

        int n = arr.size();
        int start = 0, end = 0;

        unordered_map<int, int> mp; // <element , freq>
        int maxfruit = 0;
        for (end = 0; end < n; end++)
        {

            mp[arr[end]]++;

            if (mp.size() > 2)
            {

                mp[arr[start]]--;
                if (mp[arr[start]] == 0)
                    mp.erase(arr[start]);
                start++;
            }

            maxfruit = max(maxfruit, end - start + 1);
        }
        return maxfruit;
    }
};