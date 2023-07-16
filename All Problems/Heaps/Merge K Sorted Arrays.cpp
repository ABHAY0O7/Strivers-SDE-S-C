#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    vector<int> temp(k, 0);
    int idx = -1;
    while(true) {
        int nidx = -1;
        int prev = INT_MAX;
        for(int i = 0; i < k; i++) {
            if(temp[i] < kArrays[i].size() && prev > kArrays[i][temp[i]]) {
                prev = kArrays[i][temp[i]];
                nidx = i;
            }
        }
        if(nidx == -1) break;
        ans.push_back(prev);
        temp[nidx]++;
    }
    return ans;
}

// Optimize solution
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i = 0; i < k; i++) if(kArrays[i].size()) pq.push({kArrays[i][0], {i, 0}});
    
    while(!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        int val = v.first;
        int i = v.second.first;
        int j = v.second.second;
        ans.push_back(val);
        if(j + 1 < kArrays[i].size()) pq.push({kArrays[i][j+1], {i, j + 1}});
    }
    return ans;
}

