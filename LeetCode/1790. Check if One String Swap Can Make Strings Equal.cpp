#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool areAlmostEqual(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    int size = s1.size(), swap_idx = -1;
    for (int i = 0; i < size; ++i) {
      if (s1[i] != s2[i]) {
        if (swap_idx != -1) {
          swap(s1[i], s1[swap_idx]);
          break;
        } else
          swap_idx = i;
      }
    }
    return s1 == s2;
  }
};
