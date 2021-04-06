#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool checkOnesSegment(string s) {
    int len = s.size();
    for (int i = 1; i < len - 1; ++i)
      if (s[i] == '0' && s[i + 1] == '1') return false;
    return true;
  };
};
