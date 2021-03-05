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
    //    the new tail will be (len-(k%len))th node which is 4 (6-(4%6)).
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
