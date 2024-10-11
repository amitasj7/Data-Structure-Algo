#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        
        string vowels = "aeiouAEIOU";

        // find all vowels

        vector<int> index;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            // if vowel then contain vowel index
            if (vowels.find(ch) != string ::npos)
            {

                index.push_back(i);
            }
        }

        int right = index.size() - 1;

        int left = 0;

        while (left < right)
        {

            swap(s[index[left]], s[index[right]]);
            left++;
            right--;
        }

        return s;
    }
};

int main()
{
    Solution s;

    string ans = s.reverseVowels("hello");

    cout << ans << endl;
}