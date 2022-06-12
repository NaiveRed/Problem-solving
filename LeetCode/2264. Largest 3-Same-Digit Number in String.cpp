#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string largestGoodInteger(string num) {
        for (char c = '9'; c >= '0'; --c) {
            string s(3, c);
            if (num.find(s) != string::npos)
                return s;
        }
        return "";
    }
};

class Solution1 {
  public:
    string largestGoodInteger(string num) {
        char ans = '0' - 1;
        for (int i = 0, len = num.size(); i + 3 <= len;) {
            if (num[i] != num[i + 1]) {
                ++i;
                continue;
            }
            if (num[i + 1] != num[i + 2]) {
                i += 2;
                continue;
            }
            if (num[i] > ans) {
                ans = num[i];
            }
            i += 3;
        }

        return ans >= '0' ? string(3, ans) : "";
    }
};
