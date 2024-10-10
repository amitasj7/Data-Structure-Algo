#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {

        int n = quality.size();

        // store max value
        double result = DBL_MAX;

        vector<pair<double, int>> workerRatio(n);

        // find worker ration
        for (int i = 0; i < n; i++)
        {
            pair<double, int> p;
            p.first = (double)(wage[i]) / quality[i];
            p.second = quality[i];

            workerRatio[i] = p;
        }

        // sort workerRatio
        sort(workerRatio.begin(), workerRatio.end());

        priority_queue<int, vector<int>> pq;

        int sumQuality = 0;

        for (int i = 0; i < k; i++)
        {
            pq.push(workerRatio[i].second);

            sumQuality += workerRatio[i].second;
        }

        double managerRatio = workerRatio[k - 1].first;
        result = managerRatio * sumQuality;

        for (int i = k; i < n; i++)
        {
            managerRatio = workerRatio[i].first;

            pq.push(workerRatio[i].second); 
            sumQuality += workerRatio[i].second;

            if (pq.size() > k)
            {
                sumQuality -= pq.top();
                pq.pop();
            }

            // update result with min salary
            result = min(result, managerRatio * sumQuality);
        }

        return result;
    }
};