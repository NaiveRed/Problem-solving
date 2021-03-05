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

class Solution {
 public:
  // Method 1: iterative
  ListNode* reverseList(ListNode* head) {
    ListNode *curr = head, *prev = nullptr;
    while (curr != nullptr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  // Method 2: recursive
  ListNode* reverseList2(ListNode* head) {
    // head==nullptr: edge case for empty list
    if (head == nullptr || head->next == nullptr)  // Final node
      return head;
    // Recursively, the node after `head->next` had been reversed
    ListNode* tail = reverseList2(head->next);
    // Reverse current node and next
    // a -> b becomes a <- b
    head->next->next = head;
    head->next = nullptr;  // Only for the original head
    return tail;
  }
};
