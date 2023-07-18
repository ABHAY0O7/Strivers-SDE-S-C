#include "bits/stdc++.h"
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> g(n);
    for(auto it : edges) {
        g[it[0]-1].push_back(it[1]-1);
        g[it[1]-1].push_back(it[0]-1);
    }
    vector<int> vis(n);
    function<bool(int, int)> dfs = [&] (int idx, int par) -> bool {
        vis[idx] = 1;
        for(auto it : g[idx]) {
            if(!vis[it]) {
                if(dfs(it, idx)) return 1;
            } else if(it != par) return 1;
        }
        return 0;
    };
    for(int i = 0; i < n; i++) {
      if (!vis[i]) {
        if (dfs(i, -1))
          return "Yes";
      }
    }
    return "No";
}

