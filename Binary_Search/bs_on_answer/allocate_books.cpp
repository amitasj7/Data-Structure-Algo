#include <bits/stdc++.h>
using namespace std;

int countStudentatmidpages(vector<int> &arr, int n, int pages)
{
    int pagesSum = 0;
    int countStudent = 1;

    for (int i = 0; i < n; i++)
    {
        pagesSum += arr[i];
        if (pagesSum > pages)
        {
            countStudent++;
            pagesSum = arr[i];
        }
    }
    return countStudent;
}
int findPages(vector<int> &arr, int n, int m)
{
    // Write your code here.

    if( m > n){  
        return -1; 
    }

    int sum = 0;
    int max1 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        max1 = max(max1, arr[i]);
    }

    int low = max1;
    int high = sum;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (countStudentatmidpages(arr, n, mid) > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}
int main()
{

    return 0;
}