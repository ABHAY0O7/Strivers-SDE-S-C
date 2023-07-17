#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> ans(n, -1);
    stack<int> st;
    arr.push_back(-1);
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
