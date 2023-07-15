long long getTrappedWater(long long* arr, int n) {
    #define ll long long
    vector<ll> pre(n), suff(n);
    ll curr = -1e18;

    for(int i = 0; i < n; i++) {
        pre[i] = curr;
        curr = max(curr, arr[i]);
    }
    curr = -1e18;
    for(int i = n - 1; i >= 0; i--) {
        suff[i] = curr;
        curr = max(curr, arr[i]);
    }

    ll ans = 0;
    for(int i = 1; i < n - 1; i++) {

        ans += max(0ll, min(pre[i], suff[i]) - arr[i]);
    }
    return ans;
}

// Optimize solution

long long getTrappedWater(long long* arr, int n) {
    #define ll long long
    ll i = 0, lmax = 0, j = n - 1, rmax = 0;
    ll ans = 0;
    while(i <= j) {
        if(arr[i] <= arr[j]) {
            lmax = max(lmax, arr[i]);
            ans += max(0ll, lmax - arr[i]);
            i++;
        } else {
            rmax = max(arr[j], rmax);
            ans += max(0ll, rmax - arr[j]);
            j--;
        }
    }
    return ans;
}
