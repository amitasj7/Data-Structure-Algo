#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(int ind, vector<vector<int>> &result, vector<int> &combination, int k,
                   int n)
    {
        if (n == 0 && combination.size() == k)
        {
            result.push_back(combination);
            return;
        }

        for (int i = ind; i <= 9; ++i)
        {
            if (n < i) // target chhota ho gya
                break;

            // if(i > ind && .... ) continue;  // vector me sabhi element unique hai jo 1 to 9 hai

            combination.push_back(i);
            backtrack(i + 1, result, combination, k, n - i);
            combination.pop_back();

            // not take wala case lene ki jaroorat nahi kyuki not_take le fir aage 2 hoga so loop apne aap hi cover kar lega
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(1, result, combination, k, n);
        return result;
    }
};