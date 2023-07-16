#include "bits/stdc++.h"
void findMedian(int *arr, int n)
{
    if(n == 0) return;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int ans = arr[0];
    pq1.push(ans);
    cout << ans << " ";
    for(int i = 1; i < n; i++) {
        if(arr[i] > ans) {
            pq2.push(arr[i]);
            if(pq2.size() - pq1.size() > 1) {
                pq1.push(pq2.top());
                pq2.pop();
            }
        } else {
            pq1.push(arr[i]);
            if(pq1.size() - pq2.size() > 1) {
                pq2.push(pq1.top());
                pq1.pop();
            }
        }

        if(i % 2) ans = (pq1.top() + pq2.top()) / 2;
        else if(pq1.size() > pq2.size()) ans = pq1.top();
        else ans = pq2.top();
        cout << ans << " ";
    }
}
