#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
    int cnt = 1;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1] + 1) cnt++;
        else if(arr[i] == arr[i-1]) ;
        else if(ans < cnt) {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    return ans;
}
