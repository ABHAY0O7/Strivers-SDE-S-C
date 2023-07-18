#include "bits/stdc++.h"
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>> g(n);
    for(auto it : edges) {
        g[it.first-1].push_back(it.second-1);
    }
    vector<int> vis(n, 0);
    function<bool(int, int)> dfs = [&] (int idx, int par) -> bool {
        vis[idx] = 2;
        for(auto it : g[idx]) {
            if(vis[it] == 0) {
                if(dfs(it, idx)) return 1;
            } else if(vis[it] == 2) return 1;
        }
        vis[idx] = 1;
        return 0;
    };
    for(int i = 0; i < n; i++) {
      if(!vis[i]) {
        if(dfs(i, -1)) return 1;
      }
    }
    return 0;
}
