// First Solution

#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	rack.insert(rack.begin(), 0);
	n = rack.size();
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

	function<int(int idx, int prev)> abhay = [&] (int idx, int prev) -> int {
		if(idx == n) return 0;
		// cout << idx << " " << prev << endl;
		if(dp[idx][prev] != -1) return dp[idx][prev];

		int ans = abhay(idx + 1, prev);

		if(rack[idx] > rack[prev]) ans = max(ans, rack[idx] + abhay(idx + 1, idx));

		return dp[idx][prev] = ans;
	};


	return abhay(1, 0);
}

// Second Optimize Solution

#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	rack.insert(rack.begin(), 0);
	n = rack.size();
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

	function<int(int idx, int prev)> abhay = [&] (int idx, int prev) -> int {
		if(idx == n) return 0;
		// cout << idx << " " << prev << endl;
		if(dp[idx][prev] != -1) return dp[idx][prev];

		int ans = abhay(idx + 1, prev);

		if(rack[idx] > rack[prev]) ans = max(ans, rack[idx] + abhay(idx + 1, idx));

		return dp[idx][prev] = ans;
	};


	for(int i = n - 1; i > 0; i--) {
		for(int j = i; j >= 0; j--) {
			int ans = dp[i+1][j];
			if(rack[i] > rack[j]) ans = max(ans, rack[i] + dp[i+1][i]);
			dp[i][j] = ans;
		}
	}
	return dp[1][0];
}
