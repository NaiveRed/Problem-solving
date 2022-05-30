#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int percentageLetter(string s, char letter) {
        return count(s.begin(), s.end(), letter) * 100 / s.size();
    }
};
