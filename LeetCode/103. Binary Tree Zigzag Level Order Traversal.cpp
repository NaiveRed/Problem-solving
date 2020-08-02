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

class Solution
{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> result;
    if (!root)
      return result;

    bool left_to_right = true;
    queue<TreeNode *> q;
    q.push(root);
    stack<int> s; // For right to left

    while (!q.empty())
    {
      int width = q.size();
      vector<int> lev_res(width);
      for (int i = 0; i < width; ++i)
      {
        TreeNode *node = q.front();
        if (left_to_right)
          lev_res[i] = (node->val);
        else
          s.push(node->val);

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);

        q.pop();
      }

      if (!left_to_right)
        for (int i = 0; i < width; ++i)
        {
          lev_res[i] = s.top();
          s.pop();
        }

      left_to_right = !left_to_right;
      result.emplace_back(std::move(lev_res));
    }

    return result;
  }
};