#include <bits/stdc++.h>
using namespace std;

// Method 1 : Sliding window for substr
// and use map to keep the index of each characters.
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> char_map;
    // s_idx: start index of substring
    int len = s.size(), s_idx = 0, max_sub = 0;

    for (int i = 0; i < len; ++i) {
      // Current substr include this repeating char.
      // Use `.count` to avoid s_idx == 0 and default value of map.
      if (char_map.count(s[i]) && char_map[s[i]] >= s_idx)
        s_idx = char_map[s[i]] + 1;  // Move `s_idx` to the new postition.
      else
        max_sub = max(i - s_idx + 1, max_sub);

      char_map[s[i]] = i;  // Update index of character.
    }
    return max_sub;
  }
};

// Method 2 : Basic sliding window for substr.
class Solution2 {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> char_set;
    // s_idx: start index of substring
    int len = s.size(), s_idx = 0, max_sub = 0;

    for (int i = 0; i < len; ++i) {
      if (char_set.count(s[i]))  // Repeating
      {
        // Find the duplicate and
        // remove the characters before the repeating from the set.
        // Move `s_idx` to the new postition.
        while (s_idx < i) {
          char c = s[s_idx++];
          if (c != s[i])
            char_set.erase(c);
          else
            break;
        }
      } else {
        char_set.insert(s[i]);
        max_sub = (i - s_idx + 1 > max_sub) ? (i - s_idx + 1) : max_sub;
      }
    }
    return max_sub;
  }
};
