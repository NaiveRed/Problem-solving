#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// Method 1: recursive, top-down
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) return root->val == targetSum;

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
  }
};

// Method 2: iterative
class Solution1 {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    stack<TreeNode*> s;  // Use val to keep cumulative sum
    s.push(root);
    while (!s.empty()) {
      TreeNode* node = s.top();
      s.pop();
      if (!node->left && !node->right && node->val == targetSum) return true;

      if (node->right) {
        node->right->val += node->val;
        s.push(node->right);
      }
      if (node->left) {
        node->left->val += node->val;
        s.push(node->left);
      }
    }
    return false;
  }
};
