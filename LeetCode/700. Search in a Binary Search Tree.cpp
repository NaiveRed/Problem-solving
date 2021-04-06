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

// Method 1: recursive
class Solution {
 public:
  TreeNode *searchBST(TreeNode *root, int val) {
    if (!root) return nullptr;
    if (val > root->val) return searchBST(root->right, val);
    if (val < root->val) return searchBST(root->left, val);
    return root;
  }
};

// Method 2: iterative
class Solution1 {
 public:
  TreeNode *searchBST(TreeNode *root, int val) {
    while (root) {
      if (val > root->val)
        root = root->right;
      else if (val < root->val)
        root = root->left;
      else
        return root;
    }
    return nullptr;
  }
};
