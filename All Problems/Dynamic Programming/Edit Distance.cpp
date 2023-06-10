#include "bits/stdc++.h"

int editDistance(string str1, string str2)
{
    int n = str1.size(), m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    
    for(int i = 1; i <= n; i++) dp[i][0] = i;
    for(int j = 1; j <= m; j++) dp[0][j] = j;


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int &ans = dp[i][j];
            if(str1[i-1] == str2[j-1]) ans = dp[i-1][j-1];
            else {
                ans = 1 + dp[i-1][j];
                ans = min(ans, 1 + dp[i-1][j-1]);
                ans = min(ans, 1 + dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
