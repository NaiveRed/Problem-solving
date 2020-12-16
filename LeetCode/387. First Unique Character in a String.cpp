#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    int dict[26] = {};
    for (int i = 0; i < s.size(); ++i) ++dict[s[i] - 'a'];
    for (int i = 0; i < s.size(); ++i)
      if (dict[s[i] - 'a'] == 1) return i;
    return -1;
  }
};
