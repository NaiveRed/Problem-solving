#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int count[46] = {1, 1, 2};
  Solution()
  {
    for (int i = 3; i < 46; ++i)
      count[i] = count[i - 1] + count[i - 2];
  }

public:
  int climbStairs(int n)
  {
    return count[n];
  }
};