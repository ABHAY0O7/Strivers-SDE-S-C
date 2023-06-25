#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
    function<int(int, int)> dfs = [&] (int idx, int sum) -> int {
        if(sum < 0) return 0;
        if(idx == n) return sum == 0;

        if(dp[idx][sum] != -1) return dp[idx][sum];

        int ans = dfs(idx + 1, sum);
        ans |= dfs(idx + 1, sum - arr[idx]);
        return dp[idx][sum] = ans;
    };
    return dfs(0, k);
}
