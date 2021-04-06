#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    // nums can be considered as two sides:
    // Normal side: [x,x,x,0,1,2,3]
    // Rotate part: [4,5,6,x,x,x,x]
    while (l <= r) {
      int m = l + (r - l) / 2;

      // Use nums[0] to determine whether target and mid are at the same side.
      if ((nums[0] > nums[m]) == (nums[0] > target)) {
        // They are at the same side, do binary search normally.
        // E.g.,
        //        m   t          t m
        // [4,5,6,0,1,2,3] or [4,5,6,0,1,2,3]
        if (nums[m] > target)
          r = m - 1;
        else if (nums[m] < target)
          l = m + 1;
        else
          return m;
      } else {
        // At the different side, intend to move mid close to target
        // E.g.,
        //      m   t            t   m
        // [4,5,6,0,1,2,3] or [4,5,6,0,1,2,3]
        if (nums[m] > target)
          l = m + 1;
        else  // if (nums[m] < target)
          r = m - 1;
      }
    }
    return -1;
  }
};
