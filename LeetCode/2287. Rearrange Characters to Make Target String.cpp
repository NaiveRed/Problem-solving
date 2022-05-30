#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rearrangeCharacters(string s, string target) {
        int count1[26] = {}, count2[26] = {};

        for (const char& c : s) {
            ++count1[c - 'a'];
        }
        for (const char& c : target) {
            ++count2[c - 'a'];
        }

        int ans = 1000;
        for (int i = 0; i < 26; ++i) {
            if (count2[i]) {
                if (!count1[i])
                    return 0;
                ans = min(ans, count1[i] / count2[i]);
            }
        }
        return ans;
    }
};
