#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// Method 1:
// Time: O(N)
// Space: O(1)
class Solution {
 public:
  Node* connect(Node* root) {
    Node* level_head = root;  // The head of each level
    while (level_head) {
      Node* node = level_head; 
      // Link the `next` level by level.
      // Link the child of current node to their next,
      // then move to next node at the current level(by `next` of current node).
      while (node && node->left) {
        node->left->next = node->right;
        // The `next` of right child can be found by current next then left.
        if (node->next) node->right->next = node->next->left;
        node = node->next;
      }
      // Back to the head of next level.
      level_head = level_head->left;
    }
    return root;
  }
};
