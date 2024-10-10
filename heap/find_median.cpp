
#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        // insert into maxHeap 1. empty 2. num < top element
        if (maxHeap.empty() || maxHeap.top() >= num)
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        // balance process

        if (maxHeap.size() > minHeap.size() + 1)
        {
            int element = maxHeap.top();
            maxHeap.pop();
            minHeap.push(element);
        }
        else if (maxHeap.size() < minHeap.size())
        {
            int element = minHeap.top();
            minHeap.pop();
            maxHeap.push(element);
        }
    }

    double findMedian()
    {

        if (maxHeap.size() == minHeap.size())
            return double(maxHeap.top() / 2.0 + minHeap.top() / 2.0);

        else
            return (double)maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */