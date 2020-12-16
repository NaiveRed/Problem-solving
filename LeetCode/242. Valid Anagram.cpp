#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    int size = s.size();
    if (size != t.size()) return false;
    int count[26] = {};
    for (int i = 0; i < size; ++i) {
      ++count[s[i] - 'a'];
      --count[t[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i)
      if (count[i]) return false;
    return true;
  }
};
