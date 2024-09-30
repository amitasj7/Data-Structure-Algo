#include <bits/stdc++.h>
using namespace std;

class Solution
{

    vector<string> ans;
    unordered_set<string> st;
    string sent;

public:
    bool validword(string &word)
    {

        return st.find(word) != st.end();
    }
    void helper(int index, string &s)
    {
        // BASE CASE
        if (index == s.size())
        {
            ans.push_back(sent);
            return;
        }

        // LOGIC
        for (int j = index; j < s.size(); j++)
        {
            string word = s.substr(index, j - index + 1);

            if (validword(word))
            {
                string temp = sent;
                // add space
                if (!sent.empty())
                    sent += " ";
                sent += word;

                helper(j + 1, s);

                // undo sentence or remove add word
                sent = temp;
            }
        }

        // RETURN
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        st.insert(wordDict.begin(), wordDict.end());

        helper(0, s);

        return ans;
    }
};