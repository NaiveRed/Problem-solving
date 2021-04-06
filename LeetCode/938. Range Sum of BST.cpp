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

// Method 1: dfs tree traverse (recursive)
// Time: O(n)
class Solution {
 public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    if (!root) return 0;
    int sum = 0;
    if (root->val >= low && root->val <= high) sum = root->val;
    // If root->val < low, then its left child will not be in valid range.
    if (root->val > low) sum += rangeSumBST(root->left, low, high);
    // If root->val > low, then its right child will not be in valid range.
    if (root->val < high) sum += rangeSumBST(root->right, low, high);
    return sum;
  }
};

// Method 2: dfs tree traverse (iterative)
// Time: O(n)
class Solution1 {
 public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    if (!root) return 0;
    int sum = 0;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
      TreeNode *node = s.top();
      s.pop();
      if (node->val >= low && node->val <= high) sum += node->val;
      // Right child
      if (node->val < high && node->right) s.push(node->right);
      // Left child
      if (node->val > low && node->left) s.push(node->left);
    }

    return sum;
  }
};
