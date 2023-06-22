int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int n = arr.size();
	int l = 0, r = n - 1;
	
	while(l < r) {
		int mid = (l + r) / 2;

		if(arr[mid] != arr[mid+1]) {
			if(mid % 2) l = mid + 1;
			else r = mid;
		} else {
			if(mid % 2) r = mid - 1;
			else l = mid + 1;
		}
	}
	return arr[l];
}
