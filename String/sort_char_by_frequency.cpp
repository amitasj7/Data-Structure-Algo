#include <bits/stdc++.h>
using namespace std;

string frequencySort1(string s)
{
    string ans;

    map<char, int, greater<int>> mp;

    // traverse string and create map

    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    //  sort map mp
    vector<pair<char, int>> myVector(mp.begin(), mp.end());

    sort(myVector.begin(), myVector.end(),
         [](const auto &a, const auto &b)
         {
             return a.second > b.second;
         });

    map<char, int> maphelper(myVector.begin(), myVector.end());

    // print map
    for (auto &i : maphelper)
    {
        cout << i.first << " : " << i.second << endl;
        // insert in ans
        int j = i.second;
        while (j--)
        {
            ans += i.first;
        }
    }

    return ans;
}
string frequencySort(string s)
{
    // create a map and find frequency
    map<char, int> mp;
    string ans;

    // traverse string and create map

    for (auto ch : s)
    {
        mp[ch]++;
    }

    // create vector and insert in {pair , value}

    vector<pair<int, char>> v;
    for (auto i : mp)
    {
        v.push_back({i.second, i.first});
    }

    // sort vector in reverse order
    sort(v.rbegin(), v.rend());

    for (auto i : v)
    {

        int j = i.first;
        while (j--)
        {
            ans += i.second;
        }
    }

    return ans;
}

int main()
{
    cout << frequencySort("tree") << endl;
}