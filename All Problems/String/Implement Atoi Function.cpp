#include <bits/stdc++.h> 
int atoi(string str) {
    int ans = 0;
    int minus = 1;
    for(int i = 0; i < str.size(); i++) {
        if(i == 0 && str[i] == '-') minus = -1;
        if(str[i] >= '0' && str[i] <= '9') ans = ans * 10 + (str[i] - '0');
    }
    return ans * minus;
}
