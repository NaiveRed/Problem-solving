#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int nthUglyNumber(int n)
  {
    int u[1700] = {1}, i2 = 0, i3 = 0, i5 = 0;
    for (int i = 0; i < n - 1; ++i)
    {
      if (2 * u[i2] <= u[i])
        ++i2;
      if (3 * u[i3] <= u[i])
        ++i3;
      if (5 * u[i5] <= u[i])
        ++i5;
      u[i + 1] = min({2 * u[i2], 3 * u[i3], 5 * u[i5]});
    }
    return u[n - 1];
  }
};