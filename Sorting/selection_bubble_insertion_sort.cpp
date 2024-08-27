#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{

    // step 1 : find minimum element and swap it

    for (int i = 0; i <= n - 2; i++)
    {
        int mini_index = i;

        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[mini_index])
            {
                mini_index = j;
            }
        }
        swap(arr[mini_index], arr[i]);
    }
}

void bubbleSort(int arr[], int n)
{

    // greatest element comes in last like a bubble
    for (int i = n - 1; i >= 0; i--)
    {

        bool didswap = 0;

        for (int j = 0; j < i; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                swap(arr[j], arr[j + 1]);
                didswap = 1;
            }
        }

        if (!didswap)
            break;
    }
}

void swap(int &a, int &b)
{

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void insertionSort(int arr[], int n)
{

    for (int i = 1; i <= n - 1; i++)
    {

        int j = i;

        while (arr[j - 1] > arr[j] && j >= 1)
        {

            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}