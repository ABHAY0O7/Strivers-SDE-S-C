#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    #define ll long long int

    ll ans = 0, curr = 0;
    for(int i = 0; i < n; i++) {
        curr = max((ll)arr[i], curr + (ll)arr[i]);
        ans = max(ans, curr);
    }
    if(ans < 0) ans = 0;
    return ans;
}
