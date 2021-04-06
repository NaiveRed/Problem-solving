#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    // Bound
    int r1 = 0, r2 = n - 1, c1 = 0, c2 = n - 1;
    // ->, v, <-, ^
    int dir_r[4] = {0, 1, 0, -1}, dir_c[4] = {1, 0, -1, 0};
    vector<vector<int>> result(n, vector<int>(n));
    int r = 0, c = 0, dir = 0;
    for (int i = 1; i <= n * n; ++i) {
      result[r][c] = i;
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
