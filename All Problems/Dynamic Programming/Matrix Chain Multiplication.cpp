// First Solution

#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

    function<int(int, int)> dfs = [&] (int l, int r) -> int {
        if(l >= r - 1) return 0;

        int &ret = dp[l][r];
        if(ret != -1) return ret;

        int ans = INT_MAX;

        for(int i = l + 1; i < r; i++) {
            int curr = arr[l] * arr[i] * arr[r];

            curr += dfs(l, i) + dfs(i, r);
            ans = min(ans, curr);
        }
        return ret = ans;
    };

    
    return dfs(0, n - 1);
}
// Second Optimize Solution
#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

    for(int r = 0; r <= n - 1; r++) {
        for(int l = r - 2; l >= 0; l--) {
            int res = INT_MAX;
            for(int i = l + 1; i < r; i++) {
                int curr = arr[l] * arr[i] * arr[r];
                curr += dp[l][i] + dp[i][r];
                res = min(curr, res);
            }
            dp[l][r] = res;
        }
    }
    return dp[0][n-1];
}
