#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	#define ll long long
	ll tot = 1ll * n * (n + 1) / 2;
	ll sum = accumulate(arr.begin(), arr.end(), 0ll);
	int diff = abs(tot - sum);
	
	ll tot2 = 0, sum2 = 0;
	for(ll i = 0; i < n; i++) {
		tot2 += ((i + 1) * (i + 1));
		sum2 += 1ll * arr[i] * arr[i];
	}

	ll m = (((tot2 - sum2) / diff) + diff) / 2;
	ll r = m - diff;

	return {abs(m), abs(r)};
}
// tot - sum = m - r;
// tot2 - sum2 = m2 - r2;
// tot2 - sum2 / tot - sum = m + r
// m = tot2 - sum2 / diff + diff / 2
// r = m - diff

// Second Optimal approach

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	
	int val = 0;
	for(int i = 1; i <= n; i++) {
		val ^= arr[i-1];
		val ^= i;
	}
	// cout << val << endl;
	int idx = -1;
	for(int i = 0; i <= 32 && idx == -1; i++) if((val >> i) & 1) idx = i;
	// cout << idx << endl;
	int num1 = 0, num2 = 0;
	for(int i = 1; i <= n; i++)  {
		if((arr[i-1] >> idx) & 1) num1 ^= arr[i-1];
		else num2 ^= arr[i-1];
		if((i >> idx) & 1) num1 ^= i;
		else num2 ^= i;
	}
	// cout << num1 << " " << num2 << endl;
	int cnt = 0;
	for(auto it : arr) if(it == num1) cnt++;
	if(cnt == 2) swap(num1, num2);
	return { num1, num2 };
}
// tot - sum = m - r;
// tot2 - sum2 = m2 - r2;
// tot2 - sum2 / tot - sum = m + r
// m = tot2 - sum2 / diff + diff / 2
// r = m - diff

