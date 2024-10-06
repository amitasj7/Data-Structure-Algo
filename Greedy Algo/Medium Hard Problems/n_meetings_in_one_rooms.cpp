#include <bits/stdc++.h>
using namespace std;

class type
{
public:
    int start_time;
    int end_time;
    int position;
};

bool comp(const type &a, const type &b)
{
    if (a.end_time == b.end_time)
    {
        return (a.position < b.position);
    }
    // if they are not equal then
    return (a.end_time < b.end_time);
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int size = start.size();

    type meet[size];

    // intialize meet complete
    for (int i = 0; i < size; i++)
    {
        meet[i].start_time = start[i];
        meet[i].end_time = end[i];
        meet[i].position = i + 1;
    }

    // sort meet corresponding end_time accordingly

    sort(meet, meet + size, comp);

    vector<int> ans;
    // first sort meet always helding
    ans.push_back(meet[0].position);

    // take end_time of every meet
    int limit = meet[0].end_time;
    // choose others meet using loop method

    for (int i = 1; i < size; i++)
    {
        if (limit < meet[i].start_time)
        {
            ans.push_back(meet[i].position);

            // update limit value
            limit = meet[i].end_time;
        }
    }

    return ans.size();
}