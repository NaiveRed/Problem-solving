#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPowerOfFour(int num)
  {
    /*
        num & (num-1): check whether the number is a power of two.
        It will have only one 1.
        The binary of power of four: the 1 will be at the odd position.
        1, 100, 10000, ....
        Use bit mask: 0x55555555 (5: 0101)
    */
    return (num > 0) && (num & (num - 1)) == 0 && ((num & 0x55555555) == num);
  }
};