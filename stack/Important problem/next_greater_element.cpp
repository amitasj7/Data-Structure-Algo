#include <bits/stdc++.h>
using namespace std;

int index(vector<int> &nums2, int ele)
{
    int size = nums2.size();

    // find element position
    auto it = find(nums2.begin(), nums2.end(), ele);

    // element permanently present hoga
    return distance(nums2.begin(), it);
}
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    stack<int> st;
    vector<int> nge;
    cout << "hello2" << endl;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        // if (st.empty())
        // {
        //     nge[i] = -1;
        // }
        cout << i << endl;
        if ((!st.empty()) && (st.top() > nums2[i]))
        {
            nge[i] = st.top();
        }
        else
        {
            while (!st.empty() && (st.top() <= nums2[i]))
            {
                st.pop();
            }
            if (!st.empty())
            {
                nge[i] = st.top();
            }
            // for empty case;
            else
            {
                nge[i] = -1;
            }
        }

        // push element in stack
        st.push(nums2[i]);
        cout << "element push: " << nums2[i] << endl;
    }

    // find nums1 element index in nums2
    for (int i = 0; i < nums1.size(); i++)
    {
        nums1[i] = nge[index(nums2, nums1[i])];
    }

    return nums1;
}
vector<int> nextGreaterElement2(vector<int> &nums1)
{
    // next greater Element for a circular array

    int n = nums1.size();
    vector<int> ans(n);

    stack<int> st;

    // take a double size array value
    for (int i = (2 * n - 1); i >= 0; i--)
    {
        if (!st.empty() && st.top() > nums1[i % n])
        {
            // it is a right condition
            ans[i % n] = st.top();
        }
        else
        {
            while (!st.empty() && st.top() <= nums1[i % n])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i % n] = -1;
            }
            else
            {
                ans[i % n] = st.top();
            }
        }

        // push element
        st.push(nums1[i % n]);
    }

    return ans;
}

int main()
{
    // vector<int> nums1 = {2, 4};
    // vector<int> nums2 = {1, 2, 3, 4};
    // cout << "hello" << endl;
    // vector<int> v = nextGreaterElement(nums1, nums2);

    // for (auto it : v)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    vector<int> nums1 = {2, 10, 12, 1, 11};
    vector<int> v = nextGreaterElement2(nums1);

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}