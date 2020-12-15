#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    int size = s.size();
    // Two-pointer for trimming spaces
    bool space = true;
    int idx = 0;
    for (int i = 0; i < size; ++i) {
      if (s[i] == ' ') {
        if (!space) {
          s[idx++] = ' ';
          space = true;
        }
      } else {
        s[idx++] = s[i];
        space = false;
      }
    }

    size = idx;
    // Remove tail and check last space
    s.erase(s[size - 1] == ' ' ? (--size) : size);

    // Reverse
    idx = 0;
    reverse(s, 0, size - 1);  // Reverse whole string
    for (int i = 0; i < size; ++i) {
      if (s[i] == ' ') {
        reverse(s, idx, i - 1);  // Reverse each word
        idx = i + 1;
      }
    }
    reverse(s, idx, size - 1);  // Reverse final word
    return s;
  }

  void reverse(string& s, int i, int j) {
    // Include s[j]
    while (i < j) swap(s[i++], s[j--]);
  }
};
