#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool hasAllCodes(string s, int k) {
        int n = 1 << k, slen = s.size();
        // slen - k + 1: the number of substr of s
        if (slen - k + 1 < n) {
            return false;
        }
        vector<bool> arr(n, false);
        unsigned int mask = n - 1, val = 0;

        // init for substr[0:k]
        for (int i = 0; i < k; ++i) {
            val = (val << 1) | (s[i] - '0');
        }
        for (int i = 0;; ++i) {
            if (!arr[val]) {
                if (!(--n))
                    return true;
                arr[val] = true;
            }
            if (i + k >= slen)
                break;
            // remove leftmost digit(MSB) and add LSB from s
            // use mask for only k bits
            val = ((val << 1) | (s[i + k] - '0')) & mask;
        }
        return false;
    }
};

class Solution2 {
  public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> string_set;
        int n = 1 << k;
        for (int i = 0, t = s.size(); i <= t - k; ++i) {
            auto [_, ret] = string_set.insert(s.substr(i, k));
            if (ret && !(--n))
                return true;
        }
        return false;
    }
};
