#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Method 1: top down merge sort
// Time: O(n log n)
// Space: O(log n) for recursive call stack
class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    // head: edge case for empty list.
    // head->next: if there is only one node, no need to sort.
    if (!head || !head->next) return head;

    ListNode* mid = findMidAndSplit(head);
    ListNode* left_head = sortList(head);  // Head of left part
    ListNode* right_head = sortList(mid);  // Head of right part
    return merge(left_head, right_head);
  }

  //     s   f
  // 1 2 3 4
  // 1 2 3 4 5
  //     s   f
  ListNode* findMidAndSplit(ListNode* head) {
    ListNode *fast = head, *slow = head, *prev = nullptr;

    // Case 1: fast is null, number of nodes is even: slow` is second middle.
    // Case 2: fast->next is null, number of nodes is odd: `slow` is middle.
    while (fast && fast->next) {
      fast = fast->next->next;
      prev = slow;
      slow = slow->next;
    }

    // Split into two parts
    // Make the tail of left part point to the nullptr.
    prev->next = nullptr;

    // Found the middle.
    // if the number is even, use second middle.
    // (E.g. `1 2 3 4` return `3`)
    // (E.g. `1 2 3 4 5` return `3`)
    return slow;
  }

  // Merge two sorted list and return its head.
  ListNode* merge(ListNode* left, ListNode* right) {
    ListNode dummy_head, *node = &dummy_head;
    while (left && right) {
      if (left->val < right->val) {
        node->next = left;
        left = left->next;
      } else {
        node->next = right;
        right = right->next;
      }
      node = node->next;
    }
    if (left)
      node->next = left;
    else
      node->next = right;
    return dummy_head.next;
  }
};

// Bubble sort, O(N^2)
// TLE
class Solution2 {
 public:
  ListNode* sortList(ListNode* head) {
    ListNode* curr = head;
    int n = 0;
    while (curr) {
      ++n;
      curr = curr->next;
    }
    ListNode dummy_head(0, head), *prev;
    for (int i = 0; i < n - 1; ++i) {
      prev = &dummy_head;
      curr = dummy_head.next;
      for (int j = n - i - 1; j; --j) {
        // swap two nodes
        ListNode* next_node = curr->next;
        if (curr->val > next_node->val) {
          prev->next = next_node;
          curr->next = next_node->next;
          next_node->next = curr;
          // since the curr node is switched to next,
          // we do not need to advance it again.
        } else
          curr = curr->next;  // Move to next
        prev = prev->next;
      }
    }
    return dummy_head.next;
  }
};
