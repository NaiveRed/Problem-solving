#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int max_p_of_three;
  Solution() {
    for (max_p_of_three = 1; max_p_of_three <= numeric_limits<int>::max() / 3;
         max_p_of_three *= 3)
      ;
  }
  // Method 1: O(log_3(n))
  bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    while (n % 3 == 0) n /= 3;
    return n == 1;
  }

  // Method 2:
  bool isPowerOfThree1(int n) { return n > 0 && max_p_of_three % n == 0; }
};
