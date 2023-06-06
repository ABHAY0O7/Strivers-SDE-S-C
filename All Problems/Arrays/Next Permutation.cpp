#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &p, int n)
{
    int idx = 0;
    for(int i = n - 1; i >= 1; i--) {
        if(p[i] > p[i-1]) {
            idx = i;
            break;
        }
    }
    sort(p.begin() + idx, p.end());

    if(idx == 0) return p;

    for(int i = idx; i < n; i++) {
        if(p[i] > p[idx-1]) {
            swap(p[i], p[idx-1]);
            break;
        }
    }
    return p;
}
