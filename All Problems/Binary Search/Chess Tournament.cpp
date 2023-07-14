#include <bits/stdc++.h> 
int chessTournament(vector<int> p , int n ,  int c){
	#define ll long long
	sort(p.begin(), p.end());
	ll l = 0, r = a*max_element(p.begin(), p.end());
	function<bool(int)> solve = [&] (int mid) -> bool {
		int curr = -1;
		for(int i = 0; i < c; i++) {
			int idx = lower_bound(p.begin(), p.end(), curr) - p.begin();
			if(idx == n) return 0;
			curr = mid + p[idx];
		}
		return 1;
	};
	while(l <= r) {
		ll mid = (l + r) / 2;
		if(solve(mid)) l = mid + 1;
		else r = mid - 1;
	}
	return l - 1;
}
