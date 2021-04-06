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

// Method 1: Recursive
class Solution {
 public:
  void helper(vector<int> &vec, TreeNode *root) {
    vec.push_back(root->val);
    if (root->left) helper(vec, root->left);
    if (root->right) helper(vec, root->right);
  }
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> vec;
    if (root) helper(vec, root);
    return vec;
  }
};

// Method 2: Iterative
class Solution1 {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    if (!root) return {};

    stack<TreeNode *> s;
    vector<int> vec;
    s.push(root);
    // root->left->right
    while (!s.empty()) {
      TreeNode *node = s.top();
      s.pop();
      vec.push_back(node->val);
      if (node->right) s.push(node->right);
      if (node->left) s.push(node->left);  // pop first
    }
    return vec;
  }
};
