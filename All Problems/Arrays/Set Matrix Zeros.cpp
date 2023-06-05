#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &mat)
{
	int n = mat.size(), m = mat[0].size();
	bool r0 = 0, c0 = 0;

	for(int i = 0; i < n; i++) if(mat[i][0] == 0) r0 = 1;
	for(int j = 0; j < m; j++) if(mat[0][j] == 0) c0 = 1;

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if (mat[i][j] == 0) {
				mat[i][0] = 0;
				break;
			}
		}
	}

	for(int j = 1; j < m; j++) {
		for(int i = 1; i < n; i++) {
			if(mat[i][j] == 0) {
				mat[0][j] = 0;
				break;
			} 
		}
	}

	for(int i = 1; i < n; i++) {
		if(mat[i][0] == 0) {
			for(int j = 1; j < m; j++) mat[i][j] = 0;
		}
		for(int j = 1; j < m; j++) {
			if(mat[0][j] == 0) mat[i][j] = 0;
		}
	}


	if(r0) for(int i = 0; i < n; i++) mat[i][0] = 0;
	if(c0) for(int j = 0; j < m; j++) mat[0][j] = 0;
}
