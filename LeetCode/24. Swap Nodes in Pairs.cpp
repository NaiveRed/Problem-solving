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

// Method 1: iteratively
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode dummy_head(0, head), *prev = &dummy_head, *curr = head;
    while (curr && curr->next) {
      // Swap
      ListNode* next = curr->next;
      prev->next = next;
      curr->next = next->next;
      next->next = curr;
      // Advance
      prev = curr;
      curr = curr->next;
    }
    return dummy_head.next;
  }
};

// Method 2: recursively
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    // The nodes after head have been swap
    // and return the new head.
    if (!head || !head->next) return head;

    ListNode* second = head->next;  // Will become the first node.

    // The nodes after second->next (include) have been swap.
    // head->next point to the new head.
    head->next = swapPairs(second->next);
    second->next = head;
    return second;
  }
};
