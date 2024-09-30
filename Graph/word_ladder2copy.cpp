#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> shortestTransitionPaths(string start, string finish, vector<string> &wordPool)
{
    // Write your code here.
    vector<vector<string>> ans;

    // take a queue
    queue<vector<string>> q;
    q.push({start});

    // take a visited vector
    vector<string> usedOnLevel;
    usedOnLevel.push_back(start);

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
                wordPool.erase(remove(wordPool.begin(), wordPool.end(), it), wordPool.end());
            }
            usedOnLevel.clear();
        }

        string word = vec.back();

        // store in the answers
        if (word == finish)
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

                auto it = find(wordPool.begin(), wordPool.end(), word);

                // now word has find then -
                if (it != wordPool.end())
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