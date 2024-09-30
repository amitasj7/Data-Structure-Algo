#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        // <word,steps>
        queue<pair<string, int>> q;

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        q.push({beginWord, 1});
        wordSet.erase(beginWord);

        while (!q.empty())
        {

            auto word = q.front().first;
            auto steps = q.front().second;
            q.pop();

            if (word == endWord)
                return steps;

            // word ke letter par traverse krne ke liye
            for (int i = 0; i < word.size(); i++)
            {

                char letter = word[i];

                // us letter ko every character se change krne ke liye
                for (char ch = 'a'; ch <= 'z'; ch++)
                {

                    word[i] = ch;

                    if (wordSet.find(word) != wordSet.end())
                    {
                        q.push({word, steps + 1});
                        wordSet.erase(word);
                    }
                }

                word[i] = letter;
            }
        }
        return 0;
    }
};