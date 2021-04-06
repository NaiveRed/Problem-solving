#include <bits/stdc++.h>
using namespace std;

// Method 1: Use `n & (n-1)` to remove lowest `1`.
// The +1 represents the removed one.
// Time: O(n)
class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> count(num + 1);
    for (int i = 1; i <= num; ++i) count[i] = count[i & (i - 1)] + 1;
    return count;
  }
};

// Method 2: Use power of 2 to get the remaining bits.
// E.g.
// 1: 1
// 2: 10
// 4: 100
// 5 (101): 5(101)-4(100) is the remaining bits.
// dp[5-4] + 1(the `1` for the power of two)
// Time: O(n)
class Solution1 {
 public:
  vector<int> countBits(int num) {
    vector<int> count(num + 1);
    int p2 = 1;
    for (int i = 1; i <= num; ++i) {
      if (i == (p2 << 1)) p2 <<= 1;
      count[i] = count[i - p2] + 1;
    }
    return count;
  }
};
