#include <bits/stdc++.h>
using namespace std;

// M-1
class Solution
{
public:
    int lenOfLongSubarr(int arr[], int n, int k)
    {
        int maxlen = 0;

        for (int i = 0; i < n; i++)
        {
            int currSum = 0;
            for (int j = i; j < n; j++)
            {

                currSum += arr[j];

                if (currSum == k)
                {

                    int len = j - i + 1;
                    maxlen = max(maxlen, len);
                }
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

        map.insert({0,-1}); // if subarray 0 to i hua to

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

// M-3 : Sliding window (zero and positive )
class Solution
{
public:
    int lenOfLongSubarr(int arr[], int n, int k)
    {
        // Complete the function

        int start = 0;

        int sum = 0;

        int maxlen = 0;

        for (int end = 0; end < n; end++)
        {

            sum += arr[end];

            while (sum > k && start <= end)
            {
                // trim fro left

                sum -= arr[start];
                start++;
            }

            if (sum == k)
            {
                maxlen = max(maxlen, end - start + 1);
            }
        }

        return maxlen; 
    }
};