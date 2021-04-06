#include <bits/stdc++.h>
using namespace std;

// Swap
class Solution {
 public:
  void reverseString(vector<char>& s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      //   char c = s[i];
      //   s[i] = s[j];
      //   s[j] = c;
      s[i] ^= s[j];
      s[j] ^= s[i];
      s[i] ^= s[j];
    }
  }
};

// Recursive
class Solution1 {
 public:
  void helper(vector<char>& s, int l, int r) {
    if (l >= r) return;
    swap(s[l], s[r]);
    helper(s, l + 1, r - 1);
  }
  void reverseString(vector<char>& s) { helper(s, 0, s.size() - 1); }
};
