#include <bits/stdc++.h>
#define DEBUG
using namespace std;

class Solution
{
public:
  double myPow(double x, int n)
  {
    // Use unsigned because -2147483648 will overflow
    unsigned int p = abs(n);
    // Binary Exponentiation
    double res = 1;
    while (p)
    {
      if (p & 1)
        res *= x;
      x *= x;
      p >>= 1;
    }
    return (n > 0) ? res : (1.0 / res);
  }
};