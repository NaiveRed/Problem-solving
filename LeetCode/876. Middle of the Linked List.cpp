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

//     s   f
// 1 2 3 4
// 1 2 3 4 5
//     s   f
class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    ListNode *fast = head, *slow = head;
    // Case 1: fast is null, number of nodes is even: slow` is second middle.
    // Case 2: fast->next is null, number of nodes is odd: `slow` is middle.
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};
