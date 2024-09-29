
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {

        int k = 0;
        // Your code here
        int maxlen = 0;
        // Complete the function
        unordered_map<int, int> map; // <prefixsum, index>

        map.insert({0, -1}); // if subarray 0 to i hua to

        int prefixSum = 0;
        for (int ind = 0; ind < n; ind++)
        {

            prefixSum += arr[ind];

            // find prefixSum-k
            if (map.find(prefixSum - k) != map.end())
            {

                int start = map[prefixSum - k];
                int end = ind;

                maxlen = max(maxlen, end - start);
            }

            if (map.find(prefixSum) == map.end()) //  0 ke case me as left as possible dekhna hai
            {

                map.insert({prefixSum, ind});
            }
        }

        return maxlen;
    }
};

// M-2 Prefix Sum Technique  (negative, zero , positive)
class Solution
{
public:
    int lenOfLongSubarr(int arr[], int n, int k)
    {
        int maxlen = 0;
        // Complete the function
        unordered_map<int, int> map; // <prefixsum, index>

        map.insert({0, -1}); // if subarray 0 to i hua to

        int prefixSum = 0;
        for (int ind = 0; ind < n; ind++)
        {

            prefixSum += arr[ind];

            // find prefixSum-k
            if (map.find(prefixSum - k) != map.end())
            {

                int start = map[prefixSum - k];
                int end = ind;

                maxlen = max(maxlen, end - start);
            }

            if (map.find(prefixSum) == map.end()) //  0 ke case me as left as possible dekhna hai
            {

                map.insert({prefixSum, ind});
            }
        }

        return maxlen;
    }
};