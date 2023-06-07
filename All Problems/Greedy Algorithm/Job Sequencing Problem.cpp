#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    multiset<int> s;
    sort(jobs.begin(), jobs.end());
    int n = jobs.size(), ans = 0;
    for(int i = 0; i < n; i++) {
        if(s.size() < jobs[i][0]) s.insert(jobs[i][1]);
        else if((*s.begin()) < jobs[i][1]) s.erase(s.begin()), s.insert(jobs[i][1]);
    }
    for(auto it : s) ans += it;
    return ans;
}

