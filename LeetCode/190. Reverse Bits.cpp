#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  uint32_t reverseBits(uint32_t n)
  {
    uint32_t ans = 0, p = 31;
    while (n)
    {
      ans |= (n & 1) << p;
      --p;
      n >>= 1;
    }
    return ans;
  }
};