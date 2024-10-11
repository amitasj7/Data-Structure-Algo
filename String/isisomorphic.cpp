#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    map<char, char> mp;

    for (int i = 0; i < s.length(); i++)
    {

        if (mp.find(s[i]) != mp.end())
        {
            s[i] = mp(s[i]);
            continue;
        }
        mp[s[i]] = t[i];
        s[i] = t[i];
    }
    if (s == t)
        return true;

    return false;
}

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    unordered_map<char, char> mapping;
    unordered_set<char> usedChars;

    for (int i = 0; i < s.length(); i++)
    {
        char char1 = s[i];
        char char2 = t[i];

        // Check if char1 is already mapped to another character.
        if (mapping.find(char1) != mapping.end())
        {
            if (mapping[char1] != char2)
            {
                return false; // Conflict in mapping
            }
        }
        else
        {
            // Check if char2 is already used in mapping.
            if (usedChars.find(char2) != usedChars.end())
            {
                return false; // Multiple characters mapping to the same character
            }

            mapping[char1] = char2;
            usedChars.insert(char2);
        }
    }

    return true;
}
int main()
{

    return 0;
}