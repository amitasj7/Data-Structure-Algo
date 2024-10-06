#include <bits/stdc++.h>
using namespace std;

/*
-1 1 2 6 3
4 2713
 */
bool comp(const vector<int> &a, const vector<int> &b)
{
    return a[2] > b[2];
}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here

    /*
        for (auto it : jobs)
        {
            for (auto it1 : it)
            {
                cout << it1 << " ";
            }
            cout << endl;
        }
     */
    // sort vector according profit
    sort(jobs.begin(), jobs.end(), comp);


    /*
        for (auto it : jobs)
        {
            for (auto it1 : it)
            {
                cout << it1 << " ";
            }
            cout << endl;
        }
     */
    // find maximum deadline no. in all jobs
    int maxi = jobs[0][1];
    int countJobs = 0;
    for (int i = 1; i < jobs.size(); i++)
    {
        maxi = max(maxi, jobs[i][1]);
    }

    // cout << "maxi value : " << maxi << endl;
    // take a  array of maxi size
    vector<int> ans(maxi + 1, -1);
    /*
        for (int i = 0; i <= maxi; i++)
        {
            ans[i] = -1;
        }
     */
    // fill ans vector with
    int maxProfit = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        int j = jobs[i][1];
        while (ans[j] != -1)
        {
            j--;
        }

        if (j == 0)
        {
            continue;
        }

        // fill this value with id
        // cout << "j value : " << j << endl;
        ans[j] = jobs[i][0];
        maxProfit += jobs[i][2];
        countJobs++;
    }

    // print job scheduling idea
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    // return 1. (no. of jobs) 2. (maximum profit)

    return {countJobs, maxProfit};
}
int main()
{
    vector<vector<int>> jobs = {
        {3, 4, 918},
        {2, 2, 857},
        {1, 2, 728},
        {4, 1, 679},
        {5, 1, 340},
        {6, 4, 210},

    };

    vector<int> ans = jobScheduling(jobs);

    for (auto it : ans)
    {
        cout << it << " ";
    }
}
