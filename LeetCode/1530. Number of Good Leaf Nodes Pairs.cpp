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
  vector<int> dfs(TreeNode *root, int &distance, int &ans)
  {
    if (root->left == nullptr && root->right == nullptr)
    {
      return vector<int>{0};
    }

    vector<int> left_leaf, right_leaf;
    if (root->left)
      left_leaf = dfs(root->left, distance, ans);
    if (root->right)
      right_leaf = dfs(root->right, distance, ans);

    for (int &l : left_leaf)
      ++l;
    for (int &r : right_leaf)
      ++r;

    for (int &l : left_leaf)
      for (int &r : right_leaf)
        if (l + r <= distance)
          ++ans;

    // All leaf int this subtree
    left_leaf.insert(left_leaf.end(), right_leaf.begin(), right_leaf.end());
    return left_leaf;
  }
  int countPairs(TreeNode *root, int distance)
  {
    int ans = 0;
    dfs(root, distance, ans);
    return ans;
  }
};