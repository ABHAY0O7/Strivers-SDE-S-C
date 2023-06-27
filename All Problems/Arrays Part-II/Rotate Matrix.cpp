#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int rs = 0, re = n - 1, cs = 0, ce = m - 1;

    while(rs < re && cs < ce) {
        pair<int, int> prev = {rs, cs};
        pair<int, int> curr = {rs + 1, cs};
        while (curr.first <= re) {
          swap(mat[curr.first][curr.second], mat[prev.first][prev.second]);
          prev = curr;
          curr.first++;
        }

        curr = {re, cs + 1};
        while (curr.second <= ce) {
          swap(mat[curr.first][curr.second], mat[prev.first][prev.second]);
          prev = curr;
          curr.second++;
        }

        curr = {re - 1, ce};
        while (curr.first >= rs) {
          swap(mat[curr.first][curr.second], mat[prev.first][prev.second]);
          prev = curr;
          curr.first--;
        }

        curr = {rs, ce - 1};
        while (curr.second > cs) {
          swap(mat[curr.first][curr.second], mat[prev.first][prev.second]);
          prev = curr;
          curr.second--;
        }
        rs++; cs++;
        re--; ce--;
    }

}
