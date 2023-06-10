#include "bits/stdc++.h"
int maxProfit(vector<int> &v, vector<int> &w, int n, int tot)
{
	vector<vector<int>> dp(n + 1, vector<int> (tot + 1, 0));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= tot; j++) {
			if(w[i-1] <= j) dp[i][j] = v[i-1] + dp[i-1][j-w[i-1]];
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}
	return dp[n][tot];
}
