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

// All three methods have the same time complexity.
class Solution {
 public:
  // 20 ms
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode result_head(0), *result = &result_head;
    int carry = 0;
    while ((l1 && l2) || carry) {
      int n = 0;  // l1->val + l2->val + carry
      if (l1) {
        n += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        n += l2->val;
        l2 = l2->next;
      }
      n += carry;
      carry = n / 10;
      ListNode* node = new ListNode(n % 10);
      result = result->next = node;
    }

    // Concate remaining digits.
    if (l1)
      result->next = l1;
    else if (l2)
      result->next = l2;
    return result_head.next;
  }

  // 24 ms
  ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
    ListNode result_head(0), *result = &result_head;
    int carry = 0;
    while (l1 || l2 || carry) {
      int n = 0;
      if (l1) {
        n += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        n += l2->val;
        l2 = l2->next;
      }
      n += carry;
      carry = n / 10;
      ListNode* node = new ListNode(n % 10);
      result = result->next = node;
    }
    return result_head.next;
  }

  // 40 ms, but less memory
  ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    // Use l1 to be result.
    ListNode *head = l1, *prev_l1 = nullptr;
    int carry = 0;
    while ((l1 && l2) || carry) {
      int n = 0;
      if (l1) {
        n += l1->val;
        prev_l1 = l1;
        l1 = l1->next;
      }
      if (l2) {
        n += l2->val;
        l2 = l2->next;
      }
      n += carry;
      carry = n / 10;
      prev_l1->val = n % 10;
      // When l1 need a new node for carry bit.
      if (!l1 && carry) prev_l1->next = l1 = new ListNode(0);
    }

    // Concate remaining digits after the final digit of l1.
    if (l2) prev_l1->next = l2;
    return head;
  }
};
