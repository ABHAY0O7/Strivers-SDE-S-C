#include "bits/stdc++.h"
int search(int* arr, int n, int key) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) / 2;

        if(arr[mid] == key) return mid;

        if(arr[l] <= arr[mid]) {
            if(key < arr[mid] && key >= arr[l]) r = mid - 1;
            else l = mid + 1;
        } else {
            if(arr[mid] < key && key <= arr[r]) l = mid + 1;
            else r = mid - 1;
        }
    }
    return -1;
}
