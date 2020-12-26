#include <bits/stdc++.h>
using namespace std;

bool isBadVersion(int version);

class Solution {
 public:
  // Binary search
  int firstBadVersion(int n) {
    int l = 1, r = n;
    while (l < r) {
      int mid = l + (r - l) / 2;  // Avoid overflow
      if (isBadVersion(mid))      // The first bad version is before mid or mid
        r = mid;
      else
        l = mid + 1;
    }
    return r;
  }
};
