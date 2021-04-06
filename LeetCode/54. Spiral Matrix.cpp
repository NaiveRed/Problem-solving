#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    // Bound
    int r1 = 0, r2 = matrix.size() - 1, c1 = 0, c2 = matrix[0].size() - 1;
    // ->, v, <-, ^
    int dir_r[4] = {0, 1, 0, -1}, dir_c[4] = {1, 0, -1, 0};
    vector<int> result;
    int r = 0, c = 0, dir = 0;
    while (r1 <= r2 && c1 <= c2) {
      result.push_back(matrix[r][c]);
      int new_r = r + dir_r[dir], new_c = c + dir_c[dir];
      if (new_c > c2 || new_r > r2 || new_c < c1 || new_r < r1) {
        if (new_c > c2)  // ->
          ++r1;
        else if (new_r > r2)  // v
          --c2;
        else if (new_c < c1)  //<-
          --r2;
        else if (new_r < r1)  //^
          ++c1;
        // Update direction
        dir = (dir + 1) % 4;
        new_r = r + dir_r[dir], new_c = c + dir_c[dir];
      }
      r = new_r;
      c = new_c;
    }
    return result;
  }
};
