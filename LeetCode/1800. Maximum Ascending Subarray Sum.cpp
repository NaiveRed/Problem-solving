#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxAscendingSum(vector<int>& nums) {
    int sum = 0, max_sum = 0, prev = 0;
    for (int& n : nums) {
      if (n > prev)
        sum += n;
      else
        sum = n;
      prev = n;
      if (sum > max_sum) max_sum = sum;
    }
    return max_sum;
  }
};
