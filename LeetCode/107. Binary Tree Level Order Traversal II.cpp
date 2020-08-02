#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    vector<vector<int>> result;
    queue<TreeNode *> q;
    // ! root can be null
    if (!root)
      return result;
    q.push(root);

    while (!q.empty())
    {
      int level = q.size();
      vector<int> level_result;
      while (level--)
      {
        TreeNode *node = q.front();
        q.pop();

        level_result.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      result.push_back(level_result);
    }

    return vector<vector<int>>(result.rbegin(), result.rend());
  }
};
