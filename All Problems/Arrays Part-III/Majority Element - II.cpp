#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    vector<pair<int, int>> v(2);
    v[0] = v[1] = {-1,0};
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        if(v[0].second == 0) v[0] = {arr[i], 1};
        else if(arr[i] == v[0].first) v[0].second++;
        else if(v[1].second == 0) v[1] = {arr[i], 1};
        else if(arr[i] == v[1].first) v[1].second++;
        else v[0].second--, v[1].second--;

        if(v[1].second > v[0].second) swap(v[1], v[0]);
    }

    v[0].second = v[1].second = 0;
    for(auto it : arr) {
        if(it == v[0].first) v[0].second++;
        else if(it == v[1].first) v[1].second++;
    }

    vector<int> ans;
    for(int i = 0; i < 2; i++) if(v[i].second > (n / 3)) ans.push_back(v[i].first);
    return ans;
}
