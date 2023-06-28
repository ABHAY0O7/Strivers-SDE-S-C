double median(vector<int>& a, vector<int>& b) {
	int i = 0, j = 0;

	int n = a.size(), m = b.size();
	a.push_back(1e9+1);
	b.push_back(1e9+1);
	int idx1 = (n + m) / 2;
	int idx2 = (n + m) % 2 ? idx1 : idx1 - 1;
	// cout << idx1 <<" " << idx2 << endl;
	int cnt = 0;
	vector<int> p;
	while(i < n || j < m) {
		if(cnt == idx1) p.push_back(min(a[i], b[j]));
		if(cnt == idx2) p.push_back(min(a[i], b[j]));

		if(p.size() == 2) break;

		if(i == n) j++;
		else if(j == m) i++;
		else if(a[i] <= b[j]) i++;
		else j++;
		cnt++;
	}

	double ans = (double) (p[0] + p[1]) / 2;
	return ans;
}

// Accepted Solution

double median(vector<int>& aa, vector<int>& bb) {
	
	function<double(vector<int> &, vector<int> &)> solve = [] (vector<int> &a, vector<int> &b) -> double {

		int n = a.size(), m = b.size();
		int med = (n + m + 1) / 2;
		a.push_back(1e9);
		b.push_back(1e9);
		int l = 0, r = n - 1;

		while(l <= r) {
			int mid = ((l + r) / 2) + 1;
			int rem = med - mid;

			int l1 = a[mid-1], l2 = rem == 0 ? INT_MIN : b[rem-1];
			int r1 = a[mid], r2 = b[rem];
			// cout << l << " " << r << " " << mid << " " << rem << endl;
			// cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
			if(l1 <= r2 && l2 <= r1) {
				if((n + m) % 2) return (double) (max(l1, l2));
				else return (double) (max(l1, l2) + min(r1, r2)) / 2;
			}

			if(l1 > r2) r = mid - 2;
			else l = mid;
		}
		return 0.0;
	};

	if(aa.size() <= bb.size()) return solve(aa, bb);
	return solve(bb, aa);
}
