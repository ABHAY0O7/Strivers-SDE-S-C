#include "bits/stdc++.h"
string reverseString(string &str){
	int n = str.size();
	stack<string> st;
	int j = 0;
	for(int i = 0; i <= n; i++) {
		if(i == n || str[i] == ' ') {
			if(j != i) {
				st.push(str.substr(j, i - j + 1));
			}
			j = i + 1;
		} else {
			if(str[j] == ' ') j = i;
		}
	}
	string s;
	while(!st.empty()) {
		s += st.top();
		st.pop();
		if(!st.empty()) s.push_back(' ');
	}
	return s;
}
