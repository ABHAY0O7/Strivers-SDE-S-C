#include "bits/stdc++.h"
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> curr;

    function<void(int, int)> dfs = [&] (int idx, int sum) -> void {
        if(idx == n) {
            if(sum == k) ans.push_back(curr);
            return;
        }

        dfs(idx + 1, sum);
        curr.push_back(arr[idx]);
        dfs(idx + 1, sum + arr[idx]);
        curr.pop_back();
    };
    dfs(0, 0);
    return ans;
}
