#include "bits/stdc++.h"
int get(int i, int j) {
    return 3 * (i / 3) + (j / 3);
}
bool isItSudoku(int matrix[9][9]) {
    int row[10][10] = {0}, col[10][10] = {0}, box[10][10] = {0};

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(matrix[i][j] == 0) continue;
            if(row[i][matrix[i][j]] || col[j][matrix[i][j]] || box[get(i, j)][matrix[i][j]]) return 0;
            row[i][matrix[i][j]] = col[j][matrix[i][j]] = box[get(i, j)][matrix[i][j]] = 1;          
        }
    }

    function<bool(int, int)> dfs = [&] (int i, int j) -> bool {
        if(i == 9) return 1;
        if(j == 9) return dfs(i + 1, 0);

        if(matrix[i][j] == 0) {
            for(int k = 1; k < 10; k++) {
                if(row[i][k] || col[j][k] || box[get(i, j)][k]) continue;
                row[i][k] = col[j][k] = box[get(i, j)][k] = 1;
                if(dfs(i, j + 1)) return 1;
                row[i][k] = col[j][k] = box[get(i, j)][k] = 0;
            }
        } else {
            if(dfs(i, j + 1)) return 1;
        }
        return 0;
    };

    return dfs(0, 0);
}

