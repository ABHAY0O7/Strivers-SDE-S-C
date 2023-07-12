#include <bits/stdc++.h> 
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    set<vector<int>> ans;

    vector<int> curr;
    function<void(int)> dfs = [&] (int idx) -> void {
        if(idx == n) {
            ans.insert(curr);
            return;
        }
        dfs(idx + 1);
        curr.push_back(arr[idx]);
        dfs(idx + 1);
        curr.pop_back();
    };
    dfs(0);
    vector<vector<int>> res(ans.begin(), ans.end());
    return res;
}

// Optimized solution
#include <bits/stdc++.h> 
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    vector<int> curr;
    function<void(int)> dfs = [&] (int idx) -> void {
        ans.push_back(curr);
        for (int i = idx; i < arr.size(); i++) {
            if (i != idx && arr[i] == arr[i - 1]) continue;
            curr.push_back(arr[i]);
            dfs(i + 1);
            curr.pop_back();
        }
    };
    dfs(0);
    // sort(ans.begin(), ans.end());
    // vector<vector<int>> res(ans.begin(), ans.end());
    return ans;
}
