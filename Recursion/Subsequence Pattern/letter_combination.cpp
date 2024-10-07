#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(int ind, string output, vector<string> &mapping, vector<string> &ans, string digits, int n)
    {
        // BASE CASE
        if (ind == n)
        {
            ans.push_back(output);
            return;
        }

        // LOGIC
        int button = digits[ind] - '0';

        string map = mapping[button];

        for (int i = 0; i < map.size(); i++)
        {

            char ch = map[i];
            helper(ind + 1, output + ch, mapping, ans, digits, n);
        }

        // RETURN
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;

        int n = digits.size();
        if (n == 0)
            return ans;

        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(0, "", mapping, ans, digits, n);

        return ans;
    }
};