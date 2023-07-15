int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i = 0, j = 0, ans = 0;
    while(j < n) {
        if(arr[j] == 0) k--;
        if(k < 0) {
            while(i < n && arr[i] != 0) i++;
            k = 0;
            i++;
        }
        j++;
        ans = max(ans, j - i);
    }
    return ans;
}

