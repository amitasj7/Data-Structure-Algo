#include <bits/stdc++.h>
using namespace std;

// create Node class
struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }

    Node *get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

// create Trie class

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            //  if bit not contain then put into node Trie
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (node->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }

        return maxNum;
    }
};

// Type - 2

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        // sort nums vector
        sort(nums.begin(), nums.end());

        int q = queries.size();
        int n = nums.size();
        // take updateQuery vector
        vector<vector<int>> oq(q, vector<int>(3, 0));

        for (int i = 0; i < q; i++)
        {
            oq[i][0] = queries[i][1];
            oq[i][1] = queries[i][0];
            oq[i][2] = i;
        }

        // sort oq
        sort(oq.begin(), oq.end());

        vector<int> ans(q, 0);

        int index = 0; // nums ke element ko trie me insert krne ke liye
        Trie trie;

        for (int i = 0; i < q; i++)
        {
            int ai = oq[i][0];
            int xi = oq[i][1];
            int qindex = oq[i][2];

            while (index < n && nums[index] <= ai)
            {
                // trie me gush jaa
                trie.insert(nums[index]);

                index++;
            }

            // koi chhota ya equal element nahi hai
            if (index == 0)
                ans[qindex] = -1;
            else
            {
                ans[qindex] = trie.getMax(xi);
            }
        }

        return ans;
    }
};
// Type - 1
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Trie trie;

        int n = nums.size();
        int maxi = 0;
        // create Trie
        for (int i = 0; i < n; i++)
        {
            trie.insert(nums[i]);
        }

        for (auto &it : nums)
        {
            maxi = max(maxi, trie.getMax(it));
        }

        return maxi;
    }
};