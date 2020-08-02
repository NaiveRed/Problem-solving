#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minFlips(string target)
  {
    int count = 0, idx = 0;
    char prev = '0';
    for (; idx < target.size(); ++idx)
      if (target[idx] != '0')
        break;
    // Start from the first '1'
    while (idx < target.size())
    {
      if (target[idx] != prev)
        ++count;
      prev = target[idx];
      ++idx;
    }
    return count;
  }
};