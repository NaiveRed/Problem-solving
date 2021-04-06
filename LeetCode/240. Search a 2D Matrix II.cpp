#include <bits/stdc++.h>
using namespace std;

// Same as Leetcode 74
// Start comparison from the top-right
// Time: O(m+n)
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int r = 0, c = col - 1, x = matrix[r][c];
    while (r < row && c >= 0) {
      if (target > matrix[r][c])
        ++r;
      else if (target < matrix[r][c])
        --c;
      else
        return true;
    }
    return false;
  }
};
