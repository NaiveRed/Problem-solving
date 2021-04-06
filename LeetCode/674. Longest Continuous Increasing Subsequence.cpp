#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int size = nums.size();
    if (!size) return 0;
    int lcis = 1, len = 1;
    for (int i = 1; i < size; ++i) {
      if (nums[i] > nums[i - 1])
        ++len;
      else
        len = 1;
      lcis = max(lcis, len);
    }
    return lcis;
  }
};
