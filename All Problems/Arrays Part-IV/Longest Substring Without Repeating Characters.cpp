#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    int i = 0, j = 0;
    int n = s.size();
    vector<int> cnt(26, 0);
    int ans = 0;
    while(j < n) {
        int idx = s[j] - 'a';
        while(cnt[idx] == 1) cnt[s[i++]-'a']--;
        cnt[idx] = 1;
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}
