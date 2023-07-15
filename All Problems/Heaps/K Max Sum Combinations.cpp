#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int i = n - 1, j = n - 1;
	priority_queue<vector<int>> pq;
	pq.push({a[i] + b[j], i, j});
	vector<int> ans;
	set<pair<int, int>> vis;
	while(k--) {
		vector<int> temp = pq.top();
		pq.pop();
		ans.push_back(temp[0]);
		i = temp[1];
		j = temp[2];
		// for(auto it : temp) cout << it << " "; cout << endl;
		int pi = i - 1, pj = j - 1; 
		if(pi >= 0 && vis.find({pi, j}) == vis.end()) pq.push({a[pi] + b[j], pi, j}), vis.insert({pi, j});
		if(pj >= 0 && vis.find({i, pj}) == vis.end()) pq.push({a[i] + b[pj], i, pj}), vis.insert({i, pj});
	}
	return ans;
}
