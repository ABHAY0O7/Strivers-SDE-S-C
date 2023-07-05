#include <bits/stdc++.h> 
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(arr[i] > 2 * arr[j]) ans++;
		}
	}
	return ans;
}

// Second solution

#include <bits/stdc++.h> 
int ans;

void merge(vector<int> &arr, int i, int mid, int j) {

	vector<int> temp;

	int x = i, y = mid + 1;
	// cout << i << " " << mid << " " << j << endl;

	int ex = mid, ey = j;
	while(ex >= i && ey > mid) {
		if(arr[ex] > arr[ey] * 2) ans += (ey - mid), ex--;
		else ey--;
	}

	while(x <= mid && y <= j){
		if(arr[x] <= arr[y]) temp.push_back(arr[x++]);
		else temp.push_back(arr[y++]);
	}
	while (x <= mid) temp.push_back(arr[x++]);

	while(y <= j) temp.push_back(arr[y++]);
	// for(auto it : temp) cout << it << " "; cout << endl;
	// cout << "ans " << ans << endl;

	for(int z = i; z <= j; z++) {
		arr[z] = temp[z-i];
	}
}

void solve(vector<int> &arr, int i, int j) {
	if(i >= j) return;

	int mid = (i + j) / 2;

	solve(arr, i, mid);
	solve(arr, mid + 1, j);

	merge(arr, i, mid, j);
}


int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	ans = 0;
	solve(arr, 0, n-1);
	return ans;
}
