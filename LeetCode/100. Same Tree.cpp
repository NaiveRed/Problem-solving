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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    queue<TreeNode *> a, b;
    if (!p || !q)
      return p == q;
    a.push(p);
    b.push(q);
    while (!a.empty())
    {
      for (int i = a.size(); i; --i)
      {
        TreeNode *a_node = a.front(), *b_node = b.front();
        a.pop(), b.pop();
        if (a_node->val != b_node->val)
          return false;
        if (a_node->left && b_node->left)
        {
          a.push(a_node->left);
          b.push(b_node->left);
        }
        else if (a_node->left != b_node->left)
          return false;
        if (a_node->right && b_node->right)
        {
          a.push(a_node->right);
          b.push(b_node->right);
        }
        else if (a_node->right != b_node->right)
          return false;
      }
    }
    return true;
  }
};