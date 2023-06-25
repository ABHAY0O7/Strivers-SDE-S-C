#include <bits/stdc++.h> 
bool wordBreak(vector < string > & arr, int m, string & target) {
    int n = target.size();
    vector<vector<bool>> can(n + 1, vector<bool> (n + 1, 0));
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        string temp;    
        for(int j = i; j < n; j++) {
            temp.push_back(target[j]);
            auto it = lower_bound(arr.begin(), arr.end(), temp);
            if(it != arr.end() && *it == temp) can[i][j] = 1;
        }
    }
    
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
    function<int(int, int)> dfs = [&] (int idx, int prev) -> int {
        if(idx == n) return prev == n;

        if(dp[idx][prev] != -1) return dp[idx][prev];

        int ans = dfs(idx + 1, prev);
        if(can[prev][idx]) ans |= dfs(idx + 1, idx + 1);
        return dp[idx][prev] = ans;
    };

    return dfs(0, 0);
}
