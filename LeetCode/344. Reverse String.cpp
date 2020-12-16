#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      char c = s[i];
      s[i] = s[j];
      s[j] = c;
    }
  }
};
