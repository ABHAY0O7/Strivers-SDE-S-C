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

