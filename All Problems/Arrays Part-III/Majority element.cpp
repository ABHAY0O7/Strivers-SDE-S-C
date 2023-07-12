#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int ans = -1;
	int cnt = 0;

	for(int i = 0; i < n; i++) {
		if(ans == -1) {
			ans = arr[i];
			cnt = 1;
		} else if(arr[i] == ans) cnt++;
		else if(cnt > 1) cnt--;
		else {
			cnt = 0;
			ans = -1;
		}
	}

	cnt = 0;
	for(int i = 0; i < n; i++) if(arr[i] == ans) cnt++;
	return cnt > (n / 2) ? ans : -1;

}
