#include <bits/stdc++.h>
using namespace std;

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
  int widthOfBinaryTree(TreeNode *root)
  {
    // Use the val of TreeNode to keep the position in one level
    int ans = 0, level;
    queue<TreeNode *> q;
    if (!root)
      return ans;
    root->val = 0;
    q.push(root);
    while (!q.empty())
    {
      int left = q.front()->val, right = left;
      // Same level
      for (int i = 0, k = q.size(); i < k; ++i)
      {
        TreeNode *node = q.front();
        q.pop();
        if (i == k - 1)
          right = node->val;

        // Let the position of node on next level based on current left
        // like an offset (i.e. start from zero)
        // or you will need to use unsigned long long to keep the position
        int new_val = node->val - left;
        if (node->left)
        {
          node->left->val = new_val << 1;
          q.push(node->left);
        }
        if (node->right)
        {
          node->right->val = (new_val << 1) + 1;
          q.push(node->right);
        }
      }

      ans = max(right - left + 1, ans);
    }

    return ans;
  }
};