vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> g(V), ans;
    for(int i = 0; i < E; i++) {
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> vis(V), curr;
    function<void(int)> dfs = [&] (int idx) -> void {
        vis[idx] = 1;
        curr.push_back(idx);
        for(auto it : g[idx]) if(!vis[it]) dfs(it);
    };
    for(int i = 0; i < V; i++) {
        
        if(!vis[i]) curr.clear(), dfs(i), ans.push_back(curr);
    }
    return ans;
}
