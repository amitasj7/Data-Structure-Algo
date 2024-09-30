#include <bits/stdc++.h>
using namespace std;

class Solution
{

    string b;
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    int sz;

public:
    void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());

            return;
        }

        int steps = mpp[word];
        for (int i = 0; i < sz; i++)
        {

            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);

                    seq.pop_back();
                }
            }

            word[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;
        b = beginWord;

        q.push({beginWord});
        mpp[beginWord] = 1;

        int size = b.size();
        sz = size;

        st.erase(b);

        while (!q.empty())
        {
            string word = q.front();
            q.pop();

            int steps = mpp[word];

            if (word == endWord)
            {
                break;
            }

            for (int i = 0; i < size; i++)
            {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }

                word[i] = original;
            }
        }
        if (mpp.find(endWord) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
    vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;

        // take a queue
        queue<vector<string>> q;
        q.push({beginWord});

        // take a visited vector
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        int level = 0;

        while (!q.empty())
        {
            auto vec = q.front();
            q.pop();

            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    wordList.erase(remove(wordList.begin(), wordList.end(), it), wordList.end());
                }
                usedOnLevel.clear();
            }

            string word = vec.back();

            // store in the answers
            if (word == endWord)
            {
                // first vector hai then
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }

            for (int i = 0; i < word.size(); i++)
            {
                char letter = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    auto it = find(wordList.begin(), wordList.end(), word);

                    // now word has find then -
                    if (it != wordList.end())
                    {
                        vec.push_back(word);
                        q.push(vec);

                        // mark as visited on the level
                        usedOnLevel.push_back(word);

                        // remove word from vec because hot->dot and hot->lot
                        vec.pop_back();
                    }
                }

                word[i] = letter;
            }
        }

        return ans;
    }
};