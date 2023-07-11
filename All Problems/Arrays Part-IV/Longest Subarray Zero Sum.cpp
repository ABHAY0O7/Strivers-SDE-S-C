#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
    int n = arr.size();
    int ans = 0;
    
    map<int, int> m;
    m[0] = -1;
    for (int i = 0; i < n; i++) {
        if(i != 0) arr[i] += arr[i - 1];
        if (m.find(arr[i]) != m.end()) ans = max(ans, i - m[arr[i]]);
        else m[arr[i]] = i;
    }
    return ans;
}
