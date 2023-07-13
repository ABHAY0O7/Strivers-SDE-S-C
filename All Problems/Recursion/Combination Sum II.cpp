#include "bits/stdc++.h"
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	vector<int> curr;
	function<void(int, int)> dfs = [&] (int idx, int sum) -> void {
		if(sum > target) return;
		if(sum == target) {
			ans.push_back(curr);
			return;
		}
		if(idx == n) return;

		// if(idx != 0 && arr[idx] == arr[idx-1]) {

		// 	curr.push_back(arr[idx]);
		// 	dfs(idx + 1, sum + arr[idx]);
		// 	curr.pop_back();
		// }
		// if(curr.empty() || curr.back() != arr[idx]) dfs(idx + 1, sum);

		for(int i = idx; i < n; i++) {
			if(i == idx || arr[i] != arr[i-1]) {
				curr.push_back(arr[i]);
				dfs(i + 1, sum + arr[i]);
				curr.pop_back();
			}
		}
	};
	dfs(0, 0);
	return ans;
}

// Second Solution

#include "bits/stdc++.h"
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	vector<int> curr;

	vector<int> last(31);
	for(int i = 0; i < n; i++) {
		last[arr[i]] = i + 1;
	}
	function<void(int, int)> dfs = [&] (int idx, int sum) -> void {
		if(sum > target) return;
		if(sum == target) {
			ans.push_back(curr);
			return;
		}
		if(idx == n) return;

		curr.push_back(arr[idx]);
		dfs(idx + 1, sum + arr[idx]);
		curr.pop_back();

		dfs(last[arr[idx]], sum);
	};
	dfs(0, 0);
	return ans;
}


