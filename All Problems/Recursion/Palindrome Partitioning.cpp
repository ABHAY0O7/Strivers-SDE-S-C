#include <bits/stdc++.h> 
vector<vector<string>> partition(string &s) 
{
    if(s.size() == 0) return {{}};
    vector<vector<string>> ans;
    vector<string> v;
    string curr;
    int n = s.size();
    function<bool(string&)> palin = [&] (string &s) -> bool {
        int m = s.size();
        for(int i = 0; i < m; i++) {
            if(s[i] != s[m-i-1]) return 0;
        }
        return 1;
    };
    function<void(int)> dfs = [&] (int idx) -> void {
        if(idx == n) {
            if(!curr.empty() && palin(curr)) {
                v.push_back(curr);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }

        curr.push_back(s[idx]);
        dfs(idx + 1);
        if(palin(curr)) {
            v.push_back(curr);
            curr.clear();
            dfs(idx + 1);
            curr = v.back();
            v.pop_back();
        }
        curr.pop_back();
    };

    dfs(0);
    return ans;
}

// Optimize Solution

#include <bits/stdc++.h> 
vector<vector<string>> partition(string &s) 
{
    if(s.size() == 0) return {{}};
    vector<vector<string>> ans;
    vector<string> v;
    string curr;
    int n = s.size();
    function<bool(int, int)> palin = [&] (int i, int j) -> bool {
        while(i < j) {
            if(s[i++] != s[j--]) return 0;
        }
        return 1;
    };
    function<void(int, int)> dfs = [&] (int idx, int prev) -> void {
        if(idx == n) {
            if(prev != n && palin(prev, idx - 1)) {
                v.push_back(s.substr(prev, idx - prev));
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }

        dfs(idx + 1, prev);
        if(palin(prev, idx)) {
            v.push_back(s.substr(prev, idx - prev + 1));
            dfs(idx + 1, idx + 1);
            v.pop_back();
        }
    };

    dfs(0, 0);
    return ans;
}


