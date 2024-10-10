
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {

        vector<vector<int>> ans;
        // take a priority queue - minHeap

        priority_queue<P, vector<P>, greater<P>> minHeap;

        set<pair<int, int>> s;

        // push first sum
        minHeap.push({nums1[0] + nums2[0], {0, 0}});
        s.insert({0, 0});

        int n1 = nums1.size();
        int n2 = nums2.size();

        while (k-- && !minHeap.empty())
        {

            // front element
            auto minSum = minHeap.top();
            minHeap.pop();

            int i = minSum.second.first;
            int j = minSum.second.second;
            // push into ans
            ans.push_back({nums1[i], nums2[j]});

            // take both case (i+1,j) and (i,j+1)

            if (i + 1 < n1 && s.find({i + 1, j}) == s.end())
            {
                minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                s.insert({i + 1, j});
            }
            if (j + 1 < n2 && s.find({i, j + 1}) == s.end())
            {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                s.insert({i, j + 1});
            }

            // minHeap automatically sort accordingly  sum
        }
        return ans;
    }
};