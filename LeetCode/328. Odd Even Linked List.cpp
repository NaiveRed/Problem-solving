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
  ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;
    ListNode* odd = head;
    ListNode *even_head = head->next, *even = head->next;
    // Case 1:  `even` is null when the length is odd
    // Case 2:  `even->next` is null when the length is even
    while (even && even->next) {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }
    odd->next = even_head;
    return head;
  }
};
