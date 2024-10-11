#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{

    // sort s and t string
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}