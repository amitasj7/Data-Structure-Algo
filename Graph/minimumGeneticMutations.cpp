#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {

        // for quick access we use vector ---> unorderedSet
        unordered_set<string> bankHelper;
        bankHelper.insert(bank.begin(), bank.end());

        unordered_set<string> visited;

        queue<string> q;

        q.push(startGene);
        // mark visited
        visited.insert(startGene);
        int minSteps = 0;

        while (!q.empty())
        {

            int size = q.size();

            for (int i = 0; i < size; i++)
            {

                string str = q.front();
                q.pop();

                // check if endGenes or not
                if (str == endGene)
                    return minSteps;

                // change all characters of str with A G C T one by one
                for (char ch : "AGCT")
                {
                    int n = str.size();

                    for (int j = 0; j < n; j++)
                    {
                        string newStr = str;

                        newStr[j] = ch;

                        // checking of newStr if exist or not
                        if (bankHelper.find(newStr) != bankHelper.end() && visited.find(newStr) == visited.end())
                        {
                            // valid newStr
                            // push into queue
                            q.push(newStr);

                            // mark visited
                            visited.insert(newStr);
                        }
                    }
                }
            }
            minSteps++;
        }

        return -1;
    }
};