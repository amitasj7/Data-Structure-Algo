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

    void build(vector<int> &vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {

            update(i, vec[i]);
        }
    }

    void update(int ind, int add)
    {
        ind++; // binary index tree start with index 1
        while (ind <= n)
        {
            fen[ind] += add;

            ind = ind + (ind & (-ind));
        }
    }

    int sum(int ind)
    {
        int s = 0;

        ind++;
        while (ind > 0)
        {
            s += fen[ind];

            ind = ind - (ind & (-ind));
        }

        return s;
    }

    int rangeSum(int left, int right)
    {
        return sum(right) - sum(left - 1);
    }
};

class NumArray
{
    vector<int> fen;
    int n;
    vector<int> nums;

public:
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        this->n = nums.size();
        fen.resize(n + 1, 0);

        for (int i = 0; i < nums.size(); i++)
        {

            updateFenwickTree(i, nums[i]);
        }
    }

    void update(int index, int val)
    {
        int delta = val - nums[index];
        nums[index] = val; // Update the value in the nums array.
        updateFenwickTree(index, delta);
    }

    void updateFenwickTree(int index, int delta)
    {
        index++; // Fenwick Tree is 1-indexed, so we increase the index by 1.
        while (index <= n)
        {
            fen[index] += delta;
            index = index + (index & (-index));
        }
    }

    int sum(int ind)
    {
        int s = 0;

        ind++;
        while (ind > 0)
        {
            s += fen[ind];

            ind = ind - (ind & (-ind));
        }

        return s;
    }
    int sumRange(int left, int right)
    {

        return sum(right) - sum(left - 1);
    }
};
int main()
{

    vector<int> freq = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = freq.size();

    // 1. find sum range 2 - 10
    // 2. add freq[3] with 6 or freq[3] += 6
    // 1. find sum range 2 - 10

    FenwickTree bit(n);
    bit.build(freq);

    cout << bit.rangeSum(2, 10) << endl;
    bit.update(3, 6);

    cout << bit.rangeSum(2, 10) << endl;
}

