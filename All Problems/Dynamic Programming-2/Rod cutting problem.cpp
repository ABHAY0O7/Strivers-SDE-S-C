#include "bits/stdc++.h"
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp (n + 2, vector<int> (n + 2, -1));
	function<int(int, int)> dfs = [&] (int idx, int prev) -> int {
		if(idx == n + 1) return 0;

		if(dp[idx][prev] != -1) return dp[idx][prev];

		int ans = dfs(idx + 1, prev);
		ans = max(ans, price[idx - prev - 1] + dfs(idx + 1, idx));
		return dp[idx][prev] = ans;
	};
	return dfs(1, 0);
}

// Second optimize solution

#include "bits/stdc++.h"
int cutRod(vector<int> &price, int n)
{
	vector<int> dp (n + 2, -1);
	function<int(int)> dfs = [&] (int idx) -> int {
		if(idx == n + 1) return 0;

		if(dp[idx] != -1) return dp[idx];
		int ans = INT_MIN;
		for(int i = idx; i <= n; i++) {
			ans = max(ans, price[i-idx] + dfs(i + 1));
		}
		return dp[idx] = ans;
	};
	return dfs(1);
}

