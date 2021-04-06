#include <bits/stdc++.h>
using namespace std;

// Method 1: Consider matrix as a 1d array and do binary search
// Time: O(log(mn)), 0 ms
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int l = 0, r = row * col - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      int x = matrix[m / col][m % col];
      if (target > x)
        l = m + 1;
      else if (target < x)
        r = m - 1;
      else
        return true;
    }
    return false;
  }
};

// Method 2: Start comparison from the top-right
// Time: O(m+n), 0 ms
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
