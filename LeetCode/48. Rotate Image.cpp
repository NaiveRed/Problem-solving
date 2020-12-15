#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Method 1:  transpose and reverse
  void rotate1(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // transpose
    for (int r = 0; r < n - 1; ++r)  // No need for last row
      for (int c = r + 1; c < n; ++c) swap(matrix[r][c], matrix[c][r]);
    // reflect_vertical
    for (int r = 0; r < n; ++r)
      for (int c = 0; c < n / 2; ++c) swap(matrix[r][c], matrix[r][n - c - 1]);
  }

  // Method 2: rotate four rectangles
  void rotate2(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i)  // outer
      for (int j = 0; j < n - 2 * i - 1; ++j) {
        int tmp = matrix[i][i + j];
        // upper left
        matrix[i][i + j] = matrix[n - j - i - 1][i];
        // lower left
        matrix[n - j - i - 1][i] = matrix[n - i - 1][n - j - i - 1];
        // lower right
        matrix[n - i - 1][n - j - i - 1] = matrix[i + j][n - i - 1];
        // upper right
        matrix[i + j][n - i - 1] = tmp;
      }
  }
};
