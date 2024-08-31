#include <bits/stdc++.h>
using namespace std;

class FenwickTree
{
    vector<int> fen;
    int n;

public:
    FenwickTree(int size)
    {
        this->n = size;
        fen.resize(n + 1, 0);
    }

    void update(int ind, int add)
    {
        ind++; // binary index tree starts with index 1
        while (ind <= n)
        {
            fen[ind] += add;
            ind += ind & (-ind);
        }
    }

    int sum(int ind)
    {
        int s = 0;
        ind++; // binary index tree starts with index 1
        while (ind > 0)
        {
            s += fen[ind];
            ind -= ind & (-ind);
        }
        return s;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;

        vector<int> nums(size);
        for (int i = 0; i < size; i++)
        {
            cin >> nums[i];
        }

        // Compress the values in the array to the range [1, size]
        map<int, int> mp;
        int rank = 1;

        for (int i = 0; i < size; i++)
        {
            mp[nums[i]] = 0;
        }

        for (auto &pair : mp)
        {
            pair.second = rank++;
        }

        for (int i = 0; i < size; i++)
        {
            nums[i] = mp[nums[i]];
        }

        // Find the maximum element after compression
        int maxi = *max_element(nums.begin(), nums.end());

        // Fenwick Tree to count inversions
        FenwickTree bit(maxi);
        int inversion_count = 0;

        for (int i = size - 1; i >= 0; i--)
        {
            inversion_count += bit.sum(nums[i] - 1);
            bit.update(nums[i], 1);
        }

        cout << inversion_count << endl;
    }

    return 0;
}