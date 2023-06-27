#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	swap(n, m);
	int i = n - 1, j = 0;
	// cout << n << " " << m << endl;
	while(i >= 0 && j < m && arr1[i] > arr2[j]) swap(arr1[i--], arr2[j++]);
	sort(arr1.begin(), arr1.begin() + n);
	sort(arr2.begin(), arr2.begin() + m);
	i = n, j = 0;
	while(j < m) arr1[i++] = arr2[j++];
	return arr1;
}

// Second Optimal approach

#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	swap(n, m);
	int i = n - 1, j = m - 1, idx = n + m - 1;

	while(idx >= 0) {
		if(i >= 0 && arr1[i] > arr2[j]) arr1[idx] = arr1[i--];
		else arr1[idx] = arr2[j--];
		idx--;
	}
	return arr1;
}
