#include <bits/stdc++.h> 
vector<string> findPermutations(string &s) {
    vector<string> ans;
    int n = s.size();
    function<void(int)> dfs = [&] (int idx) -> void {
        if(idx == n) {
            ans.push_back(s);
            return;
        }

        for(int i = idx; i < n; i++) {
            swap(s[idx], s[i]);
            dfs(idx + 1);
            swap(s[idx], s[i]);
        }
    };
    dfs(0);
    return ans;
}
