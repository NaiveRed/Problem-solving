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
    if (root->left) helper(vec, root->left);
    if (root->right) helper(vec, root->right);
    vec.push_back(root->val);
  }
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> vec;
    if (root) helper(vec, root);
    return vec;
  }
};

// Method 2: Iterative by two stack(one use reversed vector)
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode *root) {
    if (!root) return {};
    vector<int> vec;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
      TreeNode *node = s.top();
      s.pop();
      vec.push_back(node->val);
      if (node->left) s.push(node->left);
      if (node->right) s.push(node->right);
    }
    reverse(vec.begin(), vec.end());
    return vec;
  }
};

// Method 3: Iterative by one stack
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode *root) {
    if (!root) return {};
    vector<int> vec;
    stack<TreeNode *> s;
    TreeNode *node = root;
    while (node || !s.empty()) {
      if (node) {
        if (node->right) s.push(node->right);
        s.push(node);
        node = node->left;
      } else {
        TreeNode *curr = s.top();
        s.pop();
        if (!s.empty() && curr->right == s.top()) {
          node = s.top();
          s.pop();
          s.push(curr);
        } else
          vec.push_back(curr->val);
      }
    }
    return vec;
  }
};
