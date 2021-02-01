#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Method 1: Gauss' formula
  int missingNumber(vector<int>& nums) {
    int n = nums.size(), tot = (1 + n) * (n) / 2;
    for (int& i : nums) tot -= i;
    return tot;
  }
  // Method 2: Bit manipulation
  int missingNumber(vector<int>& nums) {
    int miss = nums.size();
    for (int i = 0; i < nums.size(); ++i) miss ^= nums[i] ^ i;
    return miss;
  }
};
