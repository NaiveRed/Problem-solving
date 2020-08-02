#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {    
    int remain_bits = 0;
    for (int &n : nums)
      remain_bits ^= n;

    // Get the least significant bit
    // (2's complement trick)
    int lsb = remain_bits & (-remain_bits);
    int a = 0, b = 0;

    // Group the number into `a`'s team and `b`'s team
    // If the bit matches the LSB go into the `a`'s team,
    // otherwise go into the `b`'s team
    for (int &n : nums)
      if (lsb & n)
        a ^= n;
      else
        b ^= n;

    return vector<int>{a, b};
  }
};