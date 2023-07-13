#include "bits/stdc++.h"

int get(int r, int col, int n) {
    return r * n + col;
}

vector<vector<int>> solveNQueens(int n) {
    if(n == 1) return {{1}};
    if(n <= 3) return {{}};
    vector<int> col(n);
    vector<vector<int>> ret;
    vector<int> ans(n * n);
    
    
    function<void(int)> dfs = [&] (int idx) -> void {
        if(idx == n) {
            ret.push_back(ans);
            return;
        }

        for(int j = 0; j < n; j++) {
            if(col[j]) continue;

            bool flag = 0;
            for(int ii = idx, jj = j; ii >= 0 && jj >= 0; ii--, jj--) {
                int curr = get(ii, jj, n);
                if(ans[curr]) flag = 1;
            }
            for(int ii = idx, jj = j; ii >= 0 && jj < n; ii--, jj++) {
                int curr = get(ii, jj, n);
                if(ans[curr]) flag = 1;
            }

            if(flag) continue;
            int curr = get(idx, j, n);
            ans[curr] = 1;
            col[j] = 1;
            dfs(idx + 1);
            ans[curr] = 0;
            col[j] = 0;
        }
    };

    dfs(0);
    return ret;
}
