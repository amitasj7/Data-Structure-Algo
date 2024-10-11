#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void computerLPS(string &pat, vector<int> &LPS, int m)
    {

        int len = 0;

        LPS[0] = 0;

        int i = 1;
        while (i < m)
        {

            if (pat[i] == pat[len])
            {
                len++;
                LPS[i] = len;
                i++;
            }
            else
            {
                if (len >= 1)
                    len = LPS[len - 1];
                else
                {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    vector<int> search(string pat, string txt)
    {
        // code here
        int t = txt.size();
        int p = pat.size();

        vector<int> result;

        vector<int> LPS(p, 0);
        computerLPS(pat, LPS, p);

        int i = 0, j = 0;

        while (i < t)
        {
            if (txt[i] == pat[j])
            {
                i++;
                j++;
            }
            else if (txt[i] != pat[j])
            {

                if (j >= 1)
                    j = LPS[j - 1];
                else
                {
                    i++;
                }
            }
            if (j == p)
            {
                result.push_back(i - p+1);
                j = LPS[j - 1];
            }
        }

        return result;
    }
};