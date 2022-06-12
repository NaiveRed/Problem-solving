#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool digitCount(string num) {
        int count[10] = {};
        for (const char& c : num) {
            ++count[c - '0'];
        }
        for (int i = 0, n = num.size(); i < n; ++i) {
            if (count[i] != num[i] - '0')
                return false;
        }
        return true;
    }
};

