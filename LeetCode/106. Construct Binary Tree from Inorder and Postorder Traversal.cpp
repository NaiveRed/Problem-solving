#include <bits/stdc++.h>
#define dbg(x) cout << #x " = " << x << endl;
using namespace std;
// Definition for a binary tree node.
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
  TreeNode *build(int in_left, int in_right, int post_root_idx, vector<int> &inorder, vector<int> &postorder)
  {
    if (in_left > in_right)
      return nullptr;
    int root_val = postorder[post_root_idx], in_root_idx;
    TreeNode *node = new TreeNode(root_val);
    // Find the index of the root in the inorder
    while (inorder[in_root_idx] != root_val)
      ++in_root_idx;

    // Build the right subtree
    // Root: the rightmost of postorder
    node->right = build(in_root_idx + 1, in_right, post_root_idx - 1, inorder, postorder);

    // Build the left subtree
    // Number of nodes in the right subtree: in_right - in_root_idx
    // Root: the rightmost of postorder before the number of nodes in the right subtree
    node->left = build(in_left, in_root_idx - 1, post_root_idx - (in_right - in_root_idx) - 1, inorder, postorder);
    return node;
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    return build(0, postorder.size() - 1, postorder.size() - 1, inorder, postorder);
  }
};