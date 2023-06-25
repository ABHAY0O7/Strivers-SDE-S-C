#include "bits/stdc++.h"
long countWaysToMakeChange(int *d, int n, int value)
{
    #define ll long long
    vector<vector<ll>> dp(n + 1, vector<ll> (value + 1, -1));
    function<ll(int, int)> dfs = [&] (int idx, int sum) -> ll {
        if(sum < 0) return 0;
        if(idx == n) return sum == 0;

        if(dp[idx][sum] != -1) return dp[idx][sum];
        ll ans = dfs(idx + 1, sum);
        ans += dfs(idx, sum - d[idx]);
        return dp[idx][sum] = ans;
    };
    return dfs(0, value);
}
