#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Increasing order quick sort
    void quickSort(int arr[], int low, int high)
    {
        if (low >= high)
            return;

        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }

    // increasing order
    int partition(int arr[], int low, int high)
    {
        int pivot = low;

        int i = low, j = high;

        while (i < j)
        {

            // find greater element from pivot using j
            while (arr[j] <= arr[pivot] && j >= low)
                j--;

            // find smaller or equal element from pivot using i
            while (arr[i] > arr[pivot] && i <= high)
                i++;

            if (i < j)
                swap(arr[i], arr[j]);
        }

        swap(arr[j], arr[pivot]);
        return j;
    }
};


class Solution2
{
public:
    // decreasing order quick sort
    void quickSort2(int arr[], int low, int high)
    {
        if (low >= high)
            return;

        int pivot = partition2(arr, low, high);
        quickSort2(arr, low, pivot - 1);
        quickSort2(arr, pivot + 1, high);
    }

    // decreasing order
    int partition2(int arr[], int low, int high)
    {
        int pivot = low;

        int i = low, j = high;

        while (i < j)
        {
            // find smaller or equal element from pivot using j
            while (arr[i] > arr[pivot] && i <= high)
                i++;

            // find greater element from pivot using i
            while (arr[j] <= arr[pivot] && j >= low)
                j--;

            if (i < j)
                swap(arr[i], arr[j]);
        }

        swap(arr[i], arr[pivot]);
        return i;
    }
};
