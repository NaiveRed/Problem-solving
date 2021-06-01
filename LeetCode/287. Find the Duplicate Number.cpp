#include <bits/stdc++.h>
using namespace std;

// Ref: LC. 442
class Solution {
 public:
  // Duplicate may appear more than once. e.g., [2,2,2,2]
  int findDuplicate(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
      int idx = abs(nums[i]) - 1;
      if (nums[idx] < 0) return idx + 1;
      nums[idx] *= -1;
    }
    return -1;
  }
};

class Solution1 {
 public:
  // Duplicate may appear more than once. e.g., [2,2,2,2]
  int findDuplicate(vector<int>& nums) {
    int size = nums.size();
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
      int bit_mask = (1 << i);
      // count1: for 1~n (size-1)
      // count2: for nums
      int bcount1 = 0, bcount2 = 0;
      for (int k = 0; k < size; ++k) {
        if (bit_mask & k) ++bcount1;
        if (bit_mask & nums[k]) ++bcount2;
      }
      // Only consider the bit we get more than bcount1. E.g. [2,2,2,2,2]
      // if bcount1>bcount2, we still do not know the bit
      // (only know miss some number)
      if (bcount2 > bcount1)
        ans |= bit_mask;      // It's 1 for the duplicate number at this bit.
    }
    return ans;
  }
};
