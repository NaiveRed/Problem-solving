#include <bits/stdc++.h>
using namespace std;

// Method 1: 2D array
// Time: O(len1*len2)
// Space: O(len1*len2)
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.size(), len2 = s2.size();
    if (len1 + len2 != s3.size()) return false;
    bool dp[101][101] = {};
    dp[0][0] = true;

    //     s2 [0] [1] ...
    // s1  T
    // [0]
    // [1]
    // ...
    // i: count of used characters of s1
    // j: count of used characters of s2
    for (int i = 0; i <= len1; ++i)
      for (int j = 0; j <= len2; ++j) {
        if (i && s1[i - 1] == s3[i + j - 1]) dp[i][j] |= dp[i - 1][j];
        if (j && s2[j - 1] == s3[i + j - 1]) dp[i][j] |= dp[i][j - 1];
      }

    return dp[len1][len2];
  }
};

// Method 2: 1D array
// Time: O(len1*len2)
// Space: O(len2)
class Solution1 {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.size(), len2 = s2.size();
    if (len1 + len2 != s3.size()) return false;
    vector<bool> dp(len2 + 1, false);
    dp[0] = true;

    // Use 1D array: implicit table
    // dp[x]: not used character of s1[x]
    // dp[x-1]: not used character of s2[x]

    for (int i = 0; i <= len1; ++i)
      for (int j = 0; j <= len2; ++j) {
        if (!i && !j) continue;
        // Match s3[0 ~ i-1] with s1[0 ~ i-1] and
        // Use i-1(th) of s1
        if (!j && dp[j]) dp[j] = (s1[i - 1] == s3[i - 1]);
        // Match s3[0 ~ j-1] with s2[0 ~ j-1] and
        // Use j-1(th) of s2
        else if (!i && dp[j - 1])
          dp[j] = (s2[j - 1] == s3[j - 1]);
        else if (i && j) {
          char c = s3[i + j - 1];
          dp[j] = (dp[j] && s1[i - 1] == c) || (dp[j - 1] && s2[j - 1] == c);
        }
      }

    return dp[len2];
  }
};
