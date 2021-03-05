#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int len = 0;
    char s[12];
    while (x) {
      s[len++] = '0' + x % 10;
      x /= 10;
    }
    for (int i = 0, j = len - 1; i < j; ++i, --j)
      if (s[i] != s[j]) return false;
    return true;
  }
};
