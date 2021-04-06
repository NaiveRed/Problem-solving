#include <bits/stdc++.h>
using namespace std;

// containing at least one number!
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int sum = 0, max_sum = numeric_limits<int32_t>::min();  // INT_MIN
    for (int& n : nums) {
      if (sum > 0)
        sum += n;
      else
        sum = n;  // sum = 0; if dont need at least one number.
      if (sum > max_sum) max_sum = sum;
    }
    return max_sum;
  }
};

// Better to understand
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int sum = 0, max_sum = numeric_limits<int32_t>::min();  // INT_MIN
    for (int& n : nums) {
      sum = max(n, sum + n);
      if (sum > max_sum) max_sum = sum;
    }
    return max_sum;
  }
};
