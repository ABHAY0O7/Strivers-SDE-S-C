int calculateMinPatforms(int at[], int dt[], int n) {
    vector<pair<int, int>> time(2400, {0, 0});
    for (int i = 0; i < n; i++) time[at[i]].first++, time[dt[i]].second--;
    int ans = 0, cnt = 0;

    for(auto it : time) {
        cnt += it.first;
        ans = max(ans, cnt);
        cnt += it.second;
    }
    return ans;
}
