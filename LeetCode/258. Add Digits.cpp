#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Digital root
  int addDigits(int num)
  {
    return num ? (1 + (num - 1) % 9) : 0;
  }
};