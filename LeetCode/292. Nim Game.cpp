#include <bits/stdc++.h>
using namespace std;

// Goal: leave 4 stones for the opponent.
// We want the opponent to get one of `x`,
// so we should get the place before x (i.e., 3).
// In order to do that, the remain stones before x can only exist <= k
// ... 1 2 3 x x x o
// Deduce to the whole pile, it will be the case that not divisible by 4.
class Solution {
 public:
  bool canWinNim(int n) { return n % 4 != 0; }
};
