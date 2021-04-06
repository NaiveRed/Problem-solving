#include <bits/stdc++.h>
using namespace std;

// Method 1
class Solution {
 public:
  int gcd(int a, int b) {
    while (b) {
      int t = b;
      b = a % b;
      a = t;
    }
    return a;
  }
  string gcdOfStrings(string str1, string str2) {
    // The str1 and str2 can be divided by `s`, if they have the same prefix.
    // The length of `s` should be the gcd of their length.
    // Because if there exists a string shorter than `s` and
    // can concatenate to str1 and str2, it can be extended to `s`.
    if (str1 + str2 == str2 + str1)
      return str1.substr(0, gcd(str1.size(), str2.size()));
    return "";
  }
};

// Method 2: less memory
class Solution1 {
 public:
  int gcd(int a, int b) {
    while (b) {
      int t = b;
      b = a % b;
      a = t;
    }
    return a;
  }
  string gcdOfStrings(string str1, string str2) {
    int len1 = str1.size(), len2 = str2.size();
    int prefix_len = gcd(len1, len2);

    for (int i = 0; i < len1; ++i)
      if (str1[i] != str2[i % prefix_len]) return "";

    for (int i = 0; i < len2; ++i)
      if (str2[i] != str1[i % prefix_len]) return "";

    return str1.substr(0, prefix_len);
  }
};
