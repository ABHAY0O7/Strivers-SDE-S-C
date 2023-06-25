#include <bits/stdc++.h> 
int palindromePartitioning(string str) {
    int n = str.size();
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
    function<int(int, int)> dfs = [&] (int idx, int prev) -> int {
        if(idx == n) return prev == n ? 0 : 1e4;

        if(dp[idx][prev] != -1) return dp[idx][prev];

        int ans = dfs(idx + 1, prev);

        int l = prev, r = idx;
        bool flag = true;
        while(l < r) {
            if(str[l] != str[r]) flag = false;
            l++;
            r--;
        }
        if(flag) ans = min(ans, 1 + dfs(idx + 1, idx + 1));

        return dp[idx][prev] = ans; 
    };

    return dfs(0, 0) - 1;
}

