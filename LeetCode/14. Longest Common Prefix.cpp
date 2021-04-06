#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Method 1: Vertical scanning
  string longestCommonPrefix(vector<string>& strs) {
    int ss = strs.size();
    if (!ss) return "";
    int s0_size = strs[0].size();
    for (int i = 0, j; i < s0_size; ++i) {
      for (j = 0; j < ss && i < strs[j].size(); ++j) {
        if (strs[0][i] != strs[j][i]) break;
      }
      if (j != ss) return i ? strs[0].substr(0, i) : "";
    }
    return strs[0];
  }
};

class Solution2 {
 public:
  // Method 2: horizontal scanning
  string longestCommonPrefix(vector<string>& strs) {
    int ss = strs.size();
    if (!ss) return "";
    string cp(strs[0]);
    for (int i = 1; i < ss; ++i) {
      int is = strs[i].size();
      for (int j = 0; j < cp.size(); ++j)
        if (j >= is || strs[i][j] != cp[j]) {
          cp.erase(j);
          break;
        }
    }
    return cp;
  }
};
