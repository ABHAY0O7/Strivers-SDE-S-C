#include "bits/stdc++.h"
string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<int> col(n+1, 0);
    function<bool(int, int)> dfs = [&] (int idx, int par) -> bool {
        for(int i = 1; i <= m; i++) {
            if(col[par] == i) continue;
            col[idx] = i;
            int ans = 1;
            for(int j = 1; j <= n; j++) {
                if(mat[idx-1][j-1] == 0) continue;
                if(col[j] != 0 && col[j] == col[idx]) ans = 0;
                if(col[j] == 0) ans &= dfs(j, idx);
                if(!ans) break;
            }
            if(ans) return 1;
        }
        return 0;
    };
    for(int i = 1; i <= n; i++) {
        if(!dfs(i, 0)) return "NO";
    }
    return "YES";
}
