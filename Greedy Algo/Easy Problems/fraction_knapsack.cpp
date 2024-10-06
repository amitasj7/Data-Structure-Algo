
#include <bits/stdc++.h>
using namespace std;

bool valuebywidth(const pair<int, int> a, const pair<int, int> b)
{

    double value1 = (double)a.second / (double)a.first;
    double value2 = (double)b.second / (double)b.first;

    return value1 > value2;
    // return in decreasing order
}

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{

    // items.first == value
    // items.second == weight

    // sort items with their
    // 1. weights accordingly
    // 2. decreasing order
    sort(items.begin(), items.end(), valuebywidth);
    /*
        // print all sort items
        for (auto i : items)
        {
            cout << i.first << " " << i.second << endl;
        }
         */
    double finalmaxvalue = 0;

    int i = 0;
    while (w > 0 && i < n)
    {

        // complete value insert
        if (items[i].first <= w)
        {
            finalmaxvalue += items[i].second;

            // update bag weight
            w -= items[i].first;
        }
        // part of that value
        else
        {
            double valuePerWeight = (double)items[i].second / (double)items[i].first;

            double lastValue = valuePerWeight * w;
            cout << "vpw : " << valuePerWeight << " lV : " << lastValue << " w: " << w << endl;
            finalmaxvalue += lastValue;

            // update weight
            w = 0;
        }
        cout << "finalvalue: " << finalmaxvalue << endl;
        i++;
    }

    return finalmaxvalue;
}

int main()
{
    vector<pair<int, int>> items;
    items.push_back({50, 40});
    items.push_back({40, 50});
    items.push_back({90, 25});
    items.push_back({120, 100});
    items.push_back({10, 30});
    items.push_back({200, 45});

    cout << maximumValue(items, 6, 200) << endl;
}