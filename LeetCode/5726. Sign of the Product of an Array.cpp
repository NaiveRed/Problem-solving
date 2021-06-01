#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int sign = 1;
    for (int& n : nums) {
      if (n > 0)
        sign *= 1;
      else if (n < 0)
        sign *= -1;
      else
        return 0;
    }
    return sign;
  }
};
