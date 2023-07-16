#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    int n = v.size();
    for(int i = 0; i <(1 << n); i++) {
        vector<int> curr;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) curr.push_back(v[j]);
        }
        ans.push_back(curr);
    }
    return ans;
}
