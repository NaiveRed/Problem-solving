#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numSub(string s)
  {
    int ans = 0, n = 0;
    for (auto c : s)
    {
      if (c == '0')
        n = 0;
      else
      {
        ans += (++n);
        ans %= 1000000007;
      }
    }
    return ans;
  }
};