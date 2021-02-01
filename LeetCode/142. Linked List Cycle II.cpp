#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *t = head, *h = head;
    bool is_cycle = false;

    // Find the cycle
    while (h && h->next) {
      h = h->next->next;
      t = t->next;
      if (h == t) {
        is_cycle = true;
        break;
      }
    }

    if (is_cycle) {
      h = head;
      while (h != t) {
        h = h->next;
        t = t->next;
      }
      return h;
    }

    return nullptr;
  }
};
