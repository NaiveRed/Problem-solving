#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    int size = nums.size();
    vector<int> res;
    for (int i = 0; i < size; ++i) {
      // -1: for 0-based
      int idx = abs(nums[i]) - 1;
      if (nums[idx] < 0)
        res.push_back(idx + 1);
      else
        nums[idx] *= -1;
    }
    return res;
  }
};
