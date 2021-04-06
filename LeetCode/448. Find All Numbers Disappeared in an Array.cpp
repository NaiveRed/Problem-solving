#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
      int idx = abs(nums[i]) - 1;
      // -1: for 0-based
      if (nums[idx] > 0) nums[idx] *= -1;
    }
    vector<int> res;
    for (int i = 0; i < size; ++i)
      if (nums[i] > 0) res.push_back(i + 1);
    return res;
  }
};
