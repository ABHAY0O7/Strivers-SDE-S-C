int removeDuplicates(vector<int> &arr, int n) {
	int i = 0, j = 0;
	while(j < n) {
		arr[i++] = arr[j];
		int curr = j;
		while(j < n && arr[j] == arr[curr]) j++;
	}
	return i;
}
