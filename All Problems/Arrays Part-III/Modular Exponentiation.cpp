#include <bits/stdc++.h>

int modularExponentiation(int xx, int nn, int mm) {
	#define ll long long
	
	ll n = nn, m = mm, x = xx; 
	function<ll(ll, ll)> dfs = [&] (ll x, ll n) -> ll {
		if(n == 0) return 1;
		ll res = dfs(x, n / 2) % m;
		res = (res * res) % m;
		if(n % 2) res = (res * x) % m;
		return res % m;
	} ;
	return dfs(x, n);
}

// Second optimal solution

#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	#define ll long long
	
	int ans = 1;
	while(n) {
		if(n & 1) ans = 1ll * ans * x % m;
		x = 1ll * x * x % m;
		n >>= 1;
	}
	return ans;
}
