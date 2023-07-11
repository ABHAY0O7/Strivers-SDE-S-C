#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   sort(arr.begin(), arr.end());
   vector<vector<int>> ans;
   int n = arr.size();
   for(int i = 0; i < n; i++) {
      int val = s - arr[i];
      int l = i + 1, r = n - 1;

      while(l <= r) {
         int mid = (l + r) / 2;

         if(arr[mid] < val) l = mid + 1;
         else r = mid - 1;
      }
      
      int curr = arr[l];
      if(curr != val) continue;
      while(l < n && arr[l] == curr) ans.push_back({arr[i], arr[l++]});
   }
   return ans;
}
