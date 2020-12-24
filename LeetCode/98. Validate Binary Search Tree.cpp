#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
class Solution
{
public:
    // Method 1: recursively traverse with valid range
    bool isValidBST(TreeNode *root, TreeNode *left_bound = nullptr,
                    TreeNode *right_bound = nullptr)
    {
        if (root == nullptr)
            return true;
        if ((left_bound != nullptr && root->val <= left_bound->val) ||
            (right_bound != nullptr && root->val >= right_bound->val))
            return false;
        return isValidBST(root->left, left_bound, root) &&
               isValidBST(root->right, root, right_bound);
    }

    // Method 2: use in-order traversal
    bool isValidBST2(TreeNode *root)
    {
        stack<TreeNode *> S;
        TreeNode *prev_node = nullptr;

        // Order: left -> root -> right
        while (!S.empty() || root != nullptr)
        {
            // Go left
            while (root)
            {
                S.push(root);
                root = root->left;
            }
            TreeNode *node = S.top();
            S.pop();
            // Valid: 每次取出來的 node 都要比上次 in-order 所遇到的 node 還大
            // prev_node 在 left: 要小於當前 node(root)
            // prev_node 在 root: 要小於當前 node(right)
            // prev_node 在 right: 要小於當前 node
            // (root of upper level, was just at the S.top())
            if (prev_node != nullptr && prev_node->val >= node->val)
                return false;

            // 確認完的 node 後:
            // 1. 更新 prev_node
            // 2. 檢查其右子樹
            prev_node = node;
            root = node->right;
        }

        return true;
    }
};
