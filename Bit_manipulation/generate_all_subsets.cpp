#include <bits/stdc++.h>
using namespace std;

// applicable only for vec.size() <=15
void printAllSubsets(vector<int> vec)
{
    int size = vec.size();

    // catch all number of subsets
    int numberOfSubets = 1 << size;
    vector<int> ds;
    for (int i = 0; i < (numberOfSubets); i++)
    {

        for (int bits = 0; bits < size; bits++)
        {
            // chech bits set or not
            if (i & (1 << bits))
            {
                ds.push_back(vec[bits]);
            }
        }
        // print ds
        cout << "{ ";
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << "}" << endl;

        ds.clear();
    }
}
int main()
{
    vector<int> v = {3, 2, 4,9,0};

    printAllSubsets(v);

    return 0;
}