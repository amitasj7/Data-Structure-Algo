#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {

        int totalPoints = points.size();
        if (totalPoints == 1 || totalPoints == 2)
        {
            return totalPoints;
        }

        int ans = 0;

        // take unordered_map
        unordered_map<string, int> mp;

        // p1(x1,y1)
        for (int i = 0; i < totalPoints; i++)
        {
            int maxpoint = 0;

            // p2(x2,y2)
            for (int j = 0; j < totalPoints; j++)
            {
                if (i == j)
                    continue;

                // find slope

                int dy = (points[j][1] - points[i][1]);
                int dx = (points[j][0] - points[i][0]);

                int gcd = __gcd(dy, dx);

                // simplyfy dy and dx for min value
                dy = dy / gcd;
                dx = dx / gcd;

                string key = to_string(dy) + "/" + to_string(dx);
                // find in map
                if (mp.find(key) == mp.end())
                {
                    mp[key] = 2;
                }
                else
                {
                    mp[key]++;
                }

                maxpoint = max(maxpoint, mp[key]);
            }

            ans = max(ans, maxpoint);

            mp.clear();
        }

        return ans;
    }
};