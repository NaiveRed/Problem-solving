#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

// Method 1: recursive
// Time: O(NlogN), N for find mid, logN for spliting two part.
// Space: O(logN) for the call stack.
//    (It's balanced tree, so the height will be logN)
class Solution {
 public:
  ListNode *findMid(ListNode *head) {
    ListNode *fast = head, *slow = head, *prev = nullptr;
    while (fast && fast->next) {
      fast = fast->next->next;
      prev = slow;
      slow = slow->next;
    }
    // Split list to two part, i.e., make left tail link to nullptr
    if (prev) prev->next = nullptr;
    // Return the middle node.
    // If the number of node is even, we return the one of right part.
    return slow;
  }
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) return nullptr;

    ListNode *mid = findMid(head);
    TreeNode *root = new TreeNode(mid->val);
    // It does not matter if there is only mid (i.e., one node).
    root->right = sortedListToBST(mid->next);
    if (head != mid)  // There are at least 2 nodes. i.e., exist left part
      root->left = sortedListToBST(head);
    return root;
  }
};

// Method 2: Convert to array, can reduce the `find mid` complexity,
//  but need more space.
// Time: O(N)
// Space: O(N)
class Solution1 {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) return nullptr;
    vector<int> arr;
    while (head) {
      arr.push_back(head->val);
      head = head->next;
    }

    return helper(arr, 0, arr.size() - 1);
  }
  TreeNode *helper(vector<int> &arr, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(arr[mid], helper(arr, left, mid - 1),
                                  helper(arr, mid + 1, right));
    return root;
  }
};

// Method 3: Build the tree by inorder-traverse(ascending order with BST).
//    Since we know the length of list,
//    we can deduce the position of balanced BST
//    by computing the implicit height(left and right) and inorder sequence.
//    E.g., the leftmost node in the tree is the head of list.
//    0->1->2->3->4 is same as the inorder.
//    2
//   / \
//  0   3
//   \   \
//    1   4
// Time: O(N)
// Space: O(logN)
class Solution2 {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    int len = 0;
    ListNode *node = head;
    while (node) {
      ++len;
      node = node->next;
    }

    return helper(&head, 0, len - 1);
  }
  // Use pointer-to-pointer to change the pointer of previous call
  TreeNode *helper(ListNode **head, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;
    // Go left
    TreeNode *left_child = helper(head, left, mid - 1);

    // Process root
    // cout << left << " " << right << ' ' << (*head)->val << endl;
    TreeNode *root = new TreeNode((*head)->val);
    root->left = left_child;
    *head = (*head)->next;

    // Go right
    TreeNode *right_child = helper(head, mid + 1, right);
    root->right = right_child;
    return root;
  }
};
