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
  // Use dummy node to deal with edge case
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode d(0, head);
    ListNode *h = &d, *t = &d;
    // h -> ... -> t, the gap between h and t are n-1
    for (int i = 0; i < n; ++i) t = t->next;
    while (t->next != nullptr) {
      t = t->next;
      h = h->next;
    }
    // Remove pointer after `h`
    // h -> (x) -> ... -> end
    h->next = h->next->next;
    return d.next;
  }

  // The memory of removed node should be delete (skip here)
  ListNode* removeNthFromEnd1(ListNode* head, int n) {
    ListNode *h = head, *t = head;
    // h -> ... -> t, the gap between h and t are n-1
    for (int i = 0; i < n; ++i) t = t->next;
    // Case 1: remove head, do nothing and return next
    // Include the case with only one number
    if (t == nullptr) return head->next;
    // Case 2: not head (include tail)
    // Remove pointer after `h`
    else {
      while (t->next != nullptr) {
        h = h->next;
        t = t->next;
      }
      h->next = h->next->next;
      return head;
    }
  }
};
