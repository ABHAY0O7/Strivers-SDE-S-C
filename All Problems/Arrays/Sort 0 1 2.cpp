#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int i = 0, j = n - 1;
   int idx = 1;
   while(idx <= j) {
      if(arr[idx] == 0) {
         swap(arr[idx], arr[i]);
         i++;
      } else if(arr[idx] == 2) {
         swap(arr[idx], arr[j]);
         j--;
      } else idx++;
      if(i == idx) idx++;
   }
   if(arr[0] == 2) swap(arr[0], arr[j]);
}
