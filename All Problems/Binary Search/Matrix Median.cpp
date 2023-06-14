#include "bits/stdc++.h"
int getMedian(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    function<int(int, int)> cnt = [&] (int val, int idx) -> int {
        int l = 0, r = m - 1;
        int ans = m;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(mat[idx][mid] > val) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    };

    int l = 1e9, r = 0;
    for(int i = 0; i < n; i++) {
        l = min(mat[i][0], l);
        r = max(r, mat[i][m-1]);
    }

    int tot = (n * m) / 2;
    while(l <= r) {
        int mid = (l + r) / 2;

        int curr = 0;
        for(int i = 0; i < n; i++) curr += cnt(mid, i);

        if(curr <= tot) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
