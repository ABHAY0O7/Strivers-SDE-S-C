#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> m;
    int n = arr.size();
    int ans = 0;
    int curr = 0;
    for(int i = 0; i < n; i++) {
        m[curr]++;
        curr ^= arr[i];
        int val = curr ^ x;
        ans += m[val];
    }
    return ans;
}
