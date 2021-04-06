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

// Method 1: recursive
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1)
      return l2;
    else if (!l2)
      return l1;
    if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
    return nullptr;
  }
};

// Method 2: iterative
class Solution1 {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr)
      return l2;
    else if (l2 == nullptr)
      return l1;

    ListNode dummy, *curr = &dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val > l2->val) {
        curr->next = l2;
        l2 = l2->next;
      } else {
        curr->next = l1;
        l1 = l1->next;
      }
      curr = curr->next;
    }
    curr->next = l1 != nullptr ? l1 : l2;
    return dummy.next;
  }
};
