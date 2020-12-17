#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int myAtoi(string s) {
    int size = s.size(), idx = 0;
    // Find first non-whitespace
    while (idx < size && s[idx] == ' ') ++idx;
    if (idx == size) return 0;

    // To int
    int32_t n = 0, neg = 1;
    // Check sign or invalid
    if (!isdigit(s[idx])) {
      if (s[idx] == '-')
        neg = -1;
      else if (s[idx] != '+')
        return 0;
      ++idx;
    }

    while (idx < size && isdigit(s[idx])) {
      int32_t d = s[idx++] - '0';
      if (n > INT_MAX / 10 ||
          (n == INT_MAX / 10 && d > 7))  // 7 for 214748364'7'
        return neg == 1 ? INT_MAX : INT_MIN;
      n = n * 10 + d;
    }
    // Another way to check overflow/underflow
    // while (idx < size && isdigit(s[idx])) {
    //   int32_t d = s[idx++] - '0';
    //   if (neg == 1) {
    //     if (n > (INT_MAX - d) / 10) return INT_MAX;
    //     n = n * 10 + d;
    //   } else {
    //     if (n < (INT_MIN + d) / 10) return INT_MIN;
    //     n = n * 10 - d;
    //   }
    // }
    return n * neg;
  }
};
