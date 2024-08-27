#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{

    int i = low;
    int j = mid + 1;

    vector<int> temp;

    while (i <= mid && j <= high)
    {

        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
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
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}