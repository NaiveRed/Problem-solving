#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Method 1: Brute force
  int strStr(string haystack, string needle) {
    int needle_size = needle.size();
    int size = haystack.size() - needle_size;
    if (!needle_size)
      return 0;
    else if (size < 0)
      return -1;
    for (int i = 0, j; i <= size; ++i) {
      for (j = 0; j < needle_size; ++j)
        if (haystack[i + j] != needle[j]) break;
      if (j == needle_size) return i;
    }
    return -1;
  }

  // Method 2: Z-algorithm
  int strStr1(string haystack, string needle) {
    int needle_size = needle.size();
    int size = haystack.size() - needle_size;
    if (!needle_size)
      return 0;
    else if (size < 0)
      return -1;

    string z(needle + '$' + haystack);
    int z_size = z.size();
    // Build z array(longest common prefix)
    vector<int> z_arr(z_size, 0);
    int l = 0, r = 0;  // z interval: [l, r)
    for (int i = 1; i < z_size; ++i) {
      // Case 1: not in the z interval
      if (i >= r) {
        l = r = i;
        // r-l: compare from the beginning of the z string(prefix)
        while (r < z_size && z[r] == z[r - l]) ++r;
        z_arr[i] = r - l;
      }
      // Case 1: in the z interval
      else {
        // Case a: the remain length is known, since it is less than `r` index
        if (i + z_arr[i - l] < r) z_arr[i] = z_arr[i - l];
        // Case b: the remain length is unknown
        else {
          while (r < z_size && z[r] == z[r - i]) ++r;
          z_arr[i] = r - i;
          l = i;  // update for a new interval
        }
      }

      // Early stop
      if (z_arr[i] == needle_size) break;
    }

    // Use z array to find the match
    for (int i = needle_size + 1; i < z_size; ++i)
      if (z_arr[i] == needle_size) return i - needle_size - 1;
    return -1;
  }

  // Method 3: Use built-in
  int strStr2(string haystack, string needle) {
    return (int)haystack.find(needle);
  }
};
int main() {
  Solution solution;
  cout << solution.strStr(string("caabxaabxaa"), string("aabxaabx")) << endl;
}
