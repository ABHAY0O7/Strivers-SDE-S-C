#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
    #define ll long long int
    
    vector<vector<ll>> ans;
    vector<ll> curr;

    for(int i = 0; i < n; i++) {
        ll sa = curr.size();

        for(ll j = sa - 1; j > 0; j--) curr[j] += curr[j-1];
        
        curr.push_back(1);
        ans.push_back(curr);
    }
    return ans;
}

