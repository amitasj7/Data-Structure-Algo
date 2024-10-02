#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{

    int high = numbers.size() - 1;
    int low = 0;

     while (low < high)
    {

        if (numbers[low] + numbers[high] == target)
        {
            return {low + 1, high + 1};
        }
        else if (numbers[low] + numbers[high] < target)
        {
            low++;
        }
        else
        {
            high--;
        }
    }

    return {-1, -1};
}
int main()
{

    return 0;
}