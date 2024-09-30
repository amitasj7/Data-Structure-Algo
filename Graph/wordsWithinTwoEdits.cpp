#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int checkLetters(string &str, string &dic)
    {
        int i = 0;
        int size = str.size();

        int dl = 0;
        while (i < size)
        {
            if (str[i] != dic[i])

                dl++;

            i++;
        }
        return dl;
    }
    bool isPossible(string &str, vector<string> &dictionary)
    {
        // traverse dictionary
        for (string &dic : dictionary)
        {
            if (str.size() != dic.size())
                continue;

            if (str == dic)
                return true;

            int differentLetters = checkLetters(str, dic);

            if (differentLetters <= 2)
                return true;
        }

        return false;
    }
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {
        vector<string> ans;

        // traverse all queries
        for (string &str : queries)
        {

            if (isPossible(str, dictionary))
            {
                ans.push_back(str);
            }
        }

        return ans;
    }
};