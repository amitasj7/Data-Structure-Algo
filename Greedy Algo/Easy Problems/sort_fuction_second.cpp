// C++ program to demonstrate sorting in vector
// of pair according to 2nd element of pair
#include <bits/stdc++.h>
using namespace std;

// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    cout << "a values: " << a.first << " " << a.second << endl;
    cout << "b values: " << b.first << " " << b.second << endl;
    double value1 = (double)a.second / a.first;
    double value2 = (double)b.second / b.first;

    // phle badi value aaigi then chhoti value aaigi == decreasing order
    return (value1 > value2);
}

int main()
{
    // declaring vector of pairs
    vector<pair<int, int>> vect;

    // Initialising 1st and 2nd element of pairs
    // with array values
    int arr[] = {6, 1, 5, 3};
    int arr1[] = {3, 6, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Entering values in vector of pairs
    for (int i = 0; i < n; i++)
        vect.push_back(make_pair(arr[i], arr1[i]));

    // Printing the original vector(before sort())
    cout << "The vector before sort operation is:\n";
    for (int i = 0; i < n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }

    // Using sort() function to sort by 2nd element
    // of pair
    sort(vect.begin(), vect.end(), sortbysec);

    // Printing the sorted vector(after using sort())
    cout << "The vector after sort operation is:\n";
    for (int i = 0; i < n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }
    return 0;
}
