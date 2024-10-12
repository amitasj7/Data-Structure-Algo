#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    vector<int> seg;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, int arr[])
    {
        // BASE CASE

        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        // LOGIC
        // find mid
        int mid = low + (high - low) << 1;

        build(2 * ind + 1, low, mid, arr);      // for left
        build(2 * ind + 2, mid + 1, high, arr); // for right

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
        // RETURN
    }

    int query(int ind, int low, int high, int left, int right)
    {

        // no overlap
        // [l,r][low,high] or [low,high][l,r]
        if (right < low || left > high)
            return INT_MAX;

        // complete overlap

        // [l,low,high,r]
        if (low >= left && high <= right)
        {
            return seg[ind];
        }

        // partial overlap
        int mid = low + (high - low) << 1;

        int l = query(2 * ind + 1, low, mid, left, right);
        int r = query(2 * ind + 2, mid + 1, high, left, right);

        return min(l, r);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        // BASE CASE

        if (low == high)
        {
            seg[ind] = val;
            return;
        }

        // LOGIC
        int mid = low + (high - low) << 1;

        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);

        // RETURN
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

int main()
{
    int n1;
    cin >> n1;

    int arr[n1];

    for (int i = 0; i < n1; i++)
    {
        cin >> arr[i];
    }

    SGTree seg1(n1);
    seg1.build(0, 0, n1 - 1, arr);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;

        cin >> l >> r;

        cout << "min val in range " << l << " to " << r << " " << seg1.query(0, 0, n1 - 1, l, r);
    }
}