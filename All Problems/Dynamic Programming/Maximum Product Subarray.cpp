// First Solution

#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	vector<vector<int>> memo(n);
	for(int i = 0; i < n; i++) memo[i] = {arr[i], arr[i]};
	
	int ans = arr[0];
	for(int i = 1; i < n; i++) {
		memo[i][0] = max(memo[i-1][0] * arr[i], max(memo[i-1][1] * arr[i], arr[i]));
		memo[i][1] = min(memo[i-1][1] * arr[i], min(memo[i-1][0] * arr[i], arr[i]));
		ans = max(ans, max(memo[i][0], memo[i][1]));
		// cout << memo[i][0] << " " << memo[i][1] << endl;
	}

	return ans;
}

// Second Optimize Solution

#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int ma = arr[0], mi = arr[0];
	
	int ans = arr[0];
	for(int i = 1; i < n; i++) {
		int cma = max(ma * arr[i], max(mi * arr[i], arr[i]));
		int cmi = min(mi * arr[i], min(ma * arr[i], arr[i]));
		swap(mi, cmi); swap(ma, cma);
		ans = max(ans, max(mi, ma));
	}

	return ans;
}

