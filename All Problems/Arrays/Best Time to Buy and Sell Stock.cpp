#include <bits/stdc++.h> 
int maximumProfit(vector<int> &p){
    int mi = p[0];
    int ans = 0;
    for(auto it : p) {
        if(it - mi > ans) ans = it - mi;
        if(it < mi) mi = it;
    }
    return ans;
}
