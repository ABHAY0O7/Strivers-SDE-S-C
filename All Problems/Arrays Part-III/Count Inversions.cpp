#include <bits/stdc++.h> 
#define ll long long

ll merge(ll *arr, int l, int mid, int r) {
    vector<int> temp;
    ll ans = 0;

    int i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else ans += (mid - i + 1), temp.push_back(arr[j++]);
    }

    while(i <= mid) temp.push_back(arr[i++]);
    while(j <= r) temp.push_back(arr[j++]);
    
    for(int k = l; k <= r; k++) arr[k] = temp[k-l];
    return ans;
}

ll solve(ll *arr, int l, int r) {
    ll ans = 0;
    if(l >= r) return 0;
    int mid = (l + r) / 2;

    ans += solve(arr, l, mid);
    ans += solve(arr, mid + 1, r);

    ans += merge(arr, l, mid, r);

    return ans;
}
long long getInversions(long long *arr, int n){
    ll ans = 0;

    return solve(arr, 0, n - 1);
}
