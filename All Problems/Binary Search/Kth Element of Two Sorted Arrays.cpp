int solve(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int l = 0, r = min(n - 1, k - 1);
    while(l <= r) {
        int mid = (l + r) / 2;

        int idx = lower_bound(row2.begin(), row2.end(), row1[mid]) - row2.begin();
        int ub = upper_bound(row2.begin(), row2.end(), row1[mid]) - row2.begin();
        if(mid + 1 + idx <= k && mid + 1 + ub >= k) return row1[mid];
        else if (mid + 1 + idx < k) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int ans = solve(row1, row2, n, m, k);
    if(ans == -1) ans = solve(row2, row1, m, n, k);
    return ans;
}
