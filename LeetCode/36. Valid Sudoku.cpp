#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    bool row[10][10] = {}, col[10][10] = {}, square[3][3][10] = {};
    for (int r = 0; r < 9; ++r)
      for (int c = 0; c < 9; ++c) {
        if (board[r][c] == '.') continue;
        int digit = board[r][c] - '0';

        if (row[r][digit] || col[c][digit] || square[r / 3][c / 3][digit])
          return false;
        row[r][digit] = col[c][digit] = square[r / 3][c / 3][digit] = true;
      }
    return true;
  }
};
