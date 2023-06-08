#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    vector<int> curr = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

    int ans = 0;
    for(int i = 0; i < curr.size() && amount; i++) {
        ans += (amount / curr[i]);
        amount %= curr[i];
    }
    return ans;
}

