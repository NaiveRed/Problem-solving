#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
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
