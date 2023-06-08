#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int, int>> v;
    
    int n = start.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        v.push_back({finish[i], start[i]});
    }
    sort(v.begin(), v.end());
    int prev = -1;
    for(auto it : v) {
        if(it.second >= prev) ans++, prev = it.first;
    }
    return ans;
}
