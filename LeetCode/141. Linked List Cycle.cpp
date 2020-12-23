#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  // Method 1: Tortoise and Hare algorithm
  bool hasCycle(ListNode* head) {
    ListNode *h = head, *t = head;
    while (h != nullptr && h->next != nullptr) {
      h = h->next->next;
      t = t->next;
      if (h == t) return true;
    }
    return false;
  }

  // Method 2: use set, need extra space
  bool hasCycle2(ListNode* head) {
    unordered_set<ListNode*> S;
    while (head != nullptr) {
      if (S.count(head)) return true;
      S.insert(head);
      head = head->next;
    }
    return false;
  }
};
