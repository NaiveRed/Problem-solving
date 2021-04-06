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

// Method 1: recursive
class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val > root->val)
      root->right = insertIntoBST(root->right, val);
    else
      root->left = insertIntoBST(root->left, val);
    return root;
  }
};

// Method 2: iterative
class Solution1 {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    TreeNode* node = root;
    while (true) {
      if (val > node->val) {
        if (!node->right) {
          node->right = new TreeNode(val);
          break;
        } else
          node = node->right;
      } else if (val < node->val) {
        if (!node->left) {
          node->left = new TreeNode(val);
          break;
        } else
          node = node->left;
      }
    }
    return root;
  }
};

// Method 3: iterative, nice style
class Solution2 {
 public:
  // Will not change the variable passed to root (call by value)
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode** node = &root;
    while (*node)
      node = (val > (*node)->val) ? &((*node)->right) : &((*node)->left);
    *node = new TreeNode(val);
    return root;
  }
};

int main() {
  Solution2 s;
  TreeNode* root = nullptr;
  root = s.insertIntoBST(root, 5);
  cout << root->val << endl;
  return 0;
}
