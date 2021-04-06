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

// Iterative
// Time: O(N)
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return nullptr;

    // Count for the length.
    int length = 1;
    ListNode* node = head;
    while (node->next) {
      node = node->next;
      ++length;
    }
    // Current node is at the tail.
    ListNode* tail = node;

    // Goal: find the new tail.
    // 1. Determine which node is tail after rotating.
    //    i.e., 1 -> 2 -> 3 -> 4 -> 5 ; if k == 6
    //    the new tail will be (len-(k%len))th node which is 4 (5-(6%5)).
    int pos = length - (k % length);
    if (pos == length) return head;  // No change

    // 2. We need to link tail to head and
    //    link tail to the null
    //    i.e., 5 -> 1 -> 2 -> 3 -> 4
    //          ------              --
    //    `next` of 4 should be the null.
    tail->next = head;
    ListNode* new_tail = head;
    for (int i = 1; i < pos; ++i) new_tail = new_tail->next;
    ListNode* new_head = new_tail->next;
    new_tail->next = nullptr;

    return new_head;
  }
};

// Recursive
// Time: O(n^2),
// since it need to traverse in helper to determine tail each round
class Solution1 {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !k) return head;
    // Count for the length.
    int length = 1;
    ListNode* node = head;
    while (node->next) {
      node = node->next;
      ++length;
    }
    if (length == 1) return head;

    return helper(head, k % length);
  }

  // Rotate one step
  ListNode* helper(ListNode* head, int k) {
    // Return new head
    if (!k) return head;

    // Goal: find the new head/tail.
    // 1. Determine which node is tail after rotating.
    //    i.e., 1 -> 2 -> 3 -> 4(prev) -> 5(tail)
    ListNode* prev_tail = head;
    while (prev_tail->next->next) prev_tail = prev_tail->next;

    // 2. We need to link tail to head and
    //    link tail to the null
    //    i.e., 5 -> 1 -> 2 -> 3 -> 4
    //          ------              --
    //    `next` of 4 should be the null.
    ListNode* new_head = prev_tail->next;
    new_head->next = head;
    prev_tail->next = nullptr;
    return helper(new_head, k - 1);
  }
};

// Recursive 2
// Time: O(N)
class Solution2 {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !k) return head;
    // Count for the length.
    int length;
    // if k == 6
    // 1 -> 2 -> 3 -> 4 -> 5(tail)
    // => X <- 1 <- 2 <- 3 <- 4 <- 5(tail)
    ListNode* tail = reverseAndCount(head, length);
    if (length == 1) return head;

    return helper(head, tail, k % length);
  }

  // Rverse the list and return tail of original list
  ListNode* reverseAndCount(ListNode* head, int& length) {
    length = 0;
    ListNode* prev = nullptr;
    while (head) {
      ListNode* next = head->next;
      head->next = prev;
      prev = head;
      head = next;
      ++length;
    }
    return prev;
  }

  // Rotate one step
  ListNode* helper(ListNode* head, ListNode* tail, int k) {
    // Return new head
    if (!k) {
      // Reverse back the remaining part of no rotating
      // 5(head) -> (1 <- 2 <- 3 <- 4(tail)) =>
      // 5 -> 1 -> 2 -> 3 -> 4 -> X
      int tmp;
      reverseAndCount(tail, tmp);
      return head;
    }

    // E.g., 1(head) <- 2 <- 3 <- 4 <- 5(tail)
    // Link tail to head and update new head and tail to next call.
    //    i.e., 5 -> 1 <- 2 <- 3 <- 4
    //          ------              --
    ListNode* new_tail = tail->next;  // 4
    tail->next = head;
    return helper(tail, new_tail, k - 1);
  }
};
