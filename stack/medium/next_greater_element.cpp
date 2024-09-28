#include <bits/stdc++.h>
using namespace std;


vector<int> nextGreaterElement(vector<int> &arr, int n) {
  vector<int> nge(n, 0);

  stack<int> st;

  for (int i = n - 1; i >= 0; i--) {

    while (!st.empty() && st.top() <= arr[i])
      st.pop();

    // now stack me smaller element hai ya empty hai

    nge[i] = (st.empty() ? -1 : st.top());

    st.push(arr[i]);
  }

  return nge;
}