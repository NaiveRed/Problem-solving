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
class Solution {
 public:
  // Method 1: recursive
  bool isMirror(TreeNode *a, TreeNode *b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;

    return (a->val == b->val) && isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
  }
  bool isSymmetric(TreeNode *root) {
    return root == nullptr || isMirror(root->left, root->right);
  }

  // Method 2: iterative
  bool isSymmetric2(TreeNode *root) {
    queue<TreeNode *> Q;
    Q.push(root);
    Q.push(root);
    while (!Q.empty()) {
      TreeNode *left = Q.front();
      Q.pop();
      TreeNode *right = Q.front();
      Q.pop();
      if ((left == nullptr && right != nullptr) ||
          (left != nullptr && right == nullptr))
        return false;
      if (left != nullptr)  // both not nullptr
      {
        if (left->val != right->val) return false;
        // Two consecutive node should be equal
        // Pair 1
        Q.push(left->left);
        Q.push(right->right);
        // Pair 2
        Q.push(left->right);
        Q.push(right->left);
      }
    }
    return true;
  }
};
