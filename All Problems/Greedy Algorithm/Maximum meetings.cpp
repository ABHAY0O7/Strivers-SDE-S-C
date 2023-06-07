#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<vector<int>> v(n);

    for(int i = 0; i < n; i++) v[i] = {end[i], start[i], i + 1};

    int prev = -1;
    sort(v.begin(), v.end(), [&] (vector<int> &a, vector<int> &b) -> bool {
        if(a[0] == b[0]) return a[2] < b[2];
        return a[0] < b[0];
    });

    vector<int> ans;
    for(int i = 0; i < n; i++) if(v[i][1] > prev) ans.push_back(v[i][2]), prev = max(prev, v[i][0]);

    return ans;
}
