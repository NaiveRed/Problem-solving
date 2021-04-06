#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int a = INT_MAX, b = INT_MAX;  // a<b<c
    for (int& n : nums) {
      // Case 1: `n` is less than `a`, we change `a` to it.
      // It will be a better choice for later numbers. (Greedy)
      // The equal case does not matter, since it will still return true
      // if there exists valid triplet.
      if (n <= a) a = n;
      // Case 2: `n` is greater than `a`, and the position is behind the `a`.
      // Thus, it will not be a better choice for `a`.
      // But if it is less than `b`, it will be a better choice.
      // We don't need to consider the pos(or seq) of `a` and `b`,
      // because if there is a valid number of `b`, it implies there was a
      // valid `a` before `b`.
      else if (n <= b)
        b = n;
      // Case 3: if `n` is greater than `b`, we find the triplet.
      else
        return true;  // Find c
    }
    return false;
  }
};
