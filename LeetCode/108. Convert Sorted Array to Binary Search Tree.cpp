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
  TreeNode *build(vector<int> &num, int left, int right) {
    int middle = (right + left) / 2;
    TreeNode *root;
    if (left != right) {
      root = new TreeNode(num[middle]);
      // Create left node if at least there are three numbers.
      if (right - left > 1) root->left = build(num, left, middle - 1);
      root->right = build(num, middle + 1, right);
    } else
      root = new TreeNode(num[left]);

    return root;
  }
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return nums.size() ? build(nums, 0, nums.size() - 1) : nullptr;
  }
};
int main() {
  Solution sol;
  vector<int> v{-10, -3, 0, 5, 9};
  sol.sortedArrayToBST(v);
  return 0;
}
