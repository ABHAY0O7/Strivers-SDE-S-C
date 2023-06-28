bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size(), m = mat[0].size();
    int l = 0, r = n * m - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        int i = (mid) / m;
        int j = (mid) % m;

        if(mat[i][j] == target) return 1;
        if(mat[i][j] > target) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}
