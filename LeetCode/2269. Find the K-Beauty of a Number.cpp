#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
  public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int i = 0, len = s.size(), ans = 0;
        while (i + k - 1 < len) {
            int m = stoi(s.substr(i, k));
            if (m && !(num % m))
                ++ans;
            ++i;
        }
        return ans;
    }
};
