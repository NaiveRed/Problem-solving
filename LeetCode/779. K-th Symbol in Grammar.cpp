#include <bits/stdc++.h>
using namespace std;

// Method 1: recursive with binary tree
// Time: O(log K)
// Space: O(log K)
class Solution {
 public:
  // Change to 0-index
  int helper(int k) {
    if (!k) return 0;  // First column is always 0.

    if (k & 1)  // right child
    {
      // If parent is 0 => current is 1
      // If parent is 1 => current is 0
      return helper(k >> 1) ^ 1;

    } else  // left child
    {
      // If parent is 1 => current is 1
      // If parent is 0 => current is 0
      return helper(k >> 1);
    }

    // return helper(k >> 1) ^ (k & 1) is fine
  }
  int kthGrammar(int N, int K) { return helper(K - 1); }
};

// Method 2: recursive with binary tree
// Time: O(N)
// Space: O(N)
class Solution1 {
 public:
  int kthGrammar(int N, int K) {
    if (N == 1) return 0;
    // K is left : K is right
    return K % 2 ? kthGrammar(N - 1, (K >> 1) + 1)
                 : (kthGrammar(N - 1, (K >> 1)) ^ 1);
  }
};

// Method 3: iterative with binary tree
// Time: O(log k)
// Space: O(1)
class Solution2 {
 public:
  int kthGrammar(int N, int K) {
    // If current node is left child, its value is the same as parent.
    // otherwise it will be the opposite of parent.
    --K;  // Use 0-index
    bool same = true;
    while (K) {
      if (K & 1)  // right child
        same = !same;
      K >>= 1;
    }
    return same ? 0 : 1;
  }
};
