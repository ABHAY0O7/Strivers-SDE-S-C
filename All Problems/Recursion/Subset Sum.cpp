#include "bits/stdc++.h"
vector<int> subsetSum(vector<int> &num){
	vector<int> ans;
	int n = num.size();
	function<void(int, int)> dfs = [&] (int idx, int sum) -> void {
		if(idx == n) {
			ans.push_back(sum);
			return;
		}
		dfs(idx + 1, sum);
		dfs(idx + 1, sum + num[idx]);
		
	};
	dfs(0, 0);
	sort(ans.begin(), ans.end());
	return ans;
}
