#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    vector<pair<double, int>> v;
    int i = 0;
    for(auto it : items) {
        double ans;
        ans = (double)(it.second) / it.first;
        v.push_back({ans, i++});
    }
    
    sort(v.rbegin(), v.rend());
    double ans = 0;
    int curr = 0;

    for(auto it : v) {
        int idx = it.second;
        if(curr + items[idx].first <= w) {
            ans += items[idx].second;
            curr += items[idx].first;
        } else {
            int rem = w - curr;
            double temp = ((double)rem * items[idx].second / items[idx].first);
            ans += temp;
            break;
        }
    }
    ans = (int) (ans * 100 + .5);
    ans /= 100;
    return ans;
}
