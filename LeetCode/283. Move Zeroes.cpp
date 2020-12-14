#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Method 1: O(n) but less operation
  void moveZeroes(vector<int>& nums) {
    int count = 0;  // number of non-zero
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i]) nums[count++] = nums[i];
    for (count; count < nums.size(); ++count) nums[count] = 0;
  }
  // Method 2: O(n)
  //   void moveZeroes(vector<int>& nums) {
  //     // i for zero, j for non-zero
  //     for (int i = 0, j = 0, s = nums.size(); i < s && j < s;) {
  //       while (nums[i])
  //         if (++i >= s) return;
  //       while (!nums[j] || j < i)
  //         if (++j >= s) return;
  //       swap(nums[i++], nums[j++]);
  //     }
  //   }
};
