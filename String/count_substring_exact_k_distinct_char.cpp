#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int substrCount(string s, int k)
    {
        // code here.

        long long ans = 0;

        int n = s.size();

        if (n < k)
            return ans; // string ki size k se chhoti hai

        int start = 0, end = 0;
        unordered_map<char, int> freq;

        for (end = 0; end < n; end++)
        {

            freq[s[end]]++; // store only different characters

            while (freq.size() > k)
            { // different character k se jyada ho gaye so trim

                freq[s[start]]--;

                if (freq[s[start]] == 0)
                    freq.erase(s[start]);

                start++;
            }
            // check window that is valid or not
            if (freq.size() == k)
            {

                ans++;
            }
        }

        // now end has finish but start take
        while (freq.size() == k)
        {

            freq[s[start]]--;

            if (freq[s[start]] == 0)
                freq.erase(s[start]);
            start++;

            if (freq.size() == k)
                ans++;
        }

        return ans;
    }
};