#include "bits/stdc++.h"
int ans;
vector<int> dx = {-1, 0, 1, 0, -1, 1, 1, -1};
vector<int> dy = {0, 1, 0, -1, -1, -1, 1, 1};
int n, m;
void dfs(int x, int y, int** arr) {
   if(x < 0 || y < 0 || x >= n || y >= m) return;
   if(!arr[x][y]) return;
   arr[x][y] = 0;
   for (int i = 0; i < 8; i++) {
      dfs(x + dx[i], y + dy[i], arr);
   }
}
int getTotalIslands(int** arr, int nn, int mm)
{
   ans = 0;
   n = nn;
   m = mm;
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         if(arr[i][j] == 1) dfs(i, j, arr), ans++;
      }
   }
   return ans;
}

