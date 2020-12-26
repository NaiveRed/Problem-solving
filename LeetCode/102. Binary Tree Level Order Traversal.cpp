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
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) return {};
    queue<TreeNode *> Q;
    vector<vector<int>> ans;
    Q.push(root);
    while (!Q.empty()) {
      vector<int> level;
      for (int i = Q.size(); i; --i) {
        TreeNode *node = Q.front();
        Q.pop();
        if (node->left != nullptr) Q.push(node->left);
        if (node->right != nullptr) Q.push(node->right);
        level.push_back(node->val);
      }
      ans.push_back(level);
    }
    return ans;
  }
};
