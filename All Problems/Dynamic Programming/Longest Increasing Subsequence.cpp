// First Solution

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    set<int> s;
    for(int i = 0 ; i < n; i++) {
        auto itr = s.lower_bound(arr[i]);
        if(itr == s.end()) s.insert(arr[i]);
        else {
            s.erase(itr);
            s.insert(arr[i]);
        }
    }
    return s.size();
}


// Second Solution

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> ans;
    // int n = arr.size();
    for (int i = 0; i < n; i++) {
        auto it
            = lower_bound(ans.begin(), ans.end(), arr[i]);
        if (it == ans.end()) {
            ans.push_back(arr[i]);
        }
        else {
            *it = arr[i];
        }
    }
    return ans.size();
}

// Third optimize Solution

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> ans;
    // int n = arr.size();
    for (int i = 0; i < n; i++) {
        if(ans.empty() || ans.back() < arr[i]) ans.push_back(arr[i]);
        else {
            auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
            if(it != ans.end()) *it = arr[i];
        }
    }
    return ans.size();
}


// Fourth optimize (in-place) solution

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // vector<int> ans;
    // int n = arr.size();
    int idx = 1;
    for (int i = 1; i < n; i++) {
        int val = arr[i];
        if(arr[idx-1] < val) arr[idx++] = val;
        else {
            auto it = lower_bound(arr, arr + idx, val) - arr;
            if(it < idx) arr[it] = val;
        }
    }
    return idx;
}

