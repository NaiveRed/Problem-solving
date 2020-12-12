#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> S;
    for (int& n : nums)
      if (S.count(n))
        return true;
      else
        S.insert(n);
    return false;
  }
};
