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
    // Method 1: Recursion(DFS)
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    // Method 2: DFS
    typedef pair<int, TreeNode *> LevelNode;
    int maxDepth2(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int depth = 0;
        stack<LevelNode> S;
        S.push(make_pair(1, root));
        while (!S.empty())
        {
            LevelNode node = S.top();
            S.pop();
            int level = node.first;
            depth = max(level, depth);
            if (node.second->left != nullptr)
                S.push(make_pair(level + 1, node.second->left));
            if (node.second->right != nullptr)
                S.push(make_pair(level + 1, node.second->right));
        }
        return depth;
    }

    // Method 3: BFS
    int maxDepth3(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int depth = 0;
        queue<TreeNode *> Q;
        // BFS
        Q.push(root);
        while (!Q.empty())
        {
            ++depth;
            // Q.size(): get the number of nodes at current level
            for (int i = Q.size(); i; --i)
            {
                TreeNode *node = Q.front();
                Q.pop();
                if (node->left != nullptr)
                    Q.push(node->left);
                if (node->right != nullptr)
                    Q.push(node->right);
            }
        }
        return depth;
    }
};
