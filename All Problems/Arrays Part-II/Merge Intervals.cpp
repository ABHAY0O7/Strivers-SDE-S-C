#include <bits/stdc++.h> 

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> ans{{intervals[0]}};
    int idx = 0;
    for(int i = 1; i < n; i++) {
        if(ans[idx][1] >= intervals[i][0]) ans[idx][1] = max(ans[idx][1], intervals[i][1]);
        else ans.push_back(intervals[i]), idx++;
    }
    return ans;
}

// Second Optimal approach

#include <bits/stdc++.h> 

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    int idx = 0;
    for(int i = 1; i < n; i++) {
        if(intervals[idx][1] >= intervals[i][0]) intervals[idx][1] = max(intervals[i][1], intervals[idx][1]);
        else intervals[++idx] = intervals[i];
    }
    while(intervals.size() > idx + 1) intervals.pop_back();
    return intervals;
}
