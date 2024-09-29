#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long merge(long long arr[], int low, int mid, int high)
    {

        int i = low;
        int j = mid + 1;

        vector<long long> temp;
        long long count = 0;

        while (i <= mid && j <= high)
        {

            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                // ith ele > jth ele
                count += mid - i + 1;
                temp.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= high)
        {
            temp.push_back(arr[j]);
            j++;
        }

        // transfer element from temp to arr
        // recursion chal raha hai isliye index knhi se bhi start ho skti hai, not particular 0 index
        for (int k = low; k <= high; k++)
        {

            arr[k] = temp[k - low];
        }

        return count;
    }

    long long mergeSort(long long arr[], int low, int high)
    {
        long long count = 0;
        if (low >= high)
            return count;

        int mid = low + (high - low) / 2;

        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);

        return count;
    }
    long long int inversionCount(long long arr[], int n)
    {

        return mergeSort(arr, 0, n - 1);
    }
};