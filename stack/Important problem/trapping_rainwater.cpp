/*
1. vec[0] = 9; ye only get and update krne ke liye hi use krna hai
value insert krne ke liye vec.push_back(9) ka use krna hai
2. vector initialization methods total 7
 */
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int result = 0;
    int left = 0, right = height.size() - 1;
    int leftmax = 0, rightmax = 0;

    // run loop left and right;
    while (left <= right)
    {
        // left se left wala pani store krege
        if (height[left] <= height[right])
        {
            // pani store nahi krega yadi
            if (height[left] >= leftmax)
            {
                // update leftmax
                leftmax = height[left];
                // cout << "leftmax: " << leftmax << endl;
            }
            else
            {
                // pani store hoga
                // cout << "result: " << result << endl;
                result += leftmax - height[left];
            }
            // increse left
            left++;
        }
        else
        {

            // right se right ka pani store krege
            // pani store nahi krega yadi
            if (height[right] >= rightmax)
            {
                // update leftmax
                rightmax = height[right];
                // cout << "rightmax: " << rightmax << endl;
            }
            else
            {
                // pani store hoga
                // cout << "result: " << result << endl;
                result += rightmax - height[right];
            }
            // increse left
            right--;
        }
    }
    return result;
}
int trap1(vector<int> &height)
{
    int n = height.size();
    // cout << "in" << endl;
    // complete prefix and suffix
    vector<int> prefix(n, 0);
    vector<int> suffix(n, 0);
    // cout << "in" << endl;
    // fill first element of prefix
    prefix[0] = height[0];
    // prefix.push_back(height[0]);
    // cout << "in" << endl;
    // cout << prefix[0] << endl;

    // fill last element of suffix
    suffix[n - 1] = height[n - 1];
    // cout << suffix[n - 1] << endl;

    for (int i = 1; i < n; i++)
    {

        prefix[i] = max(prefix[i - 1], height[i]);
        suffix[n - 1 - i] = max(suffix[n - i], height[n - 1 - i]);
    }

    // cout << "prefix: ";
    // for (auto it : prefix)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    // cout << "suffix: ";
    // for (auto it : suffix)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    int totalwater = 0;
    // 0th and last building kabhi bhi water store nahi karegi
    for (int i = 1; i <= n - 2; i++)
    {
        totalwater += (min(prefix[i], suffix[i]) - height[i]);
    }

    return totalwater;
}
int main()
{
    vector<int> build = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // cout << "hello" << endl;

    cout << trap1(build) << endl;

    return 0;
}