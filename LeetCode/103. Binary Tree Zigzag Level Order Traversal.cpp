#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (!root) return result;

    bool right_to_left = false;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int width = q.size();
      result.push_back(vector<int>(width));
      for (int i = 0; i < width; ++i) {
        TreeNode *node = q.front();
        q.pop();
        result.back()[i] = node->val;

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      if (right_to_left) reverse(result.back().begin(), result.back().end());
      right_to_left = !right_to_left;
    }

    return result;
  }
};
