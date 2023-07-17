#include <bits/stdc++.h> 
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    vector<vector<int>> g(V);
    for(int i = 0; i < edges.size(); i++) {
        g[edges[i].second].push_back(edges[i].first);
        g[edges[i].first].push_back(edges[i].second);
    }
    for(int i = 0; i < V; i++) sort(g[i].begin(), g[i].end());
    vector<int> vis(V), curr;
    function<void(int)> bfs = [&] (int idx) -> void {
        queue<int> q;
        q.push(idx);
        vis[idx] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            curr.push_back(node);
            for(auto it : g[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    };
    for(int i = 0; i < V; i++) {
        
        if(!vis[i]) bfs(i);
    }
    return curr;
}
