#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;

	int idx = 0;

	while(idx < n) {
		int i = idx + 1, j = n - 1;
		int sum = K - arr[idx];
		while(i < j) {
			int curr = arr[i] + arr[j];
			if(curr == sum) {
				ans.push_back({arr[idx], arr[i], arr[j]});
				int ni = i;
				while(ni < j && arr[ni] == arr[i]) ni++;
				i = ni;
			} else if(curr < sum) i++;
			else j--;
		}
		int nidx = idx;
		while(nidx < n && arr[idx] == arr[nidx]) nidx++;
		idx = nidx;
	}
	return ans;
}
