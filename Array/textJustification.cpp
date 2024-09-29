#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findLine(int i, int j, int eachGaddeSpace, int extraGaddeSpace, vector<string> &words, int maxWidth)
    {
        string line = "";

        for (int k = i; k < j; k++)
        {
            line += words[k];

            // for last line
            if (k == j - 1)
                break;

            for (int z = 1; z <= eachGaddeSpace; z++)
            {
                line += " ";
            }

            if (extraGaddeSpace > 0)
            {
                line += " ";
                extraGaddeSpace--;
            }
        }

        while (line.length() < maxWidth)
        {
            line += " ";
        }

        return line;
    }
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {

        vector<string> ans;

        int n = words.size();

        int i = 0;
        while (i < n)
        {
            int lettersCount = words[i].size();

            int j = i + 1;

            int gadde = 0;

            while (j < n && words[j].length() + 1 + lettersCount + gadde <= maxWidth)
            {
                lettersCount += words[j].size();
                gadde += 1;
                j++;
            }

            int remainGadde = maxWidth - lettersCount;

            int eachGaddeSpace = gadde ? remainGadde / gadde : 0;
            int extraGaddeSpace = gadde ? remainGadde % gadde : 0;

            // for last line
            if (j == n)
            {
                eachGaddeSpace = 1;
                extraGaddeSpace = 0;
            }

            string line = findLine(i, j, eachGaddeSpace, extraGaddeSpace, words, maxWidth);

            ans.push_back(line);

            i = j;
        }

        return ans;
    }
};