#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{

    int size1 = nums1.size();
    int size2 = nums2.size();

    int count = 0;
    // count merge sortd array ki index ko point krta hai

    int index2 = (size1 + size2 + 1) / 2;
    int index1 = index2 - 1;

    int element2 = 0;
    int element1 = 0;
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {

        if (nums1[i] <= nums2[j])
        {

            if (count == index1)
            {
                element1 = nums1[i];
            }
            if (count == index2)
            {
                element2 = nums1[i];
            }

            count++;
            i++;
        }
        else
        {
            if (count == index1)
            {
                element1 = nums2[j];
            }
            if (count == index2)
            {
                element2 = nums2[j];
            }

            count++;
            j++;
        }
    }

    while (i < size1)
    {

        if (count == index1)
        {
            element1 = nums1[i];
        }
        if (count == index2)
        {
            element2 = nums1[i];
        }

        count++;
        i++;
    }

    while (j < size2)
    {

        if (count == index1)
        {
            element1 = nums2[j];
        }
        if (count == index2)
        {
            element2 = nums2[j];
        }

        count++;
        j++;
    }

    if ((size1 + size2) % 2 == 1)
    {
        return (element1 / 1.0);
    }

    return (element1 + element2) / 2.0;
}
int main()
{

    return 0;
}