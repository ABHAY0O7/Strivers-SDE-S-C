#include <bits/stdc++.h> 
int get(int i, int j, int n) {
  return i * n + j;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> ans;
    vector<int> curr(n*n);
    vector<int> del= {-1, 0, 1, 0, -1};
    function<void(int, int)> dfs = [&] (int i, int j) -> void {
      if(i < 0 || j < 0 || i >= n || j >= n) return;
      if(maze[i][j] == 0) return;
      int idx = get(i, j, n);
      if(curr[idx]) return;

      curr[idx] = 1;
      if(idx == n * n - 1) {
        ans.push_back(curr);
        curr[idx] = 0;
        return;
      }

      for (int k = 0; k < 4; k++) {
        int x = i + del[k];
        int y = j + del[k+1];
        dfs(x, y);
      }
      curr[idx] = 0;
    };
    dfs(0, 0);
    return ans;
}
