#include <bits/stdc++.h> 
struct Node {
    Node* arr[2];
    bool find(int idx) { return arr[idx] == NULL; }
    void set(int idx, Node* node) { arr[idx] = node; }
    Node* get(int idx) { return arr[idx]; }
};

class Trie {

	Node* root;
	public:
	Trie() {
		root = new Node();
	}

	void insert(int x) {
		Node* node = root;
		for(int i = 31; i >= 0; i--) {
			int idx = (x >> i) & 1;
			if(node -> find(idx)) node -> set(idx, new Node());
			node = node -> get(idx);
		}
	}

	int findMax(int x) {
		Node* node = root;
		int ans = 0;
		if(node -> find(0) && node -> find(1)) return -1;
		for(int i = 31; i >= 0; i--) {
			int idx = ((x >> i) & 1) ^ 1;
			if(!node -> find(idx)) {
				ans |= (1 << i);
				node = node -> get(idx);
			} else {
				node = node -> get(!idx);
			}
		}
		return ans;
	}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	vector<vector<int>> v;
	Trie trie;

	int q = queries.size();
	int n = arr.size();
	vector<int> ans(q);
	for(int i = 0; i < q; i++) {
		v.push_back({queries[i][1], queries[i][0], i});
	}
	sort(arr.begin(), arr.end());
	sort(v.begin(), v.end());
	int i = 0;
	int j = 0;
	while(j < q) {
		int val = v[j][0];
		int idx = v[j][2];
		while(i < n && arr[i] <= val) trie.insert(arr[i++]);
		

		ans[idx] = trie.findMax(v[j][1]);
		j++;
	}
	return ans;
}
