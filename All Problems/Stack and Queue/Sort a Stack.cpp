#include <bits/stdc++.h> 
void sortStack(stack<int> &st)
{
	if(st.empty()) return;

	int curr = st.top();
	st.pop();
	sortStack(st);
	stack<int> q;
	while(!st.empty() && st.top() > curr) {
		q.push(st.top());
		st.pop();
	}
	st.push(curr);
	while(!q.empty()) {
		st.push(q.top());
		q.pop();
	}
}
