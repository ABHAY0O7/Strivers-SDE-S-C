#include "bits/stdc++.h"

int cutLogs(int k, int n)
{
    // Write your code

    // function<int(int, int, int)> dfs = [&] (int l, int r, int axes) -> int {
    //     if(l == r) return 0;
    //     if(axes == 1) return r - l;

    //     int ans = 1e8;
    //     int i = (r + l - 1) / 2;
    //     // for(int i = l; i < r; i++) {
    //         int take = dfs(i + 1, r, axes);
    //         int nottake = dfs(l, i, axes-1);
    //         ans = min(ans, 1 + max(take, nottake));
    //     // }
    //     return ans;
    // };
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
    function<int(int, int)> dfs = [&] (int idx, int axes) -> int {
        if(axes == 1) return idx;
        if(idx <= 1) return idx;

        if(dp[idx][axes] != -1) return dp[idx][axes];

        
        int ans = 1e8;

        int l = 1, r = idx;
        while(l <= r) {
            int i = (l + r + 1) / 2;
            int curr1 = 1 + dfs(i - 1, axes - 1);
            int curr2 = 1 + dfs(idx - i, axes);

            ans = min(ans, max(curr1, curr2));

            if(curr1 <= curr2) l = i + 1;
            else r = i - 1; 
        }
        

        // int ans2 = 1 + dfs(nidx - 1, axes);
        // ans2 = max(ans, 1 + dfs(idx - nidx, axes - 1));
        // return dp[idx][axes] = min(ans, ans2);
        return dp[idx][axes] = ans;
    };

    return dfs(n, k);
}

// Second better solution

#include "bits/stdc++.h"
int cutLogs(int k, int n)
{
    // vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
    vector<int> dp(k + 1, 0);
    int moves = 0;
    while(dp[k] < n) {
        moves++;
        for(int i = k; i > 0; i--) dp[i] += 1 + dp[i-1];
    }
    return moves;
}


