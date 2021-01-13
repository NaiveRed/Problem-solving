#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Method 1: bit manipulation
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
      ++count;
      n &= (n - 1);
    }
    return count;
  }

  // Method 2: check each bit
  int hammingWeight1(uint32_t n) {
    int count = 0;
    while (n) {
      if (n & 1) ++count;
      n >>= 1;
    }
    return count;
  }
};
