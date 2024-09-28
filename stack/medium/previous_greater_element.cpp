#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<int> previousGreaterElement(int n, int arr[]){

      vector<int>pge(n,0); 
      stack<int>st; 

      for(int i = 0; i<n; i++){  

          while(!st.empty() && st.top() <= arr[i]){  
            st.pop(); 
          }

          // stack me smaller element hai ya empty hai 
          pge[i] = (st.empty() ? -1 : st.top()); 

        st.push(arr[i]); 
      }


      return pge; 
        

    }
};