#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

  bool isPalindrome(string s)
  {
    for (int len = s.size(), h = 0, t = len - 1; h < t; ++h, --t)
    {
      while (h < len && !isalnum(s[h]))
        ++h;
      while (t >= 0 && !isalnum(s[t]))
        --t;
      if (h >= t)
        return true;
      if (tolower(s[h]) != tolower(s[t]))
        return false;
    }
    return true;
  }
};