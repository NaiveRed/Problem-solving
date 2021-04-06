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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* node = head;
    while (node) {
      ListNode* next_node = node->next;
      if (next_node && node->val == next_node->val) {
        node->next = next_node->next;
        delete next_node;
      } else
        node = node->next;
    }
    return head;
  }
};
