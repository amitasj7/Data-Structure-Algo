#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size(), n2 = arr2.size();

        if (n1 > n2)
            return kthElement(k, arr2, arr1); // first array always is smaller than second

        int low = max(0, k - n2), high = min(k, n1);
        int ans = -1;

        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);

            // take four variable
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid - 1 >= 0)
                l1 = arr1[mid - 1];
            if (mid <= n1 - 1)
                r1 = arr1[mid];

            if (k - mid - 1 >= 0)
                l2 = arr2[k - mid - 1];
            if (k - mid <= n2 - 1)
                r2 = arr2[k - mid];

            // satisfy
            if (l1 <= r2 && l2 <= r1)
            {
                ans = max(l1, l2);
                return ans;
            }
            else if (l1 > r2)
                high = mid - 1;

            else
                low = mid + 1;
        }

        return ans;
    }
};

int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
{
    // Write your code here

    int count = 0;
    int k_element = -1;

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {

            if (count == k)
            {
                k_element = arr1[i];
            }
            count++;
            i++;
        }
        else
        {

            if (count == k)
            {
                k_element = arr2[j];
            }
            count++;
            j++;
        }
    }
    while (i < n)
    {

        if (count == k)
        {
            k_element = arr1[i];
        }
        count++;
        i++;
    }
    while (j < m)
    {
        if (count == k)
        {
            k_element = arr2[j];
        }
        count++;
        j++;
    }

    return k_element;
}
int main()
{

    return 0;
}