#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int min_p = INT_MAX, ret = 0;
    for (int i : prices) {
      if (i < min_p) min_p = i;
      if (i - min_p > ret) ret = i - min_p;
    }
    return ret;
  }
};
