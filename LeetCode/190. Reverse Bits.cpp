#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Method 1: bit by bit
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0, p = 31;
    while (n) {
      ans |= (n & 1) << p;
      --p;
      n >>= 1;
    }
    return ans;
  }

  // Method 1.1: also bit by bit
  uint32_t reverseBits1(uint32_t n) {
    uint32_t ans = 0;
    for (int i = 0; i < 32; ++i) {
      ans <<= 1;
      ans |= n & 1;
      n >>= 1;
    }
    return ans;
  }

  // Method 2: D&C
  uint32_t reverseBits2(uint32_t n) {
    // Reverse Bytes
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    // Reverse bits
    // 1100 => c, 0011 => 3
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    // 1010 => a, 0101 => 5
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
  }
};
