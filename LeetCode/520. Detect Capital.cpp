#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool detectCapitalUse(string word)
  {
    bool first_caps = isupper(word[0]);
    if (first_caps)
    {
      for (int i = 1; i < word.size() - 1; ++i)
        if (isupper(word[i]) != isupper(word[i + 1]))
          return false;
    }
    else
      for (char c : word)
        if (isupper(c))
          return false;
    return true;
  }
};