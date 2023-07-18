#include "bits/stdc++.h"

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();
	vector<vector<int>> g(n);
	vector<int> vis(n, -1);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(edges[i][j]) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}

	function<bool(int, int, int)> dfs = [&] (int idx, int par, int col) -> bool {
		vis[idx] = col;

		for(auto it : g[idx]) {
			if(vis[it] == -1) {
				if(dfs(it, idx, 1 - col)) return 1;
			} else if(vis[it] == col) return 1;
		}
		return 0;
	};

	for(int i = 0; i < n; i++) {
		if(vis[i] == -1) {
			if(dfs(i, -1, 0)) return 0;
		}
	}
	return 1;
}
