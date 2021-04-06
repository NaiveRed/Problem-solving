#include <bits/stdc++.h>
using namespace std;

// Method 1: DP with O(rowIndex) space
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    // rowIndex is 0-indexed
    vector<int> result(rowIndex + 1);
    result[0] = 1;
    for (int r = 1; r <= rowIndex; ++r) {
      // From right to left
      for (int c = r; c; --c) result[c] += result[c - 1];
    }
    return result;
  }
};

// Method 2: recursive
class Solution1 {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> result(rowIndex + 1);
    result[0] = 1;
    if (rowIndex >= 1) {
      vector<int> prev = getRow(rowIndex - 1);
      for (int c = 1; c < rowIndex; ++c) result[c] = prev[c - 1] + prev[c];
      result[rowIndex] = 1;
    }

    return result;
  }
};

// Method 2: tail recursive
class Solution3 {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> result;
    result.push_back(1);
    getRowTR(0, rowIndex, result);
    return result;
  }
  void getRowTR(int idx, int rowIndex, vector<int>& result) {
    if (idx == rowIndex) return;
    for (int i = idx; i; --i) result[i] += result[i - 1];
    result.push_back(1);
    getRowTR(idx + 1, rowIndex, result);
  }
};

// Method 3: basic recursive
// TLE
class Solution4 {
 public:
  int pascal(int row, int col) {
    if (!col || row == col) return 1;
    return pascal(row - 1, col - 1) + pascal(row - 1, col);
  }
  vector<int> getRow(int rowIndex) {
    vector<int> result;
    for (int i = 0; i <= rowIndex; ++i) result.push_back(pascal(rowIndex, i));
    return result;
  }
};
