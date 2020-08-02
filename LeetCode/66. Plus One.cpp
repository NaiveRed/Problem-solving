#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    int size = digits.size() - 1;
    while (size >= 0)
    {
      if (digits[size] == 9)
        digits[size--] = 0;
      else
      {
        ++digits[size];
        break;
      }
    }

    // The answer here will only be [1,...,0]
    if (size < 0)
    {
      // No need to insert actually
      // digits.insert(digits.begin(), 1);
      // We can just do this:
      digits[0] = 1;
      digits.push_back(0);
    }

    return digits;
  }
};