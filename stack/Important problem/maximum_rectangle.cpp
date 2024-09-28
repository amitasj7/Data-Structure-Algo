#include <bits/stdc++.h>
using namespace std;

// 1. Brute force

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        int n = heights.size();

        int maxArea = 0;

        for (int ind = 0; ind < n; ind++)
        {

            int left = -1;
            int right = n;

            // find left smaller element place
            for (int j = ind - 1; j >= 0; j--)
            {

                if (heights[j] < heights[ind])
                {
                    left = j;
                    break; // aage ke liye check nahi krna hai
                }
            }

            // find right smaller element place
            for (int j = ind + 1; j < n; j++)
            {

                if (heights[ind] > heights[j])
                {
                    right = j;
                    break;
                }
            }

            int w = right - left - 1;
            int h = heights[ind];

            // update maxarea
            maxArea = max(maxArea, w * h);
        }
        return maxArea;
    }
};

// M-2:

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        // area = h*w
        // h = heights[i]
        // w = right - left -1

        vector<int> leftsmall(n, -1); // {-1,-1,-1,-1}
        vector<int> rightsmall(n, n); // {6,6,6,6}

        stack<int> st;

        // fill left small , find every ith element ke liye small
        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                // pop that element from stack
                st.pop();
            }

            if (!st.empty())
            {
                // if not empty that fill top index ;
                leftsmall[i] = st.top();
            }
            // push index of that number in stack
            st.push(i);
        }

        // stack empty kare
        // fir se use krna hai
        while (!st.empty())
        {
            st.pop();
        }

        // fill right small, find every ith element ke liye right small find kare
        for (int i = n - 1; i >= 0; i--)
        {

            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                // pop that element from stack
                st.pop();
            }

            if (!st.empty())
            {
                // if not empty that fill top index - 1;
                rightsmall[i] = st.top();
            }
            // push index of that number in stack
            st.push(i);
        }

        int maxArea = 0;
        // area = width * height;

        for (int i = 0; i < n; i++)
        {
            int width = rightsmall[i] - leftsmall[i] - 1;
            int ht = heights[i];

            maxArea = max(maxArea, (width * ht));
        }

        return maxArea;
    }
};

// M-3:
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        heights.push_back(0); // at last for remaining element

        int n = heights.size();

        int maxArea = 0;

        stack<int> st; // store index

        for (int ind = 0; ind < n; ind++)
        {

            // stack ke top elemet ki right bounday current element hoga if
            while (!st.empty() && heights[st.top()] > heights[ind])
            {
                int check = st.top();
                st.pop();

                int left = -1;
                int right = n;

                right = ind;

                if (!st.empty())
                    left = st.top();

                int w = right - left - 1;
                int h = heights[check];

                maxArea = max(maxArea, w * h);
            }

            st.push(ind);
        }

        return maxArea;
    }
};

int main()
{

    // vector<int> height = {2, 1, 5, 6, 2, 3, 1};
    vector<int> height = {0, 9};
    // cout << largestRectangleArea(height) << endl;

    return 0;
}