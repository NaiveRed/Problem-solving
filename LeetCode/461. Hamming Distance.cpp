#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int hammingDistance(int x, int y)
  {
    // Method 1:
    //return bitset<32>(x ^ y).count();
    // Method 2:
    int ret = x ^ y, dis = 0;
    while (ret)
    {
      ++dis;
      ret &= (ret - 1);
    }
    return dis;
  }
};