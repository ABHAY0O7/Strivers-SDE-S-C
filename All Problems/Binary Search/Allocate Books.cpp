#include <bits/stdc++.h> 
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	#define ll long long

	ll l = 1, r = accumulate(time.begin(), time.end(), 0ll);
	function<bool(ll)> solve = [&] (ll mid) -> bool {
		ll cnt = 0;
		ll ans = 1;
		for(int i = 0; i < m; i++) {
			if(time[i] > mid) return 0;
			cnt += time[i];
			if(cnt > mid) ans++, cnt = time[i];
		}
		
		return ans <= n;
	};
	while(l <= r) {
		ll mid = (l + r) / 2;
		if(solve(mid)) r = mid - 1;
		else l = mid + 1;
	}
	return r + 1;
}
