#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy_head(-1, head), *node = &dummy_head;
    while (node->next) {
      ListNode *next_node = node->next;
      if (next_node->val == val) {
        node->next = next_node->next;
        delete next_node;
      } else
        node = next_node;
    }
    return dummy_head.next;
  }
};
