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
    vec.push_back(root->val);
    if (root->right) helper(vec, root->right);
  }
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> vec;
    if (root) helper(vec, root);
    return vec;
  }
};

// Method 2: Iterative
class Solution1 {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    if (!root) return {};

    vector<int> vec;
    stack<TreeNode *> s;
    TreeNode *node = root;
    while (node || !s.empty()) {
      while (node) {
        s.push(node);
        node = node->left;
      }
      node = s.top();
      s.pop();
      vec.push_back(node->val);
      node = node->right;
    }
    return vec;
  }
};

// Method 3: Morris algorithm
class Solution2 {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> vec;
    TreeNode *curr = root;
    while (curr) {
      // Case 2
      if (curr->left) {
        // Find predecessor
        // (i.e., the rightmost node in the left subtree)
        // rightmost in BST means smallest.
        TreeNode *pred = curr->left;
        while (pred->right && pred->right != curr) pred = pred->right;

        if (pred->right) {
          // 2.b) The right child of predecessor is `curr`.
          // The left subtree of curr have done
          vec.push_back(curr->val);
          pred->right = nullptr;
          curr = curr->right;
        } else {
          // 2.a) The predecessor has no right child,
          // so link it to the `curr`
          pred->right = curr;
          curr = curr->left;
        }

      } else {
        // Case 1: No left child.
        vec.push_back(curr->val);
        curr = curr->right;
      }
    }
    return vec;
  }
};
