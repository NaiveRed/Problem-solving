#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    string longest = "";
    // Iterate over each postition for the center of palindrome.
    // Expand around center and check palindrome.
    for (int i = 0, s_len = s.size(); i < s_len; ++i) {
      // Check palindrome from the center of `i`.
      // The total length of substr should be odd.
      int h_len = 0;  // half length
      while (i - h_len >= 0 && i + h_len < s_len &&
             s[i - h_len] == s[i + h_len])
        ++h_len;
      // The center point will count twice.
      if (h_len * 2 - 1 > longest.size())
        longest = s.substr(i - h_len + 1, h_len * 2 - 1);

      // Check palindrome from the center between `i` and `i+1`.
      // The total length of substr should be even.
      h_len = 0;
      while (i - h_len >= 0 && i + h_len + 1 < s_len &&
             s[i - h_len] == s[i + h_len + 1])
        ++h_len;
      if (h_len * 2 > longest.size())
        longest = s.substr(i - h_len + 1, h_len * 2);
    }
    return longest;
  }
};
