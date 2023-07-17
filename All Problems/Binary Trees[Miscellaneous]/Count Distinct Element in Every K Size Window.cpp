#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    map<int, int> m;
    vector<int> ans;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        m[arr[i]]++;
        if(i >= k) if(--m[arr[i-k]] == 0) m.erase(m.find(arr[i-k]));

        if(i >= k - 1) ans.push_back(m.size());
    }
    return ans;
}

