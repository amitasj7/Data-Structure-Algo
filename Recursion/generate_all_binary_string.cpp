#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;

    void helper(string temp, int num)
    {
        // BASE CASE

        if (temp.size() == num)
        {
            ans.push_back(temp);
            return;
        }

        // LOGI C

        // 1. add 0
        helper(temp + "0", num);
        // 2. add 1
        if (temp.empty() || temp.back() != '1')
            helper(temp + "1", num);

        // RETURN
    }
    vector<string> generateBinaryStrings(int num)
    {
        // Write your code

        helper("", num);

        return ans;
    }
};