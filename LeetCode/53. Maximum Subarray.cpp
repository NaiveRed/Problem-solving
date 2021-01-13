#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // containing at least one number!
  // The case will be all the negative number: choose min
  int maxSubArray(vector<int>& nums) {
    int64_t ans = numeric_limits<int64_t>::min(), sum = 0;
    for (int n : nums) {
      sum += n;
      if (sum > ans)
        ans = sum;
      if (sum < 0)
        sum = 0;
    }
    return ans;
  }
};
