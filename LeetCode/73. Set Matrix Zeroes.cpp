#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int r = matrix.size(), c = matrix[0].size();
    // Since the matrix[0][0] can not represent the row/col 0 at the same time,
    // we use another flags to record.
    bool flag_c0 = false, flag_r0 = false;
    for (int i = 0; i < r; ++i)
      if (!matrix[i][0]) flag_c0 = true;
    for (int i = 0; i < c; ++i)
      if (!matrix[0][i]) flag_r0 = true;
    // Record the matrix [1][1] ~ [r-1][c-1]
    for (int i = 1; i < r; ++i)
      for (int j = 1; j < c; ++j)
        if (!matrix[i][j]) matrix[0][j] = matrix[i][0] = 0;

    // Deal with row 1 to row r-1
    for (int i = 1; i < r; ++i)
      if (!matrix[i][0])
        for (int j = 1; j < c; ++j) matrix[i][j] = 0;
    // Deal with col 1 to col c-1
    for (int i = 1; i < c; ++i)
      if (!matrix[0][i])
        for (int j = 1; j < r; ++j) matrix[j][i] = 0;
    // Deal with row 0 and col 0
    if (flag_c0)
      for (int i = 0; i < r; ++i) matrix[i][0] = 0;
    if (flag_r0)
      for (int i = 0; i < c; ++i) matrix[0][i] = 0;
  }
};
