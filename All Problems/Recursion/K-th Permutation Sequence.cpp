#include "bits/stdc++.h"

string kthPermutation(int n, int k) {
    string ans;
    vector<int> fac(10, 1);
    for(int i = 1; i < n; i++) fac[i] = i * fac[i-1];
    vector<int> vis(n, 0);
    function<void(int, int)> dfs = [&] (int idx, int k) -> void {
        if(idx == n) return;
        int sa = n - idx - 1;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            if(k > fac[sa]) k -= fac[sa];
            else {
                ans.push_back('0' + (i + 1));
                vis[i] = 1;
                dfs(idx + 1, k);
            }
        }
    };
    dfs(0, k);
    return ans;
}

