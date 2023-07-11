#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    int i = 0, j = n - 1;
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(m.find(target - arr[i] - arr[j]) != m.end()) return "Yes";
        }
        for(int j = i - 1; j >= 0; j--) {
            m[arr[i] + arr[j]] = 1;
        }
    }
    return "No";
}

