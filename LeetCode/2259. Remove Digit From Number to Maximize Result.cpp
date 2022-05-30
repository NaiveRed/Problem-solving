#include <bits/stdc++.h>
using namespace std;

// O(n)
class Solution {
  public:
    string removeDigit(string number, char digit) {
        int x = 0, n = number.size();
        for (int i = 0; i < n; ++i) {
            if (digit == number[i]) {
                x = i;
                if (i + 1 == n || digit < number[i + 1]) {
                    break;
                }
            }
        }
        number.erase(x, 1);
        return number;
    }
};
