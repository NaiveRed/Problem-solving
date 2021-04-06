// Ref to Leetcode 96
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// Method 1: Recursive with memoization.
// Time: NOT SURE!!! Please tell me if you know~
typedef vector<TreeNode *> Trees;
const int N = 9;
class Solution {
 public:
  Trees memo[N][N];  // Only use [a][b], a<b
  Trees helper(int l, int r) {
    if (l > r) return {nullptr};  // Trees{nullptr};
    if (!memo[l][r].empty()) return memo[l][r];
    Trees ans;
    // Use i as root node
    // i=1 (root)
    //  left_trees = (1, 0) => null
    //  right_trees = (2, 8) => all structs of (2, 8)
    // i=2 (root)
    //  left_trees = (1, 1) => {1}
    //  right_trees = (3, 8) => all structs of (3, 8)
    // i=3 (root)
    //  left_trees = (1, 2)
    //  right_trees = (4, 8)
    for (int i = l; i <= r; ++i) {
      // Possible structs of left subtree
      Trees left_trees = helper(l, i - 1);
      // Possible structs of right subtree
      Trees right_trees = helper(i + 1, r);
      // Use i to link all different combination of left and right subtree
      for (TreeNode *left_t : left_trees)
        for (TreeNode *right_t : right_trees) {
          TreeNode *root = new TreeNode(i);
          root->left = left_t;
          root->right = right_t;
          ans.push_back(root);
        }
    }
    memo[l][r] = ans;
    return ans;
  }
  vector<TreeNode *> generateTrees(int n) { return helper(1, n); }
};

// Method 2: DP
typedef vector<TreeNode *> Trees;
class Solution {
 public:
  vector<TreeNode *> generateTrees(int n) {
    Trees DP[n + 1][n + 1];

    // Build from len = 1 to n-1
    // len=0
    //      (1, 1), (2, 2), (3, 3), (4, 4), ...
    // len=1
    //      (1, 2), (2, 3), (3, 4), ...
    // len=2
    //      (1, 3), (2, 4), ...
    // len=3
    //      (1, 4), ...
    //
    // For each range (l, r), we use i: l -> r as root
    // and construct the subtree with pre-build DP
    // left: (l, i-1)
    // root: i
    // right: (i+1, r)
    for (int len = 0; len < n; ++len) {
      for (int l = 1; l <= n - len; ++l) {
        int r = l + len;
        for (int i = l; i <= r; ++i) {
          Trees left_trees = l <= i - 1 ? DP[l][i - 1] : Trees{nullptr};
          Trees right_trees = i + 1 <= r ? DP[i + 1][r] : Trees{nullptr};
          for (TreeNode *left_t : left_trees)
            for (TreeNode *right_t : right_trees) {
              TreeNode *root = new TreeNode(i);
              root->left = left_t;
              root->right = right_t;
              DP[l][r].push_back(root);
            }
        }
      }
    }

    return DP[1][n];
  }
};
