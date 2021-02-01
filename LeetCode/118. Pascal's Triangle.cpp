#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> v(numRows);
    for (int i = 0; i < numRows; ++i) {
      v[i].resize(i + 1, 1);
      for (int j = 1; j < i; ++j) v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
    }
    return v;
  }
};
