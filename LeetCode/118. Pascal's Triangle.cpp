#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> v;
    v.push_back({1});
    if (numRows > 1) v.push_back({1, 1});
    for (int i = 2; i < numRows; ++i) {
      v.push_back(vector(i + 1, 1));
      for (int j = 1; j < i; ++j) v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
    }
    return v;
  }
};
